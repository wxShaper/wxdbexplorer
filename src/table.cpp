#include "table.h"
Table::Table()
{
	this->columns = new ColumnCol();
}

Table::Table(IDbAdapter* dbAdapter, const wxString& tableName, const wxString& parentName, int rowCount)
{
	this->m_name = tableName;
	this->m_parentName = parentName;
	this->m_rowCount = rowCount;
	this->columns = dbAdapter->GetColumns(this->m_name);
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

