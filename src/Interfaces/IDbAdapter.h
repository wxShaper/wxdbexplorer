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

class IDbAdapter {

public:
	virtual DatabaseLayer* GetDatabaseLayer() = 0;
	virtual bool IsConnected() = 0;
	virtual bool CanConnect() = 0;

	virtual bool GetColumns(Table* pTab, const wxString& tableName) = 0;
	virtual TableCol* GetTables(const wxString& dbName) = 0;
	virtual DatabaseCol* GetDatabases() = 0;

	virtual wxString GetDefaultSelect(const wxString& dbName, const wxString& tableName) = 0;
	virtual wxString GetCreateTableSql(Table* tab, bool dropTable) = 0;

	virtual void CloseConnection() = 0;
	
	virtual IDbType* GetDbTypeByName(const wxString& typeName) = 0;
	virtual wxArrayString* GetDbTypes () = 0;

};

#endif // IDBADAPTER_H
