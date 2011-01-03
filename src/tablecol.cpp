#include "tablecol.h"
#include <wx/arrimpl.cpp>

WX_DEFINE_OBJARRAY(ArrayOfTable);

TableCol::TableCol(const wxString& dbName)
{
	this->m_dbName = dbName;
}
TableCol::~TableCol()
{
	this->m_al.Clear();
}

void TableCol::AddTable(Table* tab)
{
	this->m_al.Add(tab);
}

Table* TableCol::GetByIndex(int i)
{
	Table& tab = this->m_al.Item(i);
	return &tab;
}

int TableCol::GetTableCount()
{
	return this->m_al.GetCount();
}



Table& TableCol::operator [](int i)
{
	return (Table&) this->m_al.Item(i);
}

