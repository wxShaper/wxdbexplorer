#ifndef COLUMNCOL_H
#define COLUMNCOL_H
#include <wx/wx.h>
#include <wx/dynarray.h>
#include <wx/dblayer/DatabaseResultSet.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "column.h"
#include "IDbAdapter.h"

WX_DECLARE_OBJARRAY(Column, ArrayOfColumn);

// -------------------------------------------------
// Colekce sloupecku tabulky
// -------------------------------------------------
class ColumnCol : public xsSerializable {
protected:
	ArrayOfColumn m_al;		
	wxString m_tableName;
	
	void initSerializable();
	
public:
	XS_DECLARE_CLONABLE_CLASS(Table);

	ColumnCol();
	ColumnCol(const ColumnCol& obj);
	ColumnCol(const wxString& tableName);
	~ColumnCol();
	
	void SetTableName(const wxString& tableName);
	
	Column* GetByIndex(int i);
	Column& operator[](int i);
	int	GetColCount();
	void AddColumn(Column* col);
};

#endif // COLUMNCOL_H
