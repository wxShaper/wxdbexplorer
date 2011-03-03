#include "database.h"
#include "../Interfaces/IDbAdapter.h"
XS_IMPLEMENT_CLONABLE_CLASS(Database,xsSerializable);

Database::Database()
{
	m_name = wxT("");
	m_pDbAdapter = NULL;
}

Database::Database(const Database& obj):xsSerializable(obj)
{
		m_name = obj.m_name;
		m_pDbAdapter = obj.m_pDbAdapter;
}
Database::Database(IDbAdapter* dbAdapter,const wxString& dbName)
{
	m_name = dbName;
	if (dbAdapter){
		m_pDbAdapter = dbAdapter;
		m_pDbAdapter->GetTables(this);
		m_pDbAdapter->GetViews(this);
	}
	//this->tables = dbAdapter->GetTables(dbName);
}
Database::~Database()
{
	//delete this->tables;
}
void Database::RefreshChildren()
{
	GetChildrenList().DeleteContents(true);
	GetChildrenList().Clear();
	if (m_pDbAdapter){
		m_pDbAdapter->GetTables(this);
		m_pDbAdapter->GetViews(this);
	}
}

