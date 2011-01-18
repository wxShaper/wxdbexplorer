#ifndef SQLITEDBADAPTER_H
#define SQLITEDBADAPTER_H

#include <wx/wx.h>
#include "../Interfaces/IDbAdapter.h"
#include "../DbEngine/table.h"
#include "../DbEngine/database.h"
#include "../DbEngine/databasecol.h"
#include <wx/dblayer/SqliteDatabaseLayer.h>
#include <wx/dblayer/DatabaseLayer.h>


class SQLiteDbAdapter : public IDbAdapter{
	public:
		SQLiteDbAdapter(const wxString& fileName) ;
		~SQLiteDbAdapter(); 
		virtual void CloseConnection(); 
		virtual DatabaseLayer* GetDatabaseLayer() ;
		virtual DatabaseCol* GetDatabases();
	
	
		virtual IDbType* GetDbTypeByName(const wxString& typeName);
		virtual wxArrayString* GetDbTypes();
		virtual  TableCol* GetTables(const wxString& dbName);
	
		virtual bool IsConnected();
		virtual wxString GetDefaultSelect(const wxString& dbName, const wxString& tableName);	
		
protected:
	wxString m_sFileName;
};
#endif // SQLITEDBADAPTER_H