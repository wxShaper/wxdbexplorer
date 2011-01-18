#include "DatabaseExplorerFrame.h"
#include "SqlCommandPanel.h"
#include "../Main/BuildNum.h"
#include "DbViewerPanel.h"

#include <wx/dblayer/DatabaseLayer.h>
#include <wx/dblayer/MysqlDatabaseLayer.h>

DatabaseExplorerFrame::DatabaseExplorerFrame(wxWindow *parent) : _MainFrame(parent)
{
	DatabaseLayer *db = new MysqlDatabaseLayer();
	delete db;
	
	m_Manager.SetManagedWindow( this );

	m_pNotebook = new wxAuiNotebook(this,wxID_ANY);
	m_Manager.AddPane( new DbViewerPanel(this, m_pNotebook), wxAuiPaneInfo().DestroyOnClose(false).
					   Name(wxT("db_viewer_panel")).
					   Right().Caption(wxT("DB Viewer")).
					   CloseButton(false).
					   BestSize(wxSize(300,500)).
					   MinSize(wxSize(300,500)));

	
	m_Manager.AddPane(m_pNotebook, wxAuiPaneInfo().DestroyOnClose(false).
	                   Name(wxT("sql_command_panel")).Caption(wxT("SQL Command")).
	                   BestSize(wxSize(400,400)).MinSize(wxSize(400,400)).
					   CloseButton(false).
	                   Center() );

	m_Manager.SetFlags( m_Manager.GetFlags() | wxAUI_MGR_ALLOW_ACTIVE_PANE );
	m_Manager.GetArtProvider()->SetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE, 0);
	m_Manager.GetArtProvider()->SetMetric(wxAUI_DOCKART_SASH_SIZE, 4);

	m_Manager.Update();
}

DatabaseExplorerFrame::~DatabaseExplorerFrame()
{
	m_Manager.UnInit();
	delete m_pNotebook;
}

void DatabaseExplorerFrame::OnExit(wxCommandEvent& event)
{
	Destroy();
}

void DatabaseExplorerFrame::InitStyledTextCtrl(wxScintilla *sci)
{
	sci->SetLexer( wxSCI_LEX_SQL );
	sci->SetKeyWords(0, wxT("select insert update from drop create alter where values order by desc asc show table column tables columns limit as in ") );
	sci->StyleSetFont( wxSCI_STYLE_DEFAULT, *wxSWISS_FONT );
	sci->StyleSetBold( wxSCI_C_WORD, true );
	sci->StyleSetForeground( wxSCI_C_WORD, *wxBLUE );
	sci->StyleSetForeground( wxSCI_C_STRING, *wxRED );
	sci->StyleSetForeground( wxSCI_C_STRINGEOL, *wxRED );
	sci->StyleSetForeground( wxSCI_C_PREPROCESSOR, wxColour( 49, 106, 197 ) );
	sci->StyleSetForeground( wxSCI_C_COMMENT, wxColour( 0, 128, 0 ) );
	sci->StyleSetForeground( wxSCI_C_COMMENTLINE, wxColour( 0, 128, 0 ) );
	sci->StyleSetForeground( wxSCI_C_COMMENTDOC, wxColour( 0, 128, 0 ) );
	sci->StyleSetForeground( wxSCI_C_COMMENTLINEDOC, wxColour( 0, 128, 0 ) );
	sci->StyleSetForeground( wxSCI_C_NUMBER, *wxGREEN );

	sci->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	sci->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );

	sci->SetCaretWidth( 2 );

	sci->SetTabIndents(true);
	sci->SetBackSpaceUnIndents(true);
	sci->SetUseTabs( false );
	sci->SetTabWidth( 4 );
	sci->SetIndent( 4 );

	// markers
	sci->MarkerDefine(wxSCI_MARKNUM_FOLDER,        wxSCI_MARK_BOXPLUS);
	sci->MarkerSetBackground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("DARK GREY") ) );
	sci->MarkerSetForeground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );

	sci->MarkerDefine(wxSCI_MARKNUM_FOLDEROPEN,    wxSCI_MARK_BOXMINUS);
	sci->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("DARK GREY") ) );
	sci->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );

	sci->MarkerDefine(wxSCI_MARKNUM_FOLDERSUB,     wxSCI_MARK_VLINE);
	sci->MarkerSetBackground( wxSCI_MARKNUM_FOLDERSUB, wxColour( wxT("DARK GREY") ) );
	sci->MarkerSetForeground( wxSCI_MARKNUM_FOLDERSUB, wxColour( wxT("WHITE") ) );

	sci->MarkerDefine(wxSCI_MARKNUM_FOLDEREND,     wxSCI_MARK_EMPTY);
	sci->MarkerSetBackground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("DARK GREY") ) );
	sci->MarkerSetForeground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );

	sci->MarkerDefine(wxSCI_MARKNUM_FOLDEROPENMID, wxSCI_MARK_BOXMINUS);
	sci->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("DARK GREY") ) );
	sci->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );

	sci->MarkerDefine(wxSCI_MARKNUM_FOLDERMIDTAIL, wxSCI_MARK_TCORNER);
	sci->MarkerSetBackground( wxSCI_MARKNUM_FOLDERMIDTAIL, wxColour( wxT("DARK GREY") ) );
	sci->MarkerSetForeground( wxSCI_MARKNUM_FOLDERMIDTAIL, wxColour( wxT("WHITE") ) );

	sci->MarkerDefine(wxSCI_MARKNUM_FOLDERTAIL,    wxSCI_MARK_LCORNER);
	sci->MarkerSetBackground( wxSCI_MARKNUM_FOLDERTAIL, wxColour( wxT("DARK GREY") ) );
	sci->MarkerSetForeground( wxSCI_MARKNUM_FOLDERTAIL, wxColour( wxT("WHITE") ) );

	sci->SetFoldFlags( wxSCI_FOLDFLAG_LINEAFTER_CONTRACTED );
}

void DatabaseExplorerFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox( wxString::Format( wxT("DatabaseExplorer (build %d)"), deBUILD_NUMBER ) );
}
