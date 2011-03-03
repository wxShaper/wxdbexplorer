#ifndef VIEWSETTINGS_H
#define VIEWSETTINGS_H

#include <wx/wx.h>
#include <wx/validate.h>
#include "GUI.h" // Base class: _TableSettings
#include <wx/wxsf/DiagramManager.h>

#include "../Interfaces/IDbAdapter.h"
#include "../DbEngine/view.h"


class ViewSettings : public _ViewSettings {

public:
	ViewSettings( wxWindow* parent,IDbAdapter* pDbAdapter);
	virtual ~ViewSettings();

	void SetView(View* pView, wxSFDiagramManager* pManager);

	virtual void OnOKClick(wxCommandEvent& event);
	
protected:
	IDbAdapter* m_pDbAdapter;
	View* m_pView;
	wxSFDiagramManager* m_pDiagramManager;
};

#endif // VIEWSETTINGS_H
