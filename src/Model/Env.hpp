/*
 * Copyright (C) 2010-2011 Daniel Richter <danielrichter2007@web.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef GRUBENV_INCLUDED
#define GRUBENV_INCLUDED

#include <string>
#include <cstdio>
#include <cstdlib>
#include <dirent.h>
#include <map>
#include <sys/stat.h>


namespace Gc { namespace Model { class Env :
	public Gc::Model::Logger::Trait::LoggerAware
{
	public: enum class Mode {
		GRUB,
		BURG
	};

	// application status flags:
	public: bool quit_requested;
	public: int activeThreadCount;
	public: bool modificationsUnsaved;
	public: std::string rootDeviceName;
	public: std::string cfg_dir, cfg_dir_noprefix, mkconfig_cmd, mkfont_cmd, cfg_dir_prefix, update_cmd, install_cmd, output_config_file, output_config_dir, output_config_dir_noprefix, settings_file, devicemap_file, mkdevicemap_cmd, cmd_prefix;
	public: bool burgMode;
	public: bool useDirectBackgroundProps; // Whether background settings should be set directly or by creating a desktop-base script

	public: Env() :
		burgMode(false),
		useDirectBackgroundProps(false),
		modificationsUnsaved(false),
		quit_requested(false),
		activeThreadCount(0)
	{}

	public: bool init(Gc::Model::Env::Mode mode, std::string const& dir_prefix)
	{
		useDirectBackgroundProps = false;
		this->cmd_prefix = dir_prefix != "" ? "chroot '"+dir_prefix+"' " : "";
		this->cfg_dir_prefix = dir_prefix;
		std::string output_config_file_noprefix;
		switch (mode){
		case Mode::BURG: {
			this->burgMode = true;
			FILE* burg_cfg = fopen((dir_prefix + "/etc/grub-customizer/burg.cfg").c_str(), "r");
			if (burg_cfg) { // try to use the settings file ...
				this->log("using custom BURG configuration", Gc::Model::Logger::GenericLogger::INFO);
				this->loadFromFile(burg_cfg, dir_prefix);
				fclose(burg_cfg);
			} else { // otherwise use the built-in config
				this->mkconfig_cmd = "burg-mkconfig";
				this->install_cmd = "burg-install";
				this->mkfont_cmd = "burg-mkfont";
				this->mkdevicemap_cmd = "burg-mkdevicemap --device-map=/dev/stdout";
				this->cfg_dir = dir_prefix+"/etc/burg.d";
				this->cfg_dir_noprefix = "/etc/burg.d";
				this->output_config_dir = dir_prefix+"/boot/burg";
				this->output_config_dir_noprefix = "/boot/burg";
				this->output_config_file = dir_prefix+"/boot/burg/burg.cfg";
				this->settings_file = dir_prefix+"/etc/default/burg";
				this->devicemap_file = dir_prefix+"/boot/burg/device.map";
			}
			} break;
		case Mode::GRUB: {
			this->burgMode = false;
			FILE* grub_cfg = fopen((dir_prefix + "/etc/grub-customizer/grub.cfg").c_str(), "r");
			if (grub_cfg) { // try to use the settings file ...
				this->log("using custom Grub2 configuration", Gc::Model::Logger::GenericLogger::INFO);
				this->loadFromFile(grub_cfg, dir_prefix);
				fclose(grub_cfg);
			} else { // otherwise use the built-in config
				this->mkconfig_cmd = "grub-mkconfig";
				this->install_cmd = "grub-install";
				this->mkfont_cmd = "grub-mkfont";
				this->mkdevicemap_cmd = "grub-mkdevicemap --device-map=/dev/stdout";
				this->cfg_dir = dir_prefix+"/etc/grub.d";
				this->cfg_dir_noprefix = "/etc/grub.d";
				this->output_config_dir = dir_prefix+"/boot/grub";
				this->output_config_dir_noprefix = "/boot/grub";
				this->output_config_file = dir_prefix+"/boot/grub/grub.cfg";
				this->settings_file = dir_prefix+"/etc/default/grub";
				this->devicemap_file = dir_prefix+"/boot/grub/device.map";
			}
			} break;
		}
		
		this->update_cmd = this->mkconfig_cmd + " -o \"" + this->output_config_file.substr(dir_prefix.size()) + "\"";
		this->log("update-CMD: " + this->update_cmd, Gc::Model::Logger::GenericLogger::INFO);
	
		bool is_valid = check_cmd(mkconfig_cmd, cmd_prefix) && check_cmd(update_cmd, cmd_prefix) && check_cmd(install_cmd, cmd_prefix) && check_dir(cfg_dir);
		
		this->mkconfig_cmd = cmd_prefix+this->mkconfig_cmd;
		this->update_cmd = cmd_prefix+this->update_cmd;
		this->install_cmd = cmd_prefix+this->install_cmd;
		this->mkfont_cmd = cmd_prefix+this->mkfont_cmd;
		this->mkdevicemap_cmd = cmd_prefix+this->mkdevicemap_cmd;
		
		return is_valid;
	}

	public: void loadFromFile(FILE* cfg_file, std::string const& dir_prefix)
	{
		Gc::Model::SettingsStore ds(cfg_file);
		this->mkconfig_cmd = ds.getValue("MKCONFIG_CMD");
		this->install_cmd = ds.getValue("INSTALL_CMD");
		this->mkfont_cmd = ds.getValue("MKFONT_CMD");
		this->mkdevicemap_cmd = ds.getValue("MKDEVICEMAP_CMD");
		this->cfg_dir = dir_prefix + ds.getValue("CFG_DIR");
		this->cfg_dir_noprefix = ds.getValue("CFG_DIR");
		this->output_config_dir = dir_prefix + ds.getValue("OUTPUT_DIR");
		this->output_config_dir_noprefix = ds.getValue("OUTPUT_DIR");
		this->output_config_file = dir_prefix + ds.getValue("OUTPUT_FILE");
		this->settings_file = dir_prefix + ds.getValue("SETTINGS_FILE");
		this->devicemap_file = dir_prefix + ds.getValue("DEVICEMAP_FILE");
	}

	public: void save()
	{
		FILE* cfg_file = NULL;
		DIR* dir = opendir((cfg_dir_prefix + "/etc/grub-customizer").c_str());
		if (dir) {
			closedir(dir);
		} else {
			int res = mkdir((cfg_dir_prefix + "/etc/grub-customizer").c_str(), 0755);
			if (res != 0) {
				throw Gc::Common::Exception::FileSaveException("cannot save the config file (directory creation)", __FILE__, __LINE__);
			}
		}
		if (this->burgMode) {
			cfg_file = fopen((cfg_dir_prefix + "/etc/grub-customizer/burg.cfg").c_str(), "w");
		} else {
			cfg_file = fopen((cfg_dir_prefix + "/etc/grub-customizer/grub.cfg").c_str(), "w");
		}
		if (!cfg_file) {
			throw Gc::Common::Exception::FileSaveException("cannot save the config file (file creation)", __FILE__, __LINE__);
		}
		Gc::Model::SettingsStore ds;
		std::map<std::string, std::string> props = this->getProperties();
		for (std::map<std::string, std::string>::iterator iter = props.begin(); iter != props.end(); iter++) {
			ds.setValue(iter->first, iter->second);
		}
		ds.save(cfg_file);
		fclose(cfg_file);
	}

	public: void saveViewOptions(std::map<Gc::Common::Type::ViewOption, bool> const& options)
	{
		FILE* cfg_file = NULL;
		DIR* dir = opendir((cfg_dir_prefix + "/etc/grub-customizer").c_str());
		if (dir) {
			closedir(dir);
		} else {
			int res = mkdir((cfg_dir_prefix + "/etc/grub-customizer").c_str(), 0755);
			if (res != 0) {
				throw Gc::Common::Exception::FileSaveException("cannot save the view config file (directory creation)", __FILE__, __LINE__);
			}
		}
		cfg_file = fopen((cfg_dir_prefix + "/etc/grub-customizer/viewOptions.cfg").c_str(), "w");
		if (!cfg_file) {
			throw Gc::Common::Exception::FileSaveException("cannot save the view config file (file creation)", __FILE__, __LINE__);
		}
		Gc::Model::SettingsStore ds;
		for (std::map<Gc::Common::Type::ViewOption, bool>::const_iterator iter = options.begin(); iter != options.end(); iter++) {
			std::string optionText = "";
			switch (iter->first) {
				case Gc::Common::Type::ViewOption::SHOW_DETAILS: optionText = "SHOW_DETAILS"; break;
				case Gc::Common::Type::ViewOption::SHOW_HIDDEN_ENTRIES: optionText = "SHOW_HIDDEN_ENTRIES"; break;
				case Gc::Common::Type::ViewOption::GROUP_BY_SCRIPT: optionText = "GROUP_BY_SCRIPT"; break;
				case Gc::Common::Type::ViewOption::SHOW_PLACEHOLDERS: optionText = "SHOW_PLACEHOLDERS"; break;
				default: throw Gc::Common::Exception::LogicException("option mapping failed");
			}
			ds.setValue(optionText, iter->second ? "true" : "false");
		}
		ds.save(cfg_file);
		fclose(cfg_file);
	}

	public: std::map<Gc::Common::Type::ViewOption, bool> loadViewOptions()
	{
		FILE* file = fopen((cfg_dir_prefix + "/etc/grub-customizer/viewOptions.cfg").c_str(), "r");
		if (file == NULL) {
			throw Gc::Common::Exception::FileReadException("viewOptions not found");
		}
		Gc::Model::SettingsStore ds(file);
		fclose(file);
		std::map<Gc::Common::Type::ViewOption, bool> result;
		if (ds.getValue("SHOW_DETAILS") != "") {
			result[Gc::Common::Type::ViewOption::SHOW_DETAILS] = ds.getValue("SHOW_DETAILS") == "true";
		} else {
			result[Gc::Common::Type::ViewOption::SHOW_DETAILS] = true;
		}
		if (ds.getValue("SHOW_HIDDEN_ENTRIES") != "") {
			result[Gc::Common::Type::ViewOption::SHOW_HIDDEN_ENTRIES] = ds.getValue("SHOW_HIDDEN_ENTRIES") == "true";
		} else {
			result[Gc::Common::Type::ViewOption::SHOW_HIDDEN_ENTRIES] = false;
		}
		if (ds.getValue("GROUP_BY_SCRIPT") != "") {
			result[Gc::Common::Type::ViewOption::GROUP_BY_SCRIPT] = ds.getValue("GROUP_BY_SCRIPT") == "true";
		} else {
			result[Gc::Common::Type::ViewOption::GROUP_BY_SCRIPT] = false;
		}
		if (ds.getValue("SHOW_PLACEHOLDERS") != "") {
			result[Gc::Common::Type::ViewOption::SHOW_PLACEHOLDERS] = ds.getValue("SHOW_PLACEHOLDERS") == "true";
		} else {
			result[Gc::Common::Type::ViewOption::SHOW_PLACEHOLDERS] = false;
		}
		return result;
	}

	public: std::map<std::string, std::string> getProperties()
	{
		std::map<std::string, std::string> result;
		result["MKCONFIG_CMD"] = this->mkconfig_cmd.substr(this->cmd_prefix.size());
		result["INSTALL_CMD"] = this->install_cmd.substr(this->cmd_prefix.size());
		result["MKFONT_CMD"] = this->mkfont_cmd.substr(this->cmd_prefix.size());
		result["MKDEVICEMAP_CMD"] = this->mkdevicemap_cmd.substr(this->cmd_prefix.size());
		result["CFG_DIR"] = this->cfg_dir_noprefix;
		result["OUTPUT_DIR"] = this->output_config_dir.substr(this->cfg_dir_prefix.size());
		result["OUTPUT_FILE"] = this->output_config_file.substr(this->cfg_dir_prefix.size());
		result["SETTINGS_FILE"] = this->settings_file.substr(this->cfg_dir_prefix.size());
		result["DEVICEMAP_FILE"] = this->devicemap_file.substr(this->cfg_dir_prefix.size());
	
		return result;
	}

	public: void setProperties(std::map<std::string, std::string> const& props)
	{
		this->mkconfig_cmd = this->cmd_prefix + props.at("MKCONFIG_CMD");
		this->install_cmd = this->cmd_prefix + props.at("INSTALL_CMD");
		this->mkfont_cmd = this->cmd_prefix + props.at("MKFONT_CMD");
		this->mkdevicemap_cmd = this->cmd_prefix + props.at("MKDEVICEMAP_CMD");
		this->cfg_dir_noprefix = props.at("CFG_DIR");
		this->cfg_dir = this->cfg_dir_prefix + props.at("CFG_DIR");
		this->output_config_dir_noprefix = props.at("OUTPUT_DIR");
		this->output_config_dir = this->cfg_dir_prefix + props.at("OUTPUT_DIR");
		this->output_config_file = this->cfg_dir_prefix + props.at("OUTPUT_FILE");
		this->settings_file = this->cfg_dir_prefix + props.at("SETTINGS_FILE");
		this->devicemap_file = this->cfg_dir_prefix + props.at("DEVICEMAP_FILE");
	}

	public: std::list<std::string> getRequiredProperties()
	{
		std::list<std::string> result;
		result.push_back("MKCONFIG_CMD");
		result.push_back("INSTALL_CMD");
		result.push_back("CFG_DIR");
		return result;
	}

	public: std::list<std::string> getValidProperties()
	{
		std::list<std::string> result;
		if (this->check_cmd(this->mkconfig_cmd.substr(this->cmd_prefix.size()), this->cmd_prefix)) {
			result.push_back("MKCONFIG_CMD");
		}
		if (this->check_cmd(this->install_cmd.substr(this->cmd_prefix.size()), this->cmd_prefix)) {
			result.push_back("INSTALL_CMD");
		}
		if (this->check_cmd(this->mkfont_cmd.substr(this->cmd_prefix.size()), this->cmd_prefix)) {
			result.push_back("MKFONT_CMD");
		}
		if (this->check_cmd(this->mkdevicemap_cmd.substr(this->cmd_prefix.size()), this->cmd_prefix)) {
			result.push_back("MKDEVICEMAP_CMD");
		}
		if (this->check_dir(this->cfg_dir)) {
			result.push_back("CFG_DIR");
		}
		if (this->check_dir(this->output_config_dir)) {
			result.push_back("OUTPUT_DIR");
		}
		if (this->check_file(this->output_config_file)) {
			result.push_back("OUTPUT_FILE");
		}
		if (this->check_file(this->settings_file)) {
			result.push_back("SETTINGS_FILE");
		}
		if (this->check_file(this->devicemap_file)) {
			result.push_back("DEVICEMAP_FILE");
		}
		return result;
	}

	public: bool check_cmd(std::string const& cmd, std::string const& cmd_prefix = "") const
	{
		this->log("checking the " + this->trim_cmd(cmd) + " command… ", Gc::Model::Logger::GenericLogger::INFO);
		FILE* proc = popen((cmd_prefix + " which " + this->trim_cmd(cmd) + " 2>&1").c_str(), "r");
		std::string output;
		int c;
		while ((c = fgetc(proc)) != EOF) {
			if (c != '\n') {
				output += char(c);
			}
		}
		bool result = pclose(proc) == 0;
		if (result == true) {
			this->log("found at: " + output, Gc::Model::Logger::GenericLogger::INFO);
		} else {
			this->log("not found", Gc::Model::Logger::GenericLogger::INFO);
		}
		return result;
	}

	public: bool check_dir(std::string const& dir_str) const
	{
		DIR* dir = opendir(dir_str.c_str());
		if (dir){
			closedir(dir);
			return true;
		}
		return false;
	}

	public: bool check_file(std::string const& file_str) const
	{
		FILE* file = fopen(file_str.c_str(), "r");
		if (file){
			fclose(file);
			return true;
		}
		return false;
	}

	public: std::string trim_cmd(std::string const& cmd) const
	{
		int firstSpace = cmd.find_first_of(' ');
		if (firstSpace != -1) {
			return cmd.substr(0, firstSpace);
		} else {
			return cmd;
		}
	}

	public: std::string getRootDevice()
	{
		FILE* mtabFile = fopen("/etc/mtab", "r");
		Gc::Model::Device::MountTable mtab;
		if (mtabFile){
			mtab.loadData(mtabFile, "");
			fclose(mtabFile);
		}
		return mtab.getEntryByMountpoint(cfg_dir_prefix == "" ? "/" : cfg_dir_prefix).device;
	}

	public: std::list<Gc::Model::Env::Mode> getAvailableModes()
	{
		std::list<Mode> result;
		if (this->init(Gc::Model::Env::Mode::BURG, this->cfg_dir_prefix))
			result.push_back(Gc::Model::Env::Mode::BURG);
		if (this->init(Gc::Model::Env::Mode::GRUB, this->cfg_dir_prefix))
			result.push_back(Gc::Model::Env::Mode::GRUB);
		return result;
	}

	public: void createBackup()
	{
		std::string backupDir = this->cfg_dir + "/backup";
		DIR* dirChk = opendir(backupDir.c_str());
		if (dirChk) {
			// if backup already exists - dont't create or update. Should only contain the initial config.
			closedir(dirChk);
		} else {
			mkdir(backupDir.c_str(), 0755);
	
			std::list<std::string> ignoreList;
			ignoreList.push_back(backupDir);
	
			Gc::Common::FileSystem fileSystem;
			fileSystem.copy(this->cfg_dir, backupDir + "/etc_grub_d", true, ignoreList);
			fileSystem.copy(this->output_config_dir, backupDir + "/boot_grub", true, ignoreList);
			fileSystem.copy(this->settings_file, backupDir + "/default_grub", true, ignoreList);
	
			FILE* restoreHowto = fopen((backupDir + "/RESTORE_INSTRUCTIONS").c_str(), "w");
			fputs("How to restore this backup\n", restoreHowto);
			fputs("--------------------------\n", restoreHowto);
			fputs(" * make sure you have root permissions (`gksu nautilus` or `sudo -s` on command line) otherwise you won't be able to copy the files\n", restoreHowto);
			fputs(" * to fix an unbootable configuration, just copy:\n", restoreHowto);
			fputs(("     * '" + backupDir + "/boot_grub' to '" + this->output_config_dir + "'\n").c_str(), restoreHowto);
			fputs(" * to reset the whole configuration (if it cannot be fixed by using grub customizer), also copy these files:\n", restoreHowto);
			fputs(("     * '" + backupDir + "/etc_grub_d' to '" + this->cfg_dir + "'\n").c_str(), restoreHowto);
			fputs(("     * '" + backupDir + "/default_grub' to '" + this->settings_file + "'\n").c_str(), restoreHowto);
			fclose(restoreHowto);
		}
	}

	public: operator Gc::Common::ArrayStructure::Container()
	{
		Gc::Common::ArrayStructure::Container result;
		result["cfg_dir"] = this->cfg_dir;
		result["cfg_dir_noprefix"] = this->cfg_dir_noprefix;
		result["mkconfig_cmd"] = this->mkconfig_cmd;
		result["mkfont_cmd"] = this->mkfont_cmd;
		result["cfg_dir_prefix"] = this->cfg_dir_prefix;
		result["install_cmd"] = this->install_cmd;
		result["output_config_file"] = this->output_config_file;
		result["output_config_dir"] = this->output_config_dir;
		result["settings_file"] = this->settings_file;
		result["devicemap_file"] = this->devicemap_file;
		result["mkdevicemap_cmd"] = this->mkdevicemap_cmd;
		result["cmd_prefix"] = this->cmd_prefix;
		result["burgMode"] = this->burgMode;
		result["useDirectBackgroundProps"] = this->useDirectBackgroundProps;
		result["quit_requested"] = this->quit_requested;
		result["activeThreadCount"] = this->activeThreadCount;
		result["modificationsUnsaved"] = this->modificationsUnsaved;
		result["rootDeviceName"] = this->rootDeviceName;
		return result;
	}

};}}

#endif
