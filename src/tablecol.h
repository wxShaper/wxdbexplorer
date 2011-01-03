#ifndef TABLECOL_H
#define TABLECOL_H
#include <wx/wx.h>
#include <wx/dynarray.h>
#include <wx/dblayer/DatabaseResultSet.h>
#include "table.h"
#include "IDbAdapter.h"

WX_DECLARE_OBJARRAY(Table, ArrayOfTable);

// -------------------------------------------------
// Colekce tabulek
// -------------------------------------------------
class TableCol {
protected:
	ArrayOfTable m_al;		
	wxString m_dbName;
	
public:
	TableCol(const wxString& dbName);
	~TableCol();
	Table* GetByIndex(int i);
	Table& operator[](int i);
	int	GetTableCount();
	void AddTable(Table* tab);
};

#endif // TABLECOL_H
