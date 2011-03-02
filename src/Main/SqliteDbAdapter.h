#ifndef SQLITEDBADAPTER_H
#define SQLITEDBADAPTER_H

#include <wx/wx.h>
#include "../Interfaces/IDbAdapter.h"
#include "../DbEngine/table.h"
#include "../DbEngine/database.h"
#include "../DbEngine/databasecol.h"

#ifdef DBL_USE_SQLITE
#include <wx/dblayer/include/SqliteDatabaseLayer.h>
#endif

#include <wx/dblayer/include/DatabaseLayer.h>
#include "SqliteType.h"

class SQLiteDbAdapter : public IDbAdapter {
public:
	SQLiteDbAdapter();
	SQLiteDbAdapter(const wxString& fileName) ;
	~SQLiteDbAdapter();
	virtual void CloseConnection();
	virtual DatabaseLayer* GetDatabaseLayer() ;


	virtual void GetDatabases(DbConnection* dbCon);
	virtual void GetTables(Database* db);
	virtual bool GetColumns(Table* pTab);



	virtual IDbType* GetDbTypeByName(const wxString& typeName);
	virtual wxArrayString* GetDbTypes();


	virtual bool CanConnect();
	virtual bool IsConnected();

	virtual wxString GetUseDb(const wxString& dbName);

	virtual wxString GetDefaultSelect(const wxString& dbName, const wxString& tableName);
	virtual wxString GetCreateTableSql(Table* tab, bool dropTable);
	virtual wxString GetAlterTableConstraintSql(Table* tab);
	virtual wxString GetCreateDatabaseSql(const wxString& dbName);
	virtual wxString GetDropTableSql(Table* pTab);
	virtual wxString GetDropDatabaseSql(Database* pDb);


protected:
	wxString m_sFileName;
};
#endif // SQLITEDBADAPTER_H
