#ifndef TABLE_H
#define TABLE_H

#include <wx/wx.h>
#include <wx/dblayer/DatabaseResultSet.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "columncol.h"
#include "IDbAdapter.h"
// -------------------------------------------------
// Trida databazove tabulky
// -------------------------------------------------
class Table : public xsSerializable {
protected:
	wxString m_name;
	wxString m_parentName;
	int m_rowCount;	
	bool m_isSaved;	
	
	void initSerializable();
	
	
public:
	XS_DECLARE_CLONABLE_CLASS(Table);
	
	Table();
	Table(const Table& obj);
	Table(IDbAdapter* dbAdapter,const wxString& tableName, const wxString& parentName, int rowCount);
	~Table();
	// nazev tabulky
	wxString getName() { return this->m_name; }
	// nazev rodicovskeho prvku - databaze
	wxString getParentName() { return this->m_parentName; }
	
	void setName(const wxString& name) ;
	
	// pocet radku
	int getRowCount() { return this->m_rowCount; }
	// priznak isSaved
	bool IsSaved() { return this->m_isSaved; }
	ColumnCol *columns;

};

#endif // TABLE_H
