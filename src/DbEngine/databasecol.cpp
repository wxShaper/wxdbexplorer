#include "databasecol.h"
#include <wx/arrimpl.cpp>

WX_DEFINE_OBJARRAY(ArrayOfDatabase);
DatabaseCol::DatabaseCol()
{
	this->m_al.Clear();
}

DatabaseCol::~DatabaseCol()
{
	this->m_al.Clear();
}

void DatabaseCol::AddDatabase(Database* db)
{
	this->m_al.Add(db);
}

Database* DatabaseCol::GetByIndex(int i)
{
	Database& db = this->m_al.Item(i);
	return &db;
}

int DatabaseCol::GetDbCount()
{
	return this->m_al.GetCount();
}

Database& DatabaseCol::operator [](int i)
{
	return (Database&) this->m_al.Item(i);
}

