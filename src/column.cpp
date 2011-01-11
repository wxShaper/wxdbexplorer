#include "column.h"

XS_IMPLEMENT_CLONABLE_CLASS(Column,xsSerializable);
Column::Column()
{
	initSerializable();
}
Column::~Column()
{
}
// -------------------------------------------------
// Konstruktor
// -------------------------------------------------
Column::Column(const Column& obj):xsSerializable(obj)
{
	m_pType = NULL;
	m_name = obj.m_name;
	m_parentName = obj.m_parentName;
	m_notNull = obj.m_notNull;
	m_primaryKey = obj.m_primaryKey;
	initSerializable();
}
Column::Column(const wxString& name,
			const wxString& parentName,
			const wxString& type,
			bool notNull,
			bool primaryKey)
{
		this->m_name = name;
		this->m_parentName = parentName;
		this->m_type = type;
		this->m_notNull = notNull;
		this->m_primaryKey = primaryKey,
		this->m_isSaved = true;
		m_pType = NULL;
		initSerializable();
		}
Column::Column(const wxString& name,
			const wxString& parentName,
			IDbType* type,
			bool notNull,
			bool primaryKey)
{
		this->m_name = name;
		this->m_parentName = parentName;
		this->m_type = wxT("no type");
		this->m_notNull = notNull;
		this->m_primaryKey = primaryKey,
		this->m_isSaved = true;
		this->m_pType = type;
		initSerializable();
		}
// metoda pro editaci sloupecku
void Column::Edit(wxString& name,
			wxString& parentName,
			wxString& type,
			bool notNull,
			bool primaryKey)
{
		this->m_pType = NULL;
		this->m_name = name;
		this->m_parentName = parentName;
		this->m_type = type;
		this->m_notNull = notNull;
		this->m_primaryKey = primaryKey;				
		this->m_isSaved = false;	

}



void Column::initSerializable()
{
		XS_SERIALIZE(m_name,wxT("m_name")); 
		XS_SERIALIZE(m_parentName,wxT("m_parentName")); 
		XS_SERIALIZE(m_notNull,wxT("m_notNull")); 
		XS_SERIALIZE(m_primaryKey,wxT("m_primaryKey")); 
}

