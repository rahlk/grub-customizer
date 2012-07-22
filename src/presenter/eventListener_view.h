#ifndef EVENTLISTENER_VIEW_INCLUDED
#define EVENTLISTENER_VIEW_INCLUDED

#include "gtk-client.h"
#include "../interface/eventListener_view_iface.h"
#include "eventListener_abstract.h"

class EventListenerView : public EventListener_abstract, public EventListenerView_iface {
public:
	EventListenerView(GtkClient& presenter);
	void settings_dialog_request();
	void reload_request();
	void save_request();
	void rootSelectorCompleted();
	void rootSelector_request();
	void installDialogRequest();
	void installGrub_request(std::string const& device);
	void scriptAddDlg_requested();
	void scriptAddDlg_applied();
	void scriptSelected();
	void removeProxy_requested(void* p);
	bool exitRequest();
	
	void signal_script_state_toggled(void* script);
	void signal_entry_state_toggled(void* entry);
	void signal_entry_renamed(void* entry);
	
	void ruleSwap_requested(void* a, void* b);
	void proxySwap_requested(void* a, void* b);
	
	void ruleSelected(void* rule);
	void proxySelected(void* proxy);

	//settings dialog
	void setting_row_changed(std::string const& name);
	void default_entry_predefined_toggeled();
	void default_entry_saved_toggeled();
	void default_entry_changed();
	void showMenu_toggled();
	void osProber_toggled();
	void timeout_changed();
	void kernelparams_changed();
	void generateRecovery_toggled();
	void useCustomResolution_toggled();
	void resolution_changed();
	void colorChange_requested();
	void backgroundChange_requested();
	void backgroundCopy_requested();
	void backgroundRemove_requested();
};

#endif

