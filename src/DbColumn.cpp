#include "DbColumn.h"

DbColumn::DbColumn( wxString parentName, wxString name, wxString type,wxString notNull, wxString key )
{
	m_parentName = parentName;
	m_name = name;
	m_type = type;
	m_notNull =  !(notNull == wxT("YES"));
	//TODO:Doresit klice
	m_primaryKey =  (key == wxT("PRI"));
	m_foreignKey =  ((!m_primaryKey)&&(key != wxT("")));
}

DbColumn::~DbColumn()
{
}

void DbColumn::SetParentName(wxString& databaseName)
{
	m_parentName =  databaseName;
}
void DbColumn::SetName(wxString& name)
{
	m_name = name;
}
