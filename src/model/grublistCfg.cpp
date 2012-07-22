#include "grublistCfg.h"

GrublistCfg::GrublistCfg(GrubEnv& env)
 : error_proxy_not_found(false),
 progress(0), config_has_been_different_on_startup_but_unsaved(false),
 cancelThreadsRequested(false), verbose(true), env(env), eventListener(NULL),
 locked(false)
{}

void GrublistCfg::setEventListener(EventListenerModel_iface& eventListener) {
	this->eventListener = &eventListener;
}


bool GrublistCfg::umountSwitchedRootPartition(){
	if (env.cfg_dir_prefix != ""){
		bool res = umount_all(env.cfg_dir_prefix);
		if (!res)
			return false;
		env.cfg_dir_prefix = "";
		return true;
	}
	else
		return true;
}


void GrublistCfg::lock(){
	while (this->locked) usleep(1000); //wait until another thread is has unlocked this object
	this->locked = true;
}
bool GrublistCfg::lock_if_free(){
	if (this->locked)
		return false;
	else {
		this->locked = true;
		return true;
	}
}
void GrublistCfg::unlock(){
	this->locked = false;
}

bool GrublistCfg::createScriptForwarder(std::string const& scriptName) const {
	//replace: $cfg_dir/proxifiedScripts/ -> $cfg_dir/LS_
	std::string scriptNameNoPath = scriptName.substr((this->env.cfg_dir+"/proxifiedScripts/").length());
	std::string outputFilePath = this->env.cfg_dir+"/LS_"+scriptNameNoPath;
	FILE* existingScript = fopen(outputFilePath.c_str(), "r");
	if (existingScript == NULL){
		FILE* fwdScript = fopen(outputFilePath.c_str(), "w");
		if (fwdScript){
			fputs("#!/bin/sh\n", fwdScript);
			fputs(("'"+scriptName.substr(env.cfg_dir_prefix.length())+"'").c_str(), fwdScript);
			fclose(fwdScript);
			chmod(outputFilePath.c_str(), 0755);
			return true;
		}
		else
			return false;
	}
	else {
		fclose(existingScript);
		return false;
	}
}

bool GrublistCfg::removeScriptForwarder(std::string const& scriptName) const {
	std::string scriptNameNoPath = scriptName.substr((this->env.cfg_dir+"/proxifiedScripts/").length());
	std::string filePath = this->env.cfg_dir+"/LS_"+scriptNameNoPath;
	return unlink(filePath.c_str()) == 0;
}

std::string GrublistCfg::readScriptForwarder(std::string const& scriptForwarderFilePath) const {
	std::string result;
	FILE* scriptForwarderFile = fopen(scriptForwarderFilePath.c_str(), "r");
	if (scriptForwarderFile){
		int c;
		while ((c = fgetc(scriptForwarderFile)) != EOF && c != '\n'){} //skip first line
		if (c != EOF)
			while ((c = fgetc(scriptForwarderFile)) != EOF && c != '\n'){result += char(c);} //read second line (=path)
		fclose(scriptForwarderFile);
	}
	return result.substr(1, result.length()-2);
}

