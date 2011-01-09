#include "table.h"

XS_IMPLEMENT_CLONABLE_CLASS(Table,xsSerializable);

Table::Table()
{
	this->columns = new ColumnCol();
	initSerializable();
}

Table::Table(const Table& obj): xsSerializable(obj)
{
	this->m_name = obj.m_name;
	this->m_parentName = obj.m_parentName;
	this->m_rowCount = obj.m_rowCount;
	this->columns = (ColumnCol*) obj.columns->Clone();
		
	initSerializable();
	this->columns = NULL;
}


Table::Table(IDbAdapter* dbAdapter, const wxString& tableName, const wxString& parentName, int rowCount)
{
	this->m_name = tableName;
	this->m_parentName = parentName;
	this->m_rowCount = rowCount;
	
	this->columns = dbAdapter->GetColumns(this->m_name);
	
	initSerializable();
}
Table::~Table()
{
	delete this->columns;
}
void Table::setName(const wxString& name)
{
	 this->m_isSaved = false; 
	 this->m_name = name; 
	 if (this->columns) this->columns->SetTableName(name);
}




void Table::initSerializable()
{
	XS_SERIALIZE(this->m_name,wxT("tableName")); 
	XS_SERIALIZE(this->m_parentName,wxT("parentName")); 
	XS_SERIALIZE_INT(this->m_rowCount, wxT("rowCount"));
	XS_SERIALIZE_DYNAMIC_OBJECT(columns, wxT("ColumnCol"));
}

