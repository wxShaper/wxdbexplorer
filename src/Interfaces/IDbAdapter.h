#ifndef IDBADAPTER_H
#define IDBADAPTER_H
#include <wx/wx.h>
#include <wx/dynarray.h>
#include <wx/dblayer/DatabaseLayer.h>
#include "IDbType.h"
//#include "columncol.h"
//#include "tablecol.h"
//#include "databasecol.h"
class DbConnection;
class Database;
class Table;

class IDbAdapter {

public:
	virtual DatabaseLayer* GetDatabaseLayer() = 0;
	virtual bool IsConnected() = 0;
	
	
	/*! \brief Return true if adapter settings are set and adapter can connect to the database */
	virtual bool CanConnect() = 0;
	
	/*! \brief Function connect databases to the DbConnection */
	virtual void GetDatabases(DbConnection* dbCon) = 0;

	/*! \brief Function connect tables to the Database */
	virtual void GetTables(Database* db) = 0;

	/*! \brief Function connect columns to the Table */
	virtual bool GetColumns(Table* pTab) = 0;
	
	
	/*! \brief Return wxString with defalut SELECT for defined table and db */
	virtual wxString GetDefaultSelect(const wxString& dbName, const wxString& tableName) = 0;
	/*! \brief Return Create table sql statement */
	virtual wxString GetCreateTableSql(Table* tab, bool dropTable) = 0;
	
	/*! \brief Return Create database SQL statement. */
	virtual wxString GetCreateDatabaseSql(const wxString& dbName) = 0;
	/*! \brief Return Drop table SQL statement. */
	virtual wxString GetDropTableSql(Table* pTab) = 0;
	

	virtual void CloseConnection() = 0;
	
	/*! \brief Return IDbType by name string */
	virtual IDbType* GetDbTypeByName(const wxString& typeName) = 0;
	/*! \brief Return wxArrayString of possible db types */
	virtual wxArrayString* GetDbTypes () = 0;

};

#endif // IDBADAPTER_H
