#include "database.h"
Database::Database(IDbAdapter* dbAdapter,const wxString& dbName)
{
	this->m_name = dbName;
	this->tables = dbAdapter->GetTables(dbName);
}
Database::~Database()
{
	delete this->tables;
}


