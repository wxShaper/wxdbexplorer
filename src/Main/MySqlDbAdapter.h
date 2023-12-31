#ifndef MYSQLDBADAPTER_H
#define MYSQLDBADAPTER_H

#ifdef DBL_USE_MYSQL
#include <wx/dblayer/include/MysqlDatabaseLayer.h>
#endif

#include <wx/dblayer/include/DatabaseLayer.h>
#include <wx/dynarray.h>
#include "../Interfaces/IDbAdapter.h" // Base class: IDbAdapter
#include "../Interfaces/IDbType.h"
#include "MySqlType.h"

class MySqlDbAdapter : public IDbAdapter {

	public:
		MySqlDbAdapter();
		MySqlDbAdapter(const wxString& serverName, const wxString& userName, const wxString& password);
		~MySqlDbAdapter();

		virtual bool GetColumns(Table* pTab);
		virtual void GetDatabases(DbConnection* dbCon);
		virtual void GetTables(Database* db, bool includeViews);
		virtual void GetViews(Database* db);
	
		virtual IDbAdapter* Clone();

		virtual bool CanConnect();
		virtual bool IsConnected();
		virtual void CloseConnection();
		virtual DatabaseLayer* GetDatabaseLayer(const wxString& dbName);

		virtual wxString GetUseDb(const wxString& dbName);
		virtual wxString GetDefaultSelect(const wxString& dbName, const wxString& tableName);
		virtual wxString GetDefaultSelect(const wxString& cols, const wxString& dbName, const wxString& tableName);
		virtual wxString GetCreateTableSql(Table* tab, bool dropTable);
		virtual wxString GetCreateViewSql(View* view, bool dropView);
		virtual wxString GetAlterTableConstraintSql(Table* tab);
		virtual wxString GetCreateDatabaseSql(const wxString& dbName);
		virtual wxString GetDropTableSql(Table* pTab);
		virtual wxString GetDropDatabaseSql(Database* pDb);
		virtual IDbType* GetDbTypeByName(const wxString& typeName);

		virtual wxArrayString* GetDbTypes();


		virtual IDbType* GetDbTypeByUniversalName(IDbType::UNIVERSAL_TYPE type);
		virtual void ConvertTable(Table* pTab);
		virtual IDbType* ConvertType(IDbType* pType);


	protected:

		IDbType* parseTypeString(const wxString& typeString);

		wxString m_serverName;
		wxString m_userName;
		wxString m_password;

		DatabaseLayer* m_pDbLayer;
};

#endif // MYSQLDBADAPTER_H