void GrublistCfg::load(bool keepConfig){
	if (!keepConfig){
		send_new_load_progress(0);
		{ //check the existence of cfg_dir
			DIR* cfg_dir = opendir(this->env.cfg_dir.c_str());
			if (cfg_dir)
				closedir(cfg_dir);
			else {
				if (this->eventListener){
					this->message = this->env.cfg_dir+gettext(" not found. Is grub2 installed?");
					this->eventListener->threadDied();
				}
				return; //dir doesn't exist, cancel!
			}
		}
		//load scripts
		repository.load(this->env.cfg_dir, false);
		repository.load(this->env.cfg_dir+"/proxifiedScripts", true);
		send_new_load_progress(0.05);
	
		DIR* hGrubCfgDir = opendir(this->env.cfg_dir.c_str());

		if (!hGrubCfgDir){
			if (this->eventListener){
				this->message = this->env.cfg_dir+gettext(" not found. Is grub2 installed?");
				this->eventListener->threadDied();
			}
			return; //cancel this thread
		}
	
		//load proxies
		struct dirent *entry;
		struct stat fileProperties;
		while (entry = readdir(hGrubCfgDir)){
			stat((this->env.cfg_dir+"/"+entry->d_name).c_str(), &fileProperties);
			if ((fileProperties.st_mode & S_IFMT) != S_IFDIR){ //ignore directories
				if (entry->d_name[2] == '_' && entry->d_name[0] != '0'){ //check whether it's an script (they should be named XX_scriptname)… und block header scripts (they use a leading 0)
					this->proxies.push_back(Proxy());
					this->proxies.back().fileName = this->env.cfg_dir+"/"+entry->d_name;
					this->proxies.back().index = (entry->d_name[0]-'0')*10 + (entry->d_name[1]-'0');
					this->proxies.back().permissions = fileProperties.st_mode & ~S_IFMT;
				
					FILE* proxyFile = fopen((this->env.cfg_dir+"/"+entry->d_name).c_str(), "r");
					ProxyScriptData data(proxyFile);
					fclose(proxyFile);
					if (data){
						this->proxies.back().dataSource = repository.getScriptByFilename(this->env.cfg_dir_prefix+data.scriptCmd);
						this->proxies.back().importRuleString(data.ruleString.c_str());
					}
					else {
						this->proxies.back().dataSource = repository.getScriptByFilename(this->env.cfg_dir+"/"+entry->d_name);
						this->proxies.back().importRuleString("+*"); //it's no proxy, so accept all
					}
				
				}
			}
		}
		closedir(hGrubCfgDir);
		this->proxies.sort();
	}
	else {
		repository.deleteAllEntries();
	}
	
	//create proxifiedScript links & chmod other files

	for (Repository::iterator iter = this->repository.begin(); iter != this->repository.end(); iter++){
		if (iter->isInScriptDir(env.cfg_dir)){
			//createScriptForwarder & disable proxies
			createScriptForwarder(iter->fileName);
			std::list<Proxy*> relatedProxies = proxies.getProxiesByScript(*iter);
			for (std::list<Proxy*>::iterator piter = relatedProxies.begin(); piter != relatedProxies.end(); piter++){
				int res = chmod((*piter)->fileName.c_str(), 0644);
			}
		}
		else {
			//enable scripts (unproxified), in this case, Proxy::fileName == Script::fileName
			chmod(iter->fileName.c_str(), 0755);
		}
	}
	send_new_load_progress(0.1);
	
	//run mkconfig
	std::cout << "running " << this->env.mkconfig_cmd << std::endl;
	FILE* mkconfigProc = popen(this->env.mkconfig_cmd.c_str(), "r");
	readGeneratedFile(mkconfigProc);
	
	int success = pclose(mkconfigProc);
	if (success != 0 && !cancelThreadsRequested){
		if (this->eventListener){
			this->message = env.mkconfig_cmd + gettext(" couldn't be executed successfully. You must run this as root!");
			this->eventListener->threadDied();
		}
		return; //cancel this thread
	}

	this->send_new_load_progress(0.9);

	mkconfigProc = NULL;
	
	
	//restore old configuration
	this->lock();
	for (Repository::iterator iter = this->repository.begin(); iter != this->repository.end(); iter++){
		if (iter->isInScriptDir(env.cfg_dir)){
			//removeScriptForwarder & reset proxy permissions
			bool result = removeScriptForwarder(iter->fileName);
			if (!result)
				std::cout << "remove not successful!" << std::endl;
		}
		std::list<Proxy*> relatedProxies = proxies.getProxiesByScript(*iter);
		for (std::list<Proxy*>::iterator piter = relatedProxies.begin(); piter != relatedProxies.end(); piter++){
			chmod((*piter)->fileName.c_str(), (*piter)->permissions);
		}
	}
	this->unlock();
	
	//compare config
	if (!keepConfig){
		FILE* oldConfigFile = fopen(env.output_config_file.c_str(), "r");
		if (oldConfigFile){
			GrublistCfg oldConfig(env);
			oldConfig.verbose = false;
			oldConfig.env = this->env;
			oldConfig.readGeneratedFile(oldConfigFile, true);
			config_has_been_different_on_startup_but_unsaved = !this->compare(oldConfig);
			fclose(oldConfigFile);
		}
		else
			config_has_been_different_on_startup_but_unsaved = false;
	}
	send_new_load_progress(1);
	
}


