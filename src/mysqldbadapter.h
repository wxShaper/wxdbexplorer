#ifndef MYSQLDBADAPTER_H
#define MYSQLDBADAPTER_H
#include <wx/dblayer/MysqlDatabaseLayer.h>
#include <wx/dblayer/DatabaseLayer.h>
#include "IDbAdapter.h" // Base class: IDbAdapter
#include "databasecol.h"
#include "database.h"

class MySqlDbAdapter : public IDbAdapter {

public:
	MySqlDbAdapter(const wxString& serverName, const wxString& userName, const wxString& password);
	~MySqlDbAdapter();


	virtual DatabaseCol* GetDatabases();
	virtual TableCol* GetTables(const wxString& dbName);
	virtual ColumnCol* GetColumns(const wxString& tableName);

	virtual bool IsConnected();
	virtual void CloseConnection();
	virtual DatabaseLayer* GetDatabaseLayer();

	static wxString GetCreateTableSql(Table* tab);

protected:
	wxString m_serverName;
	wxString m_userName;
	wxString m_password;
	MysqlDatabaseLayer* m_pDbLayer;
};

#endif // MYSQLDBADAPTER_H
