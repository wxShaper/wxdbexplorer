#include "database.h"

XS_IMPLEMENT_CLONABLE_CLASS(Database,xsSerializable);

Database::Database()
{
	m_name = wxT("");
	m_pDbConnection = NULL;
}

Database::Database(const Database& obj):xsSerializable(obj)
{
		m_name = obj.m_name;
}
Database::Database(IDbAdapter* dbAdapter,const wxString& dbName)
{
	this->m_name = dbName;
	this->tables = dbAdapter->GetTables(dbName);
}
Database::Database(DbConnection* pDbConnection, const wxString& dbName)
{
	this->m_pDbConnection = pDbConnection;
	this->m_name = dbName;
	if (IDbAdapter* dbAdapt = pDbConnection->GetDbAdapter()){
		dbAdapt->GetTables(m_pDbConnection, this);	
		}
}
Database::~Database()
{
	delete this->tables;
}





