#include "DatabaseExplorerApp.h"
#include "../Gui/DatabaseExplorerFrame.h"

IMPLEMENT_APP(DatabaseExplorerApp);

bool DatabaseExplorerApp::OnInit()
{
	m_AppPath = FindAppPath();
	wxMessageBox( m_AppPath );
	
	SetTopWindow( new DatabaseExplorerFrame( NULL ) );
	GetTopWindow()->Show();
	
	return true;
}

wxString DatabaseExplorerApp::FindAppPath()
{
   wxString str;

    // Try appVariableName
    if (!wxGetApp().GetAppName().IsEmpty())
    {
        str = wxGetenv(wxGetApp().GetAppName());
        if (!str.IsEmpty())
            return str;
    }

#if defined(__WXMAC__) && !defined(__DARWIN__)
    // On Mac, the current directory is the relevant one when
    // the application starts.
    return wxGetCwd();
#endif

    if (wxIsAbsolutePath(wxGetApp().argv[0]))
        return wxPathOnly(wxGetApp().argv[0]);
    else
    {
        // Is it a relative path?
        wxString currentDir(wxGetCwd());
        if (currentDir.Last() != wxFILE_SEP_PATH)
            currentDir += wxFILE_SEP_PATH;

        str = currentDir + wxGetApp().argv[0];
        if (wxFileExists(str))
            return wxPathOnly(str);
    }

    // OK, it's neither an absolute path nor a relative path.
    // Search PATH.

    wxPathList pathList;
    pathList.AddEnvList(wxT("PATH"));
    str = pathList.FindAbsoluteValidPath(wxGetApp().argv[0]);
    if (!str.IsEmpty())
        return wxPathOnly(str);

    // Failed
    return wxEmptyString;
}