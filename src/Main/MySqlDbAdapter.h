#ifndef MYSQLDBADAPTER_H
#define MYSQLDBADAPTER_H
#include <wx/dblayer/MysqlDatabaseLayer.h>
#include <wx/dblayer/DatabaseLayer.h>
#include <wx/dynarray.h>
#include "../Interfaces/IDbAdapter.h" // Base class: IDbAdapter
#include "../Interfaces/IDbType.h"
#include "../DbEngine/databasecol.h"
#include "../DbEngine/database.h"
#include "MySqlType.h"


class MySqlDbAdapter : public IDbAdapter {

public:
	MySqlDbAdapter(const wxString& serverName, const wxString& userName, const wxString& password);
	~MySqlDbAdapter();


	virtual DatabaseCol* GetDatabases();
	virtual TableCol* GetTables(const wxString& dbName);
	//virtual ColumnCol* GetColumns(const wxString& tableName);
	virtual bool GetColumns(Table* pTab, const wxString& tableName) ;
	
	virtual bool IsConnected();
	virtual void CloseConnection();
	virtual DatabaseLayer* GetDatabaseLayer();


	virtual wxString GetDefaultSelect(const wxString& dbName, const wxString& tableName);
	static wxString GetCreateTableSql(Table* tab);

	virtual IDbType* GetDbTypeByName(const wxString& typeName);
	virtual wxArrayString* GetDbTypes();

protected:

	IDbType* parseTypeString(const wxString& typeString);

	wxString m_serverName;
	wxString m_userName;
	wxString m_password;
	MysqlDatabaseLayer* m_pDbLayer;
};

#endif // MYSQLDBADAPTER_H