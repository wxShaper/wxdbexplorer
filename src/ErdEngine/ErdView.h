#ifndef ERDVIEW_H
#define ERDVIEW_H

#include <wx/wx.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "wx/wxsf/RoundRectShape.h" // Base class: wxSFRoundRectShape
#include "wx/wxsf/TextShape.h"
#include "wx/wxsf/FlexGridShape.h"
#include "wx/wxsf/DiagramManager.h"
#include "../DbEngine/view.h"

class ErdView : public wxSFRoundRectShape {

public:
	XS_DECLARE_CLONABLE_CLASS(ErdView);	
	ErdView();
	ErdView(const ErdView& obj);
	ErdView(View* pView);
	virtual ~ErdView();
	
	View* getView() { return (View*) this->GetUserData(); }
	
	virtual void Update();
	
protected:
	void Initialize();
	
	virtual void DrawHighlighted(wxDC& dc);
	virtual void DrawHover(wxDC& dc);
	virtual void DrawNormal(wxDC& dc);
	
	void drawDetails(wxDC& dc);
	void updateView();
	
	wxSFTextShape *m_pLabel;
	wxSFTextShape *m_pSelect;
	wxSFFlexGridShape* m_pGrid;
};

#endif // ERDVIEW_H