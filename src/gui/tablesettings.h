#ifndef TABLESETTINGS_H
#define TABLESETTINGS_H

#include "GUI.h" // Base class: _TableSettings
#include "../table.h"
#include "../column.h"
#include "../IDbType.h"
#include "../IDbAdapter.h"

class TableSettings : public _TableSettings {

public:
	TableSettings( wxWindow* parent,IDbAdapter* pDbAdapter, wxWindowID id = wxID_ANY, const wxString& title = wxT("Table settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
	virtual ~TableSettings();
	void SetTable(Table* tab);

	virtual void OnCancelClick(wxCommandEvent& event);
	virtual void OnListBoxClick(wxCommandEvent& event);
	virtual void OnNewColumnClick(wxCommandEvent& event);
	virtual void OnOKClick(wxCommandEvent& event);
	virtual void OnSaveColumnClick(wxCommandEvent& event);
	virtual void OnTypeSelect(wxCommandEvent& event);

	virtual void OnAutoIncrementUI(wxUpdateUIEvent& event);
	virtual void OnColNameUI(wxUpdateUIEvent& event);
	virtual void OnColSizeUI(wxUpdateUIEvent& event);
	virtual void OnColTypeUI(wxUpdateUIEvent& event);
	virtual void OnNotNullUI(wxUpdateUIEvent& event);
	virtual void OnPrimaryKeyUI(wxUpdateUIEvent& event);
	virtual void OnUniqueUI(wxUpdateUIEvent& event);

protected:
	Table* m_pTable;
	Column* m_pEditedColumn;
	IDbAdapter* m_pDbAdapter;

	void UpdateView();
};

#endif // TABLESETTINGS_H
