#include "DatabaseExplorerFrame.h"
#include "SqlCommandPanel.h"
#include "../Main/BuildNum.h"
#include "DbViewerPanel.h"

#include <wx/dblayer/include/DatabaseLayer.h>
#ifdef DBL_USE_MYSQL
#include <wx/dblayer/include/MysqlDatabaseLayer.h>
#endif

#include <wx/aboutdlg.h>

#include "wx/wxsf/AutoLayout.h"

enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

DatabaseExplorerFrame::DatabaseExplorerFrame(wxWindow *parent) : _MainFrame(parent)
{
	#ifdef DBL_USE_MYSQL
	DatabaseLayer *db = new MysqlDatabaseLayer();
	delete db;
	#endif
	
	m_Manager.SetManagedWindow( this );

	m_pNotebook = new wxAuiNotebook(this,wxID_ANY);
	m_Manager.AddPane( new DbViewerPanel(this, m_pNotebook), wxAuiPaneInfo().DestroyOnClose(false).
					   Name(wxT("db_viewer_panel")).
					   Right().Caption(wxT("DB Viewer")).
					   CloseButton(false).
					   BestSize(wxSize(300,500)).
					   MinSize(wxSize(300,500)));

	
	m_Manager.AddPane(m_pNotebook, wxAuiPaneInfo().DestroyOnClose(false).
	                   Name(wxT("sql_command_panel")).Caption(wxT("Explorer")).
	                   BestSize(wxSize(400,400)).MinSize(wxSize(400,400)).
					   CloseButton(false).
	                   Center() );

	m_Manager.SetFlags( m_Manager.GetFlags() | wxAUI_MGR_ALLOW_ACTIVE_PANE );
	m_Manager.GetArtProvider()->SetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE, 0);
	m_Manager.GetArtProvider()->SetMetric(wxAUI_DOCKART_SASH_SIZE, 4);

	// configure autolayout algorithns
	wxSFAutoLayout layout;
	
	wxSFLayoutHorizontalTree *pHTreeAlg = wxDynamicCast( layout.GetAlgorithm( wxT("Horizontal Tree") ), wxSFLayoutHorizontalTree );
	if( pHTreeAlg ) pHTreeAlg->SetHSpace( 200 );
	
	wxSFLayoutVerticalTree *pVTreeAlg = wxDynamicCast( layout.GetAlgorithm( wxT("Vertical Tree") ), wxSFLayoutVerticalTree );
	if( pVTreeAlg ) pVTreeAlg->SetVSpace( 75 );
	
	Maximize();
	
	m_Manager.Update();
}

DatabaseExplorerFrame::~DatabaseExplorerFrame()
{
	wxSFAutoLayout::CleanUp();
	
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
	wxString version = wxString::Format( wxT("0.1.0.%d Alpha"), deBUILD_NUMBER);

    wxString desc = wxT("Cross-platform database tool designed for managing data, ERD and code generation.\n\n");
	desc << wxbuildinfo(long_f) << wxT("\n\n");

    wxAboutDialogInfo info;
    info.SetName(wxT("DatabaseExplorer"));
    info.SetVersion(version);
    info.SetDescription(desc);
    info.SetCopyright(wxT("2011 (C) Tomas Bata University, Zlin, Czech Republic"));
    info.SetWebSite(wxT("http://www.fai.utb.cz"));
    info.AddDeveloper(wxT("Peter Janků"));
    info.AddDeveloper(wxT("Michal Bližňák"));

    wxAboutBox(info);
}
