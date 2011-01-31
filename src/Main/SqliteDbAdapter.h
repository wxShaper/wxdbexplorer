#ifndef SQLITEDBADAPTER_H
#define SQLITEDBADAPTER_H

#include <wx/wx.h>
#include "../Interfaces/IDbAdapter.h"
#include "../DbEngine/table.h"
#include "../DbEngine/database.h"
#include "../DbEngine/databasecol.h"
#include <wx/dblayer/SqliteDatabaseLayer.h>
#include <wx/dblayer/DatabaseLayer.h>
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

	virtual wxString GetDefaultSelect(const wxString& dbName, const wxString& tableName);
	virtual wxString GetCreateTableSql(Table* tab, bool dropTable);

protected:
	wxString m_sFileName;
};
#endif // SQLITEDBADAPTER_H
