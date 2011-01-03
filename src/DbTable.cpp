#include "DbTable.h"

DbTable::DbTable(wxString& tableName, wxString& databaseName)
{
	m_tableName = tableName;
	m_databaseName = databaseName;
}

DbTable::~DbTable()
{
}

wxString DbTable::GetParentName()
{
	return m_databaseName;
}
wxString DbTable::GetName()
{
	return m_tableName;
}

void DbTable::SetParentName(wxString& databaseName)
{
	m_databaseName = databaseName;
}
void DbTable::SetName(wxString& name)
{
	m_tableName = name;
}

