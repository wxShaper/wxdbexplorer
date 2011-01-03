#ifndef SQLCOMMANDPANEL_H
#define SQLCOMMANDPANEL_H

#include <wx/wx.h>
#include <wx/dblayer/DatabaseLayerException.h>
#include "GUI.h" // Base class: _SqlCommandPanel
#include <wx/dblayer/DatabaseLayer.h>
#include <wx/dblayer/MysqlDatabaseLayer.h>
#include <wx/dblayer/DatabaseErrorCodes.h>

class SQLCommandPanel : public _SqlCommandPanel
{

public:
	SQLCommandPanel(wxWindow *parent, wxString& dbName, DatabaseLayer* pDbLayer, wxString& dbTable);
	virtual ~SQLCommandPanel();
	virtual void OnExecuteClick(wxCommandEvent& event);
	virtual void OnScintilaKeyDown(wxKeyEvent& event);

	virtual void OnLoadClick(wxCommandEvent& event);
	virtual void OnSaveClick(wxCommandEvent& event);

	void ExecuteSql();

protected:
	DatabaseLayer* m_pDbLayer;
	wxString m_dbName;
	wxString m_dbTable;

};

#endif // SQLCOMMANDPANEL_H
