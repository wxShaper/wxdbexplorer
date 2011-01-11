#include "columncol.h"
#include <wx/arrimpl.cpp>

XS_IMPLEMENT_CLONABLE_CLASS(ColumnCol,xsSerializable);

WX_DEFINE_OBJARRAY(ArrayOfColumn);

ColumnCol::ColumnCol()
{
	initSerializable();
}
ColumnCol::ColumnCol(const ColumnCol& obj): xsSerializable(obj)
{
	m_tableName = obj.m_tableName;
	//WX_APPEND_ARRAY(m_al, obj.m_al);
	initSerializable();
}

ColumnCol::ColumnCol(const wxString& tableName)
{
	this->m_tableName = tableName;
	initSerializable();
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

void ColumnCol::initSerializable()
{
	//XS_SERIALIZE_PROPERTY(m_al, wxT("serializabledynamicnocreate"), wxT("cols"));
	//XS_SERIALIZE(m_al, wxT("cols"));
	XS_SERIALIZE(m_tableName,wxT("tableName")); 
	
}

