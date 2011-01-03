#ifndef ERDTABLE_H
#define ERDTABLE_H

#include "wx/wxsf/RoundRectShape.h" // Base class: wxSFRoundRectShape
#include "wx/wxsf/TextShape.h"
#include "table.h"

class ErdTable : public wxSFRoundRectShape {

public:
	ErdTable();
	virtual ~ErdTable();
	
	Table* getTable() { return this->m_pTable; }

protected:
	void Initialize();
	
	wxSFTextShape *m_pLabel;
	Table* m_pTable;
	
	virtual void DrawHighlighted(wxDC& dc);
	virtual void DrawHover(wxDC& dc);
	virtual void DrawNormal(wxDC& dc);
};

#endif // ERDTABLE_H
