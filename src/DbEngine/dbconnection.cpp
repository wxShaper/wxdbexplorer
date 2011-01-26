#include "dbconnection.h"

XS_IMPLEMENT_CLONABLE_CLASS(Table,xsSerializable);

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
}
DbConnection::~DbConnection()
{
	if (m_pDbAdapter) delete m_pDbAdapter;
}




