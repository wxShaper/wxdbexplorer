#include <wx/wx.h>

class DatabaseExplorerApp : public wxApp
{
public:
	virtual bool OnInit();
	
	const wxString& GetAppPath() const { return m_AppPath; }
	
protected:
	wxString m_AppPath;
	
	wxString FindAppPath();
};

DECLARE_APP(DatabaseExplorerApp);
