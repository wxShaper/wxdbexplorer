#ifndef ADAPTERSELECTDLG_H
#define ADAPTERSELECTDLG_H

#include "GUI.h" // Base class: _AdapterSelectDlg
#include <wx/wx.h>
#include <wx/aui/aui.h>

#ifdef DBL_USE_MYSQL
#include "../Main/MySqlDbAdapter.h"
#endif

#ifdef DBL_USE_SQLITE
#include "../Main/SqliteDbAdapter.h"
#endif

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
