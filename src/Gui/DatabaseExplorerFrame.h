#ifndef DATABASEEXPLORERFRAME_H
#define DATABASEEXPLORERFRAME_H

#include "GUI.h" // Base class: _MainFrame
#include <wx/aui/aui.h>

class DatabaseExplorerFrame : public _MainFrame
{

public:
	DatabaseExplorerFrame(wxWindow *parent);
	virtual ~DatabaseExplorerFrame();

	static void InitStyledTextCtrl(wxScintilla *sci);

	wxAuiManager m_Manager;

	virtual void OnExit(wxCommandEvent& event);
	virtual void OnAbout(wxCommandEvent& event);

	wxAuiNotebook* m_pNotebook;

};

#endif // DATABASEEXPLORERFRAME_H