void GrublistCfg::readGeneratedFile(FILE* source, bool createScriptIfNotFound){
	GrubConfRow row;
	Script* script;
	int i = 0;
	while (!cancelThreadsRequested && (row = GrubConfRow(source))){
		if (row.text.substr(0,10) == ("### BEGIN ") && row.text.substr(row.text.length()-4,4) == " ###"){
			this->lock();
			if (script)
				this->proxies.sync_all(true, true, script);
			std::string scriptName = row.text.substr(10, row.text.length()-14);
			std::string prefix = this->env.cfg_dir_prefix;
			std::string realScriptName = prefix+scriptName;
			if (realScriptName.substr(0, (this->env.cfg_dir+"/LS_").length()) == this->env.cfg_dir+"/LS_"){
				realScriptName = prefix+readScriptForwarder(realScriptName);
			}
			script = repository.getScriptByFilename(realScriptName, createScriptIfNotFound);
			if (createScriptIfNotFound){ //for the compare-configuration
				this->proxies.push_back(Proxy(*script));
			}
			this->unlock();
			if (script){
				this->send_new_load_progress(0.1 + (0.7 / this->repository.size() * ++i));
			}
		}
		else if (script != NULL && row.text.substr(0, 10) == "menuentry ") {
			this->lock();
			script->push_back(Entry(source, row));
			this->proxies.sync_all(false, false, script);
			this->unlock();
			this->send_new_load_progress(0.1 + (0.7 / this->repository.size() * i));
		}
	}
	this->lock();
	if (script)
		this->proxies.sync_all(true, true, script);
	this->unlock();
}

