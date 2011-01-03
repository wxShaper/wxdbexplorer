#ifndef IDBCONNECTOR_H
#define IDBCONNECTOR_H

#include <wx/wx.h>
#include <wx/dblayer/DatabaseLayer.h>

class IDbConnector {

public:
	virtual DatabaseLayer* GetDatabaseLayer() = 0;
	virtual bool IsConnected() = 0;
	
	virtual wxArrayString GetDatabases() = 0;
	virtual wxArrayString GetTablses(wxString& dbName) = 0;
	virtual wxArrayString GetViews(wxString& dbName) = 0;
	virtual wxArrayString GetSP(wxString& dbName) = 0;
	
	virtual DatabaseResultSet* GetTableInfo(wxString& dbName, wxString& tableName) = 0;
	
	virtual void CloseConnection() = 0;
};

#endif // IDBCONNECTOR_H
