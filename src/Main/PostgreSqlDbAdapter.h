#ifndef POSTGRESQLDBADAPTER_H
#define POSTGRESQLDBADAPTER_H

#ifdef DBL_USE_POSTGRES
#include <wx/dblayer/include/PostgresDatabaseLayer.h>
#endif

#include <wx/dblayer/include/DatabaseLayer.h>
#include <wx/dynarray.h>
#include "../Interfaces/IDbAdapter.h" // Base class: IDbAdapter
#include "../Interfaces/IDbType.h"
#include "MySqlType.h"


class PostgreSqlDbAdapter : public IDbAdapter {

public:
	PostgreSqlDbAdapter();
	PostgreSqlDbAdapter(const wxString& serverName,const wxString& defaultDb, const wxString& userName, const wxString& password);
	~PostgreSqlDbAdapter();

	virtual bool GetColumns(Table* pTab);
	virtual void GetDatabases(DbConnection* dbCon);
	virtual void GetTables(Database* db);
	virtual void GetViews(Database* db);

	virtual bool CanConnect();
	virtual bool IsConnected();
	virtual void CloseConnection();
	virtual DatabaseLayer* GetDatabaseLayer();

	virtual wxString GetUseDb(const wxString& dbName);
	virtual wxString GetDefaultSelect(const wxString& dbName, const wxString& tableName);
	virtual wxString GetCreateTableSql(Table* tab, bool dropTable);
	virtual wxString GetCreateViewSql(View* view, bool dropView);
	virtual wxString GetAlterTableConstraintSql(Table* tab);
	virtual wxString GetCreateDatabaseSql(const wxString& dbName);
	virtual wxString GetDropTableSql(Table* pTab);
	virtual wxString GetDropDatabaseSql(Database* pDb);

	virtual IDbType* GetDbTypeByName(const wxString& typeName);
	virtual wxArrayString* GetDbTypes();

protected:
	void SetDatabase(const wxString& db) { m_defaultDb = db; }

	IDbType* parseTypeString(const wxString& typeString);

	wxString m_serverName;
	wxString m_userName;
	wxString m_password;
	wxString m_defaultDb;

	DatabaseLayer* m_pDbLayer;
};

#endif // POSTGRESQLDBADAPTER_H