void GrublistCfg::save(){
	send_new_save_progress(0);
	std::map<std::string, int> samename_counter;
	proxies.deleteAllProxyscriptFiles();  //delete all proxies to get a clean file system
	proxies.clearTrash(); //delete all files of removed proxies
	for (Repository::iterator script_iter = repository.begin(); script_iter != repository.end(); script_iter++)
		script_iter->moveToBasedir(this->env.cfg_dir);
	
	send_new_save_progress(0.1);

	int mkdir_result = mkdir((this->env.cfg_dir+"/proxifiedScripts").c_str(), 0755); //create this directory if it doesn't allready exist

	int proxyCount = 0;
	for (Repository::iterator script_iter = repository.begin(); script_iter != repository.end(); script_iter++){
		std::list<Proxy*> relatedProxies = proxies.getProxiesByScript(*script_iter);
		if (proxies.proxyRequired(*script_iter)){
			script_iter->moveFile(this->env.cfg_dir+"/proxifiedScripts/"+pscriptname_encode(script_iter->name, samename_counter[script_iter->name]++), 0755);
			for (std::list<Proxy*>::iterator proxy_iter = relatedProxies.begin(); proxy_iter != relatedProxies.end(); proxy_iter++){
				std::ostringstream nameStream;
				nameStream << (*proxy_iter)->index << "_" << script_iter->name << "_proxy";
				(*proxy_iter)->generateFile(this->env.cfg_dir+"/"+nameStream.str(), this->env.cfg_dir_prefix.length(), this->env.cfg_dir_noprefix);
				proxyCount++;
			}
		}
		else {
			if (relatedProxies.size() == 1){
				std::ostringstream nameStream;
				nameStream << relatedProxies.front()->index << "_" << script_iter->name;
				script_iter->moveFile(this->env.cfg_dir+"/"+nameStream.str(), relatedProxies.front()->permissions);
			}
			else
				std::cerr << "GrublistCfg::save: cannot move proxy… only one expected!" << std::endl;
		}	
	}
	send_new_save_progress(0.2);


	//remove "proxifiedScripts" dir, if empty
	
	{
		int proxifiedScriptCount = 0;
		struct dirent *entry;
		struct stat fileProperties;
		DIR* hScriptDir = opendir((this->env.cfg_dir+"/proxifiedScripts").c_str());
		while (entry = readdir(hScriptDir)){
			if (std::string(entry->d_name) != "." && std::string(entry->d_name) != ".."){
				proxifiedScriptCount++;
			}
		}
		closedir(hScriptDir);
		
		if (proxifiedScriptCount == 0)
			rmdir((this->env.cfg_dir+"/proxifiedScripts").c_str());
	}

	//add or remove proxy binary
	
	FILE* proxyBin = fopen((this->env.cfg_dir+"/bin/grubcfg_proxy").c_str(), "r");
	bool proxybin_exists = proxyBin != NULL;
	bool proxy_is_dummy = false;
	std::string dummyproxy_code = "#!/bin/sh\ncat\n";
	std::string proxy_code;
	
	if (proxyBin){
		std::cerr << "proxybin does already exist!" << std::endl;
		int c;
		for (int i = 0; i < dummyproxy_code.length() && (c = fgetc(proxyBin)) != EOF; i++)
			proxy_code += c;
		
		if (proxy_code == dummyproxy_code)
			proxy_is_dummy = true;
		fclose(proxyBin);
	}

	if (proxyCount != 0 && (!proxybin_exists || proxy_is_dummy)){
		//copy proxy
		int bin_mk_success = mkdir((this->env.cfg_dir+"/bin").c_str(), 0755);

		FILE* proxyBinSource = fopen((std::string(LIBDIR)+"/grubcfg-proxy").c_str(), "r");
		
		if (proxyBinSource){
			FILE* proxyBinTarget = fopen((this->env.cfg_dir+"/bin/grubcfg_proxy").c_str(), "w");
			if (proxyBinTarget){
				int c;
				while ((c = fgetc(proxyBinSource)) != EOF){
					fputc(c, proxyBinTarget);
				}
				fclose(proxyBinTarget);
				chmod((this->env.cfg_dir+"/bin/grubcfg_proxy").c_str(), 0755);
			}
			else
				std::cerr << "could not open proxy output file!" << std::endl;
			fclose(proxyBinSource);
		}
		else {
			std::cerr << "proxy could not be copied, generating dummy!" << std::endl;
			FILE* proxyBinTarget = fopen((this->env.cfg_dir+"/bin/grubcfg_proxy").c_str(), "w");
			if (proxyBinTarget){
				fputs(dummyproxy_code.c_str(), proxyBinTarget);
				error_proxy_not_found = true;
				fclose(proxyBinTarget);
				chmod((this->env.cfg_dir+"/bin/grubcfg_proxy").c_str(), 0755);
			}
			else
				std::cerr << "coundn't create proxy!" << std::endl;
		}
	}
	else if (proxyCount == 0 && proxybin_exists){
		//the following commands are only cleanup… no problem, when they fail
		unlink((this->env.cfg_dir+"/bin/grubcfg_proxy").c_str());
		rmdir((this->env.cfg_dir+"/bin").c_str());
	}


	//run update-grub
	FILE* saveProc = popen((env.update_cmd+" 2>&1").c_str(), "r");
	if (saveProc){
		int c;
		std::string row = "";
		while ((c = fgetc(saveProc)) != EOF){
			if (c == '\n'){
				send_new_save_progress(0.5); //a gui should use pulse() instead of set_fraction
				row = "";
			}
			else
				row += char(c);
			std::cerr << char(c); //print messages (for debugging purposes)
		}
		pclose(saveProc);
	}
	config_has_been_different_on_startup_but_unsaved = false;
	send_new_save_progress(1);
}

void GrublistCfg::renameRule(Rule* rule, std::string const& newName){
	rule->outputName = newName;
}

bool GrublistCfg::compare(GrublistCfg const& other) const {
	std::list<const Rule*> rlist[2];
	for (int i = 0; i < 2; i++){
		const GrublistCfg* gc = i == 0 ? this : &other;
		for (ProxyList::const_iterator piter = gc->proxies.begin(); piter != gc->proxies.end(); piter++){
			if (piter->isExecutable() && piter->dataSource){
				std::string fname = piter->dataSource->fileName.substr(other.env.cfg_dir.length()+1);
				if (i == 0 || fname[0] >= '1' && fname[0] <= '9' && fname[1] >= '0' && fname[1] <= '9' && fname[2] == '_'){
					for (std::list<Rule>::const_iterator riter = piter->rules.begin(); riter != piter->rules.end(); riter++){
						if (riter->type == Rule::NORMAL && riter->dataSource && riter->isVisible){
							rlist[i].push_back(&*riter);
						}
					}
				}
			}
		}
	}
	if (rlist[0].size() != rlist[1].size())
		return false;
	
	std::list<const Rule*>::iterator self_iter = rlist[0].begin(), other_iter = rlist[1].begin();
	while (self_iter != rlist[0].end() && other_iter != rlist[1].end()){
		if ((*self_iter)->outputName != (*other_iter)->outputName || (*self_iter)->dataSource->extension != (*other_iter)->dataSource->extension || (*self_iter)->dataSource->content != (*other_iter)->dataSource->content)
			return false;
		self_iter++;
		other_iter++;
	}
	return true;
}


