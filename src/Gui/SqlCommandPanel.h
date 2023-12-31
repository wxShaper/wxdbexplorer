#ifndef SQLCOMMANDPANEL_H
#define SQLCOMMANDPANEL_H

#include <wx/wx.h>
#include <wx/dblayer/include/DatabaseLayerException.h>
#include "GUI.h" // Base class: _SqlCommandPanel
#include <wx/dblayer/include/DatabaseLayer.h>

#ifdef DBL_USE_MYSQL
#include <wx/dblayer/include/MysqlDatabaseLayer.h>
#endif

#include <wx/dblayer/include/DatabaseErrorCodes.h>
#include "Interfaces/IDbAdapter.h"

#include "Ids.h"


class SQLCommandPanel : public _SqlCommandPanel{

public:
	SQLCommandPanel(wxWindow *parent,IDbAdapter* dbAdapter, const wxString& dbName,const wxString& dbTable);
	virtual ~SQLCommandPanel();
	virtual void OnExecuteClick(wxCommandEvent& event);
	virtual void OnScintilaKeyDown(wxKeyEvent& event);

	virtual void OnLoadClick(wxCommandEvent& event);
	virtual void OnSaveClick(wxCommandEvent& event);
	virtual void OnTeplatesLeftDown(wxMouseEvent& event);
	virtual void OnTemplatesBtnClick(wxCommandEvent& event);

	void OnPopupClick(wxCommandEvent &evt);
	void ExecuteSql();


protected:
	IDbAdapter* m_pDbAdapter;
	wxString m_dbName;
	wxString m_dbTable;

};

#endif // SQLCOMMANDPANEL_H
