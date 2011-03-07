#ifndef ERDTABLE_H
#define ERDTABLE_H

#include <wx/wx.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "wx/wxsf/RoundRectShape.h" // Base class: wxSFRoundRectShape
#include "wx/wxsf/TextShape.h"
#include "wx/wxsf/FlexGridShape.h"
#include "wx/wxsf/DiagramManager.h"
#include "../DbEngine/table.h"
#include "../DbEngine/constraint.h"
//#include "../ErdEngine/ErdForeignKey.h"
#include "../ErdEngine/ErdForeignKey.h"
#include "Gui/Ids.h"
#include "../Gui/NArrow.h"
#include "Interfaces/IDbType.h"

class ErdTable : public wxSFRoundRectShape {

public:
	XS_DECLARE_CLONABLE_CLASS(ErdTable);	

	ErdTable();
	ErdTable(const ErdTable& obj);
	ErdTable(Table* tab);
	
	virtual ~ErdTable();
	
	virtual void Update();

	void addColumn(const wxString& colName, IDbType* type);
	Table* getTable() { return (Table*) this->GetUserData(); }

protected:
	void Initialize();
	
	wxSFTextShape *m_pLabel;
	//Table* m_pTable;
	
	wxSFFlexGridShape* m_pGrid;
	
	virtual void DrawHighlighted(wxDC& dc);
	virtual void DrawHover(wxDC& dc);
	virtual void DrawNormal(wxDC& dc);
	
	void updateColumns();
	void drawDetails(wxDC& dc);
	
	void clearGrid();
	void clearConnections();
	void addColumnShape(const wxString& colName, int id);
};

#endif // ERDTABLE_H
