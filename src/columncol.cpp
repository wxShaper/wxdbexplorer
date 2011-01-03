#include "columncol.h"
#include <wx/arrimpl.cpp>

WX_DEFINE_OBJARRAY(ArrayOfColumn);

ColumnCol::ColumnCol()
{
}
ColumnCol::ColumnCol(const wxString& tableName)
{
	this->m_tableName = tableName;
}

Column* ColumnCol::GetByIndex(int i)
{
	Column& col = this->m_al.Item(i);
	return &col;
}

int ColumnCol::GetColCount()
{
	return this->m_al.GetCount();
}

Column& ColumnCol::operator [](int i)
{
	return (Column&) this->m_al.Item(i);
}

ColumnCol::~ColumnCol()
{
	this->m_al.Clear();
}

void ColumnCol::AddColumn(Column* col)
{
	this->m_al.Add(col);
}
void ColumnCol::SetTableName(const wxString& tableName)
{
	this->m_tableName = tableName;
}

