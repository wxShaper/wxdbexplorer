#include "column.h"
Column::~Column()
{
}
// -------------------------------------------------
// Konstruktor
// -------------------------------------------------
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
		}
// metoda pro editaci sloupecku
void Column::Edit(wxString& name,
			wxString& parentName,
			wxString& type,
			bool notNull,
			bool primaryKey)
{
		this->m_name = name;
		this->m_parentName = parentName;
		this->m_type = type;
		this->m_notNull = notNull;
		this->m_primaryKey = primaryKey;				
		this->m_isSaved = false;				
}
