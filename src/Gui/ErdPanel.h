#ifndef ERDPANEL_H
#define ERDPANEL_H

#include "GUI.h" // Base class: _ErdPanel
#include <wx/wx.h>
#include <wx/textfile.h>
#include "wx/wxsf/wxShapeFramework.h"
#include "wx/wxsf/ShapeBase.h"
#include "../ErdEngine/FrameCanvas.h"
#include "Art.h"
#include "Ids.h"
#include "../ErdEngine/ErdTable.h"
#include "../ErdEngine/ErdView.h"
#include "../Interfaces/IDbAdapter.h"
#include "dbeclasstype.h"

class FrameCanvas;
class ErdPanel : public _ErdPanel {
public:
	DECLARE_DYNAMIC_CLASS(ErdPanel)
	enum MODE {
		modeDESIGN,
		modeTABLE,
		modeVIEW,
		modeLine
	};

	// public data accessors
	MODE GetToolMode() {
		return m_nToolMode;
	}
	void SetToolMode(MODE m) {
		m_nToolMode = m;
	}

	ErdPanel();
	ErdPanel(wxWindow *parent, IDbAdapter* dbAdapter);
	ErdPanel(wxWindow *parent, IDbAdapter* dbAdapter, Table* pTable);
	ErdPanel(wxWindow *parent, IDbAdapter* dbAdapter, xsSerializable* pItems);
	virtual ~ErdPanel();

	void Init(wxWindow *parent, IDbAdapter* dbAdapter);



	wxSFShapeCanvas* getCanvas();



protected:
	wxSFDiagramManager m_diagramManager;
	FrameCanvas* m_pFrameCanvas;
	ErdTable* m_pErdTable;

	IDbAdapter* m_pDbAdapter;

	MODE m_nToolMode;

	// event handlers
	void OnTool(wxCommandEvent& event);
	void OnToolUpdate(wxUpdateUIEvent& event);
	void OnLoad(wxCommandEvent& WXUNUSED(event));
	void OnSave(wxCommandEvent& WXUNUSED(event));
	void OnSaveSql(wxCommandEvent& WXUNUSED(event));
	virtual void OnMouseWheel(wxMouseEvent& event);
	

	DECLARE_EVENT_TABLE();

};

#endif // ERDPANEL_H
