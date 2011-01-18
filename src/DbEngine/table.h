#ifndef TABLE_H
#define TABLE_H

#include <wx/wx.h>
#include <wx/dblayer/DatabaseResultSet.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "column.h"
#include "Interfaces/IDbAdapter.h"
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
	virtual ~Table();
	// nazev tabulky
	wxString getName() { return this->m_name; }
	// nazev rodicovskeho prvku - databaze
	wxString getParentName() { return this->m_parentName; }
	
	void setName(const wxString& name) ;
	
	// pocet radku
	int getRowCount() { return this->m_rowCount; }
	// priznak isSaved
	bool IsSaved() { return this->m_isSaved; }
	//ColumnCol *columns;
	void AddColumn(Column* col) { this->AddChild(col); }
	Column* GetFristColumn() { return (Column*) GetFirstChild( CLASSINFO(Column)); }
};

#endif // TABLE_H
