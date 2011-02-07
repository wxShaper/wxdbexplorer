#ifndef ADAPTERSELECTDLG_H
#define ADAPTERSELECTDLG_H

#include "GUI.h" // Base class: _AdapterSelectDlg
#include <wx/wx.h>
#include <wx/aui/aui.h>
#include "../Main/MySqlDbAdapter.h"
#include "../Main/SqliteDbAdapter.h"

class AdapterSelectDlg : public _AdapterSelectDlg {

public:
	AdapterSelectDlg(wxWindow* parent, wxAuiNotebook* pNotebook);
	virtual ~AdapterSelectDlg();

	virtual void OnMysqlClick(wxCommandEvent& event);
	virtual void OnSqliteClick(wxCommandEvent& event);
protected:
	wxAuiNotebook* m_pNotebook;
};

#endif // ADAPTERSELECTDLG_H
