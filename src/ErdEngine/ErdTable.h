#ifndef ERDTABLE_H
#define ERDTABLE_H

#include <wx/wx.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "wx/wxsf/RoundRectShape.h"
#include "wx/wxsf/BitmapShape.h"
#include "wx/wxsf/TextShape.h"
#include "wx/wxsf/FlexGridShape.h"
#include "wx/wxsf/DiagramManager.h"
#include "../DbEngine/table.h"
#include "../DbEngine/constraint.h"
#include "../ErdEngine/ErdForeignKey.h"
#include "Gui/Ids.h"
#include "../Gui/NArrow.h"
#include "Interfaces/IDbType.h"
/*! \brief Class representig table graphics in ERD diagram. For more info see wxSF manual. */
class ErdTable : public wxSFRoundRectShape {

public:
	XS_DECLARE_CLONABLE_CLASS(ErdTable);	

	ErdTable();
	ErdTable(const ErdTable& obj);
	ErdTable(Table* tab);
	
	virtual ~ErdTable();
	
	void AddColumn(const wxString& colName, IDbType* type);
	void UpdateColumns();
	
	Table* GetTable() { return (Table*) this->GetUserData(); }

protected:	
	void Initialize();
	
	wxSFTextShape *m_pLabel;
	wxSFFlexGridShape* m_pGrid;
	
	virtual void DrawHighlighted(wxDC& dc);
	virtual void DrawHover(wxDC& dc);
	virtual void DrawNormal(wxDC& dc);
	
	void DrawDetails(wxDC& dc);
	
	void ClearGrid();
	void ClearConnections();
	void AddColumnShape(const wxString& colName, int id, Constraint::constraintType type);
	void SetCommonProps(wxSFShapeBase* shape);
};

#endif // ERDTABLE_H
