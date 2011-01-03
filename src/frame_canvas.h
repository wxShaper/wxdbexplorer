#ifndef FRAMECANVAS_H
#define FRAMECANVAS_H

#include "gui/ErdPanel.h"
#include <wx/wx.h>
#include "wx/wxsf/ShapeCanvas.h" // Base class: wxSFShapeCanvas
#include <wx/clipbrd.h>
#include "mysqldbadapter.h"

class ErdPanel;
class FrameCanvas : public wxSFShapeCanvas {

public:
	FrameCanvas(){;}
	FrameCanvas(wxSFDiagramManager* manager, wxWindow* parent, wxPanel* parentPanel, wxWindowID id);
	virtual ~FrameCanvas();
	virtual void OnConnectionFinished(wxSFLineShape* connection);
	virtual void OnKeyDown(wxKeyEvent& event);
	virtual void OnRightDown(wxMouseEvent& event);
	virtual void OnLeftDown(wxMouseEvent& event);
	
	void OnPopupClick(wxCommandEvent &evt);

protected:
	ErdPanel* m_pParentPanel;

};

#endif // FRAMECANVAS_H
