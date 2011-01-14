#ifndef COLUMN_H
#define COLUMN_H
#include <wx/wx.h>
#include <wx/dblayer/DatabaseResultSet.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "IDbAdapter.h"
#include "IDbType.h"
// ------------------------------------------------
// Trida databazoveho sloupecku
// -------------------------------------------------

class Column : public xsSerializable {
protected:
	wxString m_name;
	wxString m_parentName;
	bool m_isSaved;	
	
	IDbType* m_pType;
	void initSerializable();
	
public:
	// -------------------------------------------------
	// Konstruktor
	// -------------------------------------------------
	XS_DECLARE_CLONABLE_CLASS(Column);
	Column();
	Column(const Column& obj);
	Column(const wxString& name,
			const wxString& parentName,
			IDbType* type);
	virtual ~Column();
	
	
	// nazev sloupecku
	wxString getName() { return this->m_name; }
	void setName(const wxString& name) { this->m_name = name; }
	// nazev rodicovskeho prvku - tabulky nebo view
	wxString getParentName() { return this->m_parentName; }
	// priznak isSaved
	bool IsSaved() { return this->m_isSaved; }
	
	// typ
	IDbType* getPType(){ return this->m_pType; }
	void setPType(IDbType* pType ) { delete this->m_pType; this->m_pType = pType; }
	
	// funkce pro editaci sloupecku - nastuvje prizna isSaved na false
	void Edit(wxString& name,
			wxString& parentName,
			IDbType* type);
	
};

#endif // COLUMN_H
