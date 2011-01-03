#ifndef MYSQLDBCONNECTOR_H
#define MYSQLDBCONNECTOR_H

#include "IDbConnector.h" // Base class: IDbConnector
#include <wx/dblayer/MysqlDatabaseLayer.h>
#include <wx/dblayer/DatabaseLayer.h>

class MySqlDbConnector : public IDbConnector {

public:
	MySqlDbConnector( MysqlDatabaseLayer* dbLayer);
	virtual ~MySqlDbConnector();

	virtual void CloseConnection();
	virtual DatabaseLayer* GetDatabaseLayer();
	virtual wxArrayString GetDatabases();
	virtual wxArrayString GetTablses(wxString& dbName);
	virtual wxArrayString GetViews(wxString& dbName);
	virtual bool IsConnected();

	virtual DatabaseResultSet* GetTableInfo(wxString& dbName, wxString& tableName);

	virtual wxArrayString GetSP(wxString& dbName);

protected:
	MysqlDatabaseLayer* m_pDbLayer;

};

#endif // MYSQLDBCONNECTOR_H
