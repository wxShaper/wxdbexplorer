#ifndef ERDPANEL_H
#define ERDPANEL_H

#include "GUI.h" // Base class: _ErdPanel
#include "wx/wxsf/wxShapeFramework.h"
#include "../ErdEngine/FrameCanvas.h"
#include "Art.h"
#include "Ids.h"
#include "../ErdEngine/ErdTable.h"
#include "../Interfaces/IDbAdapter.h"

class FrameCanvas;
class ErdPanel : public _ErdPanel {
public:

	enum MODE {
		modeDESIGN,
		modeTABLE
	};

	// public data accessors
	MODE GetToolMode() {
		return m_nToolMode;
	}
	void SetToolMode(MODE m) {
		m_nToolMode = m;
	}


	ErdPanel(wxWindow *parent, IDbAdapter* dbAdapter);
	virtual ~ErdPanel();
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


	DECLARE_EVENT_TABLE();

};

#endif // ERDPANEL_H
