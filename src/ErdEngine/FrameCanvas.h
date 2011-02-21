#ifndef FRAMECANVAS_H
#define FRAMECANVAS_H

#include "Gui/ErdPanel.h"
#include <wx/wx.h>
#include <wx/list.h>
#include "wx/wxsf/ShapeCanvas.h" // Base class: wxSFShapeCanvas
#include <wx/wxsf/DiagramManager.h>
#include <wx/hashmap.h>
#include <wx/clipbrd.h>

#ifdef DBL_MYSQL
#include "../Main/MySqlDbAdapter.h"
#endif

#include "../Gui/TableSettingsDialog.h"
#include "../Interfaces/IDbAdapter.h"
#include "DnDTableShape.h"

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

	virtual bool OnPreConnectionFinished(wxSFLineShape* connection);


	virtual void OnDrop(wxCoord x, wxCoord y, wxDragResult def, const ShapeList& dropped);

	void OnPopupClick(wxCommandEvent &evt);

	wxString GetSqlScript();

protected:
	ErdPanel* m_pParentPanel;
	IDbAdapter* m_pDbAdapter;

};

#endif // FRAMECANVAS_H
