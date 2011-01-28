#ifndef IDBADAPTER_H
#define IDBADAPTER_H
#include <wx/wx.h>
#include <wx/dynarray.h>
#include <wx/dblayer/DatabaseLayer.h>
#include "IDbType.h"
//#include "columncol.h"
//#include "tablecol.h"
//#include "databasecol.h"

class ColumnCol;
class DatabaseCol;
class TableCol;
class Table;
class DbConnection;

class IDbAdapter {

public:
	virtual DatabaseLayer* GetDatabaseLayer() = 0;
	virtual bool IsConnected() = 0;
	
	
	/*! \brief Return true if adapter settings are set and adapter can connect to the database */
	virtual bool CanConnect() = 0;
	
	/*! \brief Function connect databases to the DbConnection */
	virtual void GetDatabases(DbConnection* dbCon) = 0;
	/*! \brief Function return collection of databases */
	virtual DatabaseCol* GetDatabases() = 0;

	/*! \brief Function connect tables to the Database */
	virtual void GetTables(DbConnection* dbCon, Database* db) = 0;
	/*! \brief Function return collection of databases */
	virtual TableCol* GetTables(const wxString& dbName) = 0;

	/*! \brief Function connect columns to the Table */
	virtual void GetColumns(DbConnection* dbCon, Table* pTab, const wxString& tableName) = 0;
	/*! \brief Function connect columns to the Table */
	virtual bool GetColumns(Table* pTab, const wxString& tableName) = 0;
	
	
	/*! \brief Return wxString with defalut SELECT for defined table and db */
	virtual wxString GetDefaultSelect(const wxString& dbName, const wxString& tableName) = 0;
	/*! \brief Return Create table sql statement */
	virtual wxString GetCreateTableSql(Table* tab, bool dropTable) = 0;

	virtual void CloseConnection() = 0;
	
	/*! \brief Return IDbType by name string */
	virtual IDbType* GetDbTypeByName(const wxString& typeName) = 0;
	/*! \brief Return wxArrayString of possible db types */
	virtual wxArrayString* GetDbTypes () = 0;

};

#endif // IDBADAPTER_H
