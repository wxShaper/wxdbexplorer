#ifndef TABLE_H
#define TABLE_H

#include <wx/wx.h>
#include <wx/dblayer/include/DatabaseResultSet.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "column.h"
#include "constraint.h"
#include "../Interfaces/IDbAdapter.h"
// -------------------------------------------------
// Trida databazove tabulky
// -------------------------------------------------
class Table : public xsSerializable {
protected:
	wxString m_name;
	wxString m_parentName;
	IDbAdapter* m_pDbAdapter;
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
	void RefreshChildren();
	void setName(const wxString& name) ;
	
	// pocet radku
	int getRowCount() { return this->m_rowCount; }
	// priznak isSaved
	bool IsSaved() { return this->m_isSaved; }
	//ColumnCol *columns;
	void AddColumn(Column* col) { this->AddChild(col); }
	void AddConstraint(Constraint* cont) { this->AddChild(cont); } 
	
	Column* GetFristColumn() { return (Column*) GetFirstChild( CLASSINFO(Column)); }
	
	IDbAdapter* GetDbAdapter() { return m_pDbAdapter; }
};

#endif // TABLE_H
