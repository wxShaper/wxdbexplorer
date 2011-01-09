#ifndef ERDTABLE_H
#define ERDTABLE_H

#include "wx/wxsf/RoundRectShape.h" // Base class: wxSFRoundRectShape
#include "wx/wxsf/TextShape.h"
#include "wx/wxsf/FlexGridShape.h"
#include "table.h"
#include "gui/Ids.h"
#include "IDbType.h"

class ErdTable : public wxSFRoundRectShape {

public:
	XS_DECLARE_CLONABLE_CLASS(ErdTable);	

	ErdTable();
	ErdTable(const ErdTable& obj);
	
	virtual ~ErdTable();
	
	void updateColumns();
	void addColumn(const wxString& colName, IDbType* type);
	Table* getTable() { return this->m_pTable; }

protected:
	void Initialize();
	
	wxSFTextShape *m_pLabel;
	Table* m_pTable;
	
	wxSFFlexGridShape* m_pGrid;
	
	virtual void DrawHighlighted(wxDC& dc);
	virtual void DrawHover(wxDC& dc);
	virtual void DrawNormal(wxDC& dc);
	void clearGrid();
	void addColumnShape(const wxString& colName, int id);
};

#endif // ERDTABLE_H
