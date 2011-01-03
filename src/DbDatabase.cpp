#include "DbDatabase.h"

DbDatabase::DbDatabase(const wxString databaseName)
{
	m_databaseName = databaseName;
}

DbDatabase::~DbDatabase()
{
}

wxString DbDatabase::GetParentName()
{
	return m_databaseName;
}

wxString DbDatabase::GetName()
{
	return m_databaseName;
}

void DbDatabase::SetParentName(wxString& databaseName)
{
	m_databaseName = databaseName;
}

void DbDatabase::SetName(wxString& name)
{
	m_databaseName = name;
}
