#ifndef SCRIPT_ADD_DLG_INCLUDED
#define SCRIPT_ADD_DLG_INCLUDED
#include <gtkmm.h>
#include "../interface/evt_scriptAddDlg.h"
#include "../interface/scriptAddDlg.h"
#include <libintl.h>

class ScriptAddDlgGtk : public Gtk::Dialog, public ScriptAddDlg {
	Gtk::Dialog scriptAddDlg;
	Gtk::VBox vbScriptPreview;
	Gtk::HBox hbScriptSelection;
	Gtk::ComboBoxText cbScriptSelection;
	Gtk::ListViewText lvScriptPreview;
	Gtk::ScrolledWindow scrScriptPreview;
	Gtk::Label lblScriptSelection;
	Gtk::Label lblScriptPreview;
	EventListener_scriptAddDlg* eventListener;
public:
	ScriptAddDlgGtk();
	void setEventListener(EventListener_scriptAddDlg& eventListener);
	void signal_scriptAddDlg_response(int response_id);
	void clear();
	void addItem(Glib::ustring const& text);
	int getSelectedEntryIndex();
	void signal_script_selection_changed();
	void clearPreview();
	void addToPreview(Glib::ustring const& name);
	void show();
	void hide();
};

#endif
