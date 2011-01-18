#include "MySqlType.h"
XS_IMPLEMENT_CLONABLE_CLASS(MySqlType,IDbType);
MySqlType::MySqlType()
{
	m_dbtPropertyFlags = 0;
	InitSerialize();
}

MySqlType::MySqlType(const MySqlType& obj):IDbType(obj)
{
	m_typeName = obj.m_typeName;
	m_dbtPropertyFlags = obj.m_dbtPropertyFlags;
	m_autoIncrement = obj.m_autoIncrement;
	m_notNull = obj.m_notNull;
	m_primaryKey = obj.m_primaryKey;
	m_size = obj.m_size;
	m_size2 = obj.m_size2;
	m_unique = obj.m_unique;
	InitSerialize();
}

MySqlType::MySqlType(const wxString& typeName, long propertyFlags) {
	m_typeName = typeName;
	m_dbtPropertyFlags = propertyFlags;
	
	m_autoIncrement = false;
	m_notNull = false;
	m_primaryKey = false;
	m_size = 0;
	m_size2 = 0;
	m_unique = false;
	InitSerialize();
}

MySqlType::~MySqlType() {
}

wxString MySqlType::ReturnSql() {
	wxString sql;
	sql = wxString::Format(wxT(" %s"), m_typeName.c_str());
	if ((m_dbtPropertyFlags & dbtSIZE)&&(m_dbtPropertyFlags & dbtSIZE_TWO)) sql.append(wxString::Format(wxT("(%li,%li)"),m_size, m_size2));
	else if (m_dbtPropertyFlags & dbtSIZE) sql.append(wxString::Format(wxT("(%li)"),m_size));
	if ((m_dbtPropertyFlags & dbtNOT_NULL) && m_notNull) sql.append(wxT(" NOT NULL"));
	if ((m_dbtPropertyFlags & dbtAUTO_INCREMENT) && m_autoIncrement) sql.append(wxT(" AUTO INCREMENT"));
	return sql;
}

void MySqlType::InitSerialize()
{
	XS_SERIALIZE(m_typeName,wxT("m_typeName")); 
	XS_SERIALIZE_LONG(m_dbtPropertyFlags,wxT("m_dbtPropertyFlags")); 
	XS_SERIALIZE_LONG(m_size, wxT("m_size"));
	XS_SERIALIZE_LONG(m_size2, wxT("m_size2"));
	XS_SERIALIZE(m_unique, wxT("m_unique"));
	XS_SERIALIZE(m_primaryKey, wxT("m_primaryKey"));
	XS_SERIALIZE(m_notNull, wxT("m_notNull"));
	XS_SERIALIZE(m_autoIncrement, wxT("m_autoIncrement"));

}


