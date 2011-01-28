#include "dbconnection.h"

XS_IMPLEMENT_CLONABLE_CLASS(DbConnection,xsSerializable);

DbConnection::DbConnection()
{
	m_pDbAdapter = NULL;
}
DbConnection::DbConnection(IDbAdapter* dbAdapter, const wxString& serverName)
{
	m_serverName = serverName;
	m_pDbAdapter = dbAdapter;	
}

DbConnection::DbConnection(const DbConnection& obj) : xsSerializable(obj)
{
	m_serverName = obj.m_serverName;
}
DbConnection::~DbConnection()
{
	if (m_pDbAdapter) delete m_pDbAdapter;
}
void DbConnection::Load()
{
	if (m_pDbAdapter)
		if (m_pAdapter->CanConnect()){		
			m_pDbAdapter->GetDatabases(this);		
			}
}