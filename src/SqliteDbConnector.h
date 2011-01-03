#ifndef SQLITEDBCONNECTOR_H
#define SQLITEDBCONNECTOR_H

#include "IDbConnector.h" // Base class: IDbConnector
#include <wx/dblayer/SqliteDatabaseLayer.h>
#include <wx/dblayer/DatabaseLayer.h>


class SqliteDbConnector : public IDbConnector {

public:
	SqliteDbConnector(SqliteDatabaseLayer* dbLayer);
	virtual ~SqliteDbConnector();

public:
	virtual void CloseConnection();
	virtual DatabaseLayer* GetDatabaseLayer();
	virtual wxArrayString GetDatabases();
	virtual wxArrayString GetSP(wxString& dbName);
	virtual wxArrayString GetTablses(wxString& dbName);
	virtual wxArrayString GetViews(wxString& dbName);
	virtual bool IsConnected();


	virtual DatabaseResultSet* GetTableInfo(wxString& dbName, wxString& tableName);


protected:
	SqliteDatabaseLayer* m_pDbLayer;

};

#endif // SQLITEDBCONNECTOR_H
