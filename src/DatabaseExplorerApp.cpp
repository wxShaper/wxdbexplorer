#include "DatabaseExplorerApp.h"
#include "gui/DatabaseExplorerFrame.h"

IMPLEMENT_APP(DatabaseExplorerApp);

bool DatabaseExplorerApp::OnInit()
{
	SetTopWindow( new DatabaseExplorerFrame( NULL ) );
	GetTopWindow()->Show();
	
	return true;
}
