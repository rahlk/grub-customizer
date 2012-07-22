#ifndef EVENTLISTENER_LISTCFGDLG_INCLUDED
#define EVENTLISTENER_LISTCFGDLG_INCLUDED

/**
 * base class to be implemented by grublistconfig event listeners
 */
class EventListener_listCfgDlg {
public:
	//user wants to show the settings dialog
	virtual void settings_dialog_request()=0;
	//user wants to reload the whole configuration
	virtual void reload_request()=0;
	//user wants to save all his changes
	virtual void save_request()=0;
	//user wants to show the partition chooser
	virtual void rootSelector_request()=0;
	//user wants to show the grub install dialog
	virtual void installDialogRequest()=0;
	//user wants to show the dialog which lets him add new scripts
	virtual void scriptAddDlg_requested()=0;
	//user wants to remove one of the proxies (script instances)
	virtual void removeProxy_requested(void* p)=0;
	//user wants to show the about dialog
	virtual void aboutDialog_requested()=0;
	//user wants to quit -> application asks if it should be closed (return values: true = close, false = stay opened)
	virtual void exitRequest()=0;

	//user has activated or disabled one of the proxies (script instances)
	virtual void signal_script_state_toggled(void* script)=0;
	//user has activated or disabled one of the entries
	virtual void signal_entry_state_toggled(void* entry)=0;
	//user has renamed one of the entries
	virtual void signal_entry_renamed(void* entry)=0;

	//user wants to swap two rules
	virtual void ruleSwap_requested(void* a, void* b)=0;
	//user wants to swap two proxies
	virtual void proxySwap_requested(void* a, void* b)=0;

	//user has selected another rule
	virtual void ruleSelected(void* rule)=0;
	//user has selected another proxy
	virtual void proxySelected(void* proxy)=0;

	virtual void burgSwitcher_cancelled()=0;
	virtual void burgSwitcher_response(bool burgChosen)=0;
	virtual void partitionChooserQuestion_response(bool is_positive)=0;
};

#endif
