#ifndef FRAMECANVAS_H
#define FRAMECANVAS_H

#include "gui/ErdPanel.h"
#include <wx/wx.h>
#include "wx/wxsf/ShapeCanvas.h" // Base class: wxSFShapeCanvas
#include <wx/clipbrd.h>
#include "mysqldbadapter.h"
#include "gui/tablesettings.h"
#include "IDbAdapter.h"

class ErdPanel;
class FrameCanvas : public wxSFShapeCanvas {

public:
	FrameCanvas() {
		;
	}
	FrameCanvas(wxSFDiagramManager* manager,IDbAdapter* dbAdapter, wxWindow* parent, wxPanel* parentPanel, wxWindowID id);
	virtual ~FrameCanvas();
	virtual void OnConnectionFinished(wxSFLineShape* connection);
	virtual void OnKeyDown(wxKeyEvent& event);
	virtual void OnRightDown(wxMouseEvent& event);
	virtual void OnLeftDown(wxMouseEvent& event);
	virtual void OnLeftDoubleClick(wxMouseEvent& event);

	void OnPopupClick(wxCommandEvent &evt);

protected:
	ErdPanel* m_pParentPanel;
	IDbAdapter* m_pDbAdapter;

};

#endif // FRAMECANVAS_H