void GrublistCfg::send_new_load_progress(double newProgress){
	if (this->eventListener != NULL){
		this->progress = newProgress;
		this->eventListener->entryListUpdate();
	}
	else if (this->verbose) {
		std::cerr << "Error: cannot show updated load progress - no UI connected!" << std::endl;
	}
}

void GrublistCfg::send_new_save_progress(double newProgress){
	if (this->eventListener != NULL){
		this->progress = newProgress;
		this->eventListener->saveProgressChanged();
	}
	else if (this->verbose) {
		std::cerr << "Error: cannot show updated save progress - no UI connected!" << std::endl;
	}
}

void GrublistCfg::cancelThreads(){
	cancelThreadsRequested = true;
}


std::string GrublistCfg::getMessage() const {
	return message;
}

void GrublistCfg::reset(){
	this->repository.clear();
	this->proxies.clear();
}

double GrublistCfg::getProgress() const {
	return progress;
}

//DEPRECATED… I don't know why didn't use the easier function earlier
/*void GrublistCfg::increaseProxyPos(Proxy* proxy){
	short int i = 10;
	bool proxyToMove_found = false;
	for (ProxyList::iterator iter = this->proxies.begin(); iter != this->proxies.end(); iter++){
		if (&*iter != proxy){
			iter->index = i++;
			if (proxyToMove_found){
				proxy->index = i++;
				proxyToMove_found = false;
			}
		}
		else
			proxyToMove_found = true;
	}
	this->proxies.sort();
}*/

void GrublistCfg::renumerate(){
	short int i = 10;
	for (ProxyList::iterator iter = this->proxies.begin(); iter != this->proxies.end(); iter++){
		iter->index = i++;
	}
	this->proxies.sort();
}

void GrublistCfg::swapRules(Rule* a, Rule* b){
	Rule swap_helper = *a;
	*a = *b;
	*b = swap_helper;
}

void GrublistCfg::swapProxies(Proxy* a, Proxy* b){
	int index1 = a->index;
	a->index = b->index;
	b->index = index1;
	this->proxies.sort();
}

bool GrublistCfg::cfgDirIsClean(){
	DIR* hGrubCfgDir = opendir(this->env.cfg_dir.c_str());
	if (hGrubCfgDir){
		struct dirent *entry;
		struct stat fileProperties;
		while (entry = readdir(hGrubCfgDir)){
			std::string fname = entry->d_name;
			if (fname.length() >= 4 && fname.substr(0,3) == "LS_")
				return false;
		}
		closedir(hGrubCfgDir);
	}
	return true;
}
void GrublistCfg::cleanupCfgDir(){
	std::cout << "cleaning up cfg dir!" << std::endl;
	
	DIR* hGrubCfgDir = opendir(this->env.cfg_dir.c_str());
	if (hGrubCfgDir){
		struct dirent *entry;
		struct stat fileProperties;
		std::list<std::string> lsfiles;
		std::list<std::string> proxyscripts;
		while (entry = readdir(hGrubCfgDir)){
			std::string fname = entry->d_name;
			if (fname.length() >= 4 && fname.substr(0,3) == "LS_")
				lsfiles.push_back(fname);
			if (fname.length() >= 4 && fname[0] >= '1' && fname[0] <= '9' && fname[1] >= '0' && fname[1] <= '9' && fname[2] == '_')
				proxyscripts.push_back(fname);
		}
		closedir(hGrubCfgDir);
		
		for (std::list<std::string>::iterator iter = lsfiles.begin(); iter != lsfiles.end(); iter++){
			std::cout << "deleting " << *iter << std::endl;
			unlink((this->env.cfg_dir+"/"+(*iter)).c_str());
		}
		//proxyscripts will be disabled before loading the config. While the provious mode will only be saved on the objects, every script should be made executable
		for (std::list<std::string>::iterator iter = proxyscripts.begin(); iter != proxyscripts.end(); iter++){
			std::cout << "re-activating " << *iter << std::endl;
			chmod((this->env.cfg_dir+"/"+(*iter)).c_str(), 0755);
		}
	}
}




