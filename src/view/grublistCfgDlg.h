#ifndef GRUBLIST_CFG_DLG_INCLUDED
#define GRUBLIST_CFG_DLG_INCLUDED
#include <gtkmm.h>
#include "../interface/grubconf_ui.h"
#include "../interface/eventListener_view_iface.h"
#include <iostream>
#include <libintl.h>
#include "../config.h"


class GrubConfListing : public Gtk::TreeView {
public:
	struct TreeModel : public Gtk::TreeModelColumnRecord {
		Gtk::TreeModelColumn<bool> active;
		Gtk::TreeModelColumn<Glib::ustring> name;
		Gtk::TreeModelColumn<void*> relatedRule;
		Gtk::TreeModelColumn<void*> relatedProxy;
		Gtk::TreeModelColumn<bool> is_other_entries_marker;
		Gtk::TreeModelColumn<bool> is_editable;
		TreeModel();
	};
	TreeModel treeModel;
	Glib::RefPtr<Gtk::TreeStore> refTreeStore;
	GrubConfListing();
};

class ImageMenuItemOwnKey : public Gtk::ImageMenuItem {
	public:
	ImageMenuItemOwnKey(const Gtk::StockID& id, const Gtk::AccelKey& accel_key);
};

class GrublistCfgDlg : public GrubConfUI {
	EventListenerView_iface* eventListener;
	Gtk::Window win;
	Gtk::VBox vbMainSplit;
	
	Gtk::MenuBar menu;
	Gtk::Toolbar toolbar;
	Gtk::ScrolledWindow scrEntryList;
	Gtk::Statusbar statusbar;
	
	GrubConfListing tvConfList;
	Gtk::ProgressBar progressBar;

	Glib::ustring appName, appVersion;
	std::vector<Glib::ustring> authors;

	Gtk::ToolButton tbttAdd, tbttRemove, tbttUp, tbttDown, tbttSave, tbttPreferences, tbttReload;
	Gtk::ToolItem ti_sep1;
	Gtk::VSeparator vs_sep1;
	Gtk::ToolItem ti_sep2;
	Gtk::VSeparator vs_sep2;
	Gtk::ToolItem ti_sep3;
	Gtk::VSeparator vs_sep3;
	Gtk::ToolItem ti_sep4;
	Gtk::VSeparator vs_sep4;
	
	Gtk::MenuItem miFile, miEdit, miView, miHelp, miInstallGrub;
	Gtk::ImageMenuItem miExit, miSave, miPreferences, miAbout, miStartRootSelector;
	ImageMenuItemOwnKey miReload, miAdd, miRemove, miUp, miDown;
	Gtk::Menu subFile, subEdit, subView, subHelp;
	Gtk::AboutDialog dlgAbout;
	
	bool lock_state;

	Gtk::TreeModel::iterator getIterByScriptPtr(void* scriptPtr) const;
	Gtk::TreeModel::iterator getIterByEntryPtr(void* entryPtr) const;
public:
	GrublistCfgDlg();
	void setEventListener(EventListenerView_iface& eventListener);
	void run();
	void close();
	bool requestForRootSelection();
	bool requestForBurgMode();
	
	void setIsBurgMode(bool isBurgMode);
	
	void update_move_buttons();
	void update_remove_button();
	void saveConfig();
	void setLockState(int state);
	void updateButtonsState();
	
	void setProgress(double progress);
	void progress_pulse();
	void hideProgressBar();
	void setStatusText(Glib::ustring const& new_status_text);
	void appendScript(Glib::ustring const& name, bool is_active, void* proxyPtr);
	void appendEntry(Glib::ustring const& name, bool is_active, void* entryPtr, bool editable);
	void showProxyNotFoundMessage();
	
	void setProxyName(void* proxy, Glib::ustring const& name, bool isModified);
	
	void swapProxies(void* a, void* b);
	void swapRules(void* a, void* b);
	
	void setDefaultTitleStatusText(Glib::ustring const& str);
	
	void removeProxy(void* p);
	
	int showExitConfirmDialog(int type);
	void showErrorMessage(Glib::ustring const& msg);
	void clear();
	
	Glib::ustring getRuleName(void* rule);
	void setRuleName(void* rule, Glib::ustring const& newName);
	bool getRuleState(void* rule);
	void setRuleState(void* rule, bool newState);
	bool getProxyState(void* proxy);

private:
	//event handlers
	void signal_show_root_selector();
	void signal_row_changed(const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& iter);
	void signal_move_click(int direction); //direction: -1: one position up, 1: one p. down
	void signal_add_click();
	void signal_remove_click();
	void signal_reload_click();
	void signal_show_grub_install_dialog_click();
	void signal_treeview_selection_changed();
	bool signal_delete_event(GdkEventAny* event);
	void signal_about_dlg_response(int response_id);
	void signal_quit_click();
	void signal_preference_click();
};

#endif
