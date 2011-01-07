#include "my_sql_type.h"

MySqlType::MySqlType(const wxString& typeName, bool haveAutoIncrement, bool haveNotNull, bool havePrimaryKey, bool haveSize, bool haveUnique)
{
	m_typeName = typeName;
	m_haveAutoIncrement = haveAutoIncrement;
	m_haveNotNull = haveNotNull;
	m_havePrimaryKey = havePrimaryKey;
	m_haveSize = haveSize;
	m_haveUnique = haveUnique;
}

MySqlType::~MySqlType() {
}

wxString MySqlType::ReturnSql() {
	wxString sql;
	sql = wxString::Format(wxT(" %s"), m_typeName.c_str());
	if (m_haveSize) sql.append(wxString::Format(wxT("(%i)"),m_size));
	if (m_haveNotNull && m_notNull) sql.append(wxT(" NOT NULL"));
	if (m_havePrimaryKey && m_primaryKey) sql.append(wxT(" PRIMARY KEY"));
	return sql;
}


