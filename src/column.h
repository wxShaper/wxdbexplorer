#ifndef COLUMN_H
#define COLUMN_H
#include <wx/wx.h>
#include <wx/dblayer/DatabaseResultSet.h>
#include "IDbAdapter.h"
#include "IDbType.h"
// ------------------------------------------------
// Trida databazoveho sloupecku
// -------------------------------------------------

class Column {
protected:
	wxString m_name;
	wxString m_parentName;
	wxString m_type;	
	bool m_notNull;
	bool m_primaryKey;
	
	bool m_isSaved;	
	
	IDbType* m_pType;
	
public:
	// -------------------------------------------------
	// Konstruktor
	// -------------------------------------------------
	Column(const wxString& name,
			const wxString& parentName,
			const wxString& type,
			bool notNull,
			bool primaryKey);
	Column(const wxString& name,
			const wxString& parentName,
			IDbType* type,
			bool notNull,
			bool primaryKey);
	~Column();
	
	
	// nazev sloupecku
	wxString getName() { return this->m_name; }
	// nazev rodicovskeho prvku - tabulky nebo view
	wxString getParentName() { return this->m_parentName; }
	// nazev typu
	wxString getType() { return this->m_type; }
	// parametr NotNull
	bool NotNull() { return this->m_notNull; }
	// parametr PrimaryKey
	bool PrimaryKey() { return this->m_primaryKey; }
	// priznak isSaved
	bool IsSaved() { return this->m_isSaved; }
	
	// typ
	IDbType* getPType(){ return this->m_pType; }
	
	// funkce pro editaci sloupecku - nastuvje prizna isSaved na false
	void Edit(wxString& name,
			wxString& parentName,
			wxString& type,
			bool notNull,
			bool primaryKey);
	
};

#endif // COLUMN_H
