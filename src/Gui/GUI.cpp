///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar  1 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

#include "../res/gui/Grid.xpm"
#include "../res/gui/database.xpm"
#include "../res/gui/delete.xpm"
#include "../res/gui/refresh.xpm"

///////////////////////////////////////////////////////////////////////////

_MainFrame::_MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar3 = new wxMenuBar( 0 );
	menuFile = new wxMenu();
	wxMenuItem* menuFileExit;
	menuFileExit = new wxMenuItem( menuFile, wxID_EXIT, wxString( wxT("E&xit") ) , wxEmptyString, wxITEM_NORMAL );
	menuFile->Append( menuFileExit );
	
	m_menubar3->Append( menuFile, wxT("&File") ); 
	
	menuHelp = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( menuHelp, wxID_ABOUT, wxString( wxT("&About...") ) , wxEmptyString, wxITEM_NORMAL );
	menuHelp->Append( menuHelpAbout );
	
	m_menubar3->Append( menuHelp, wxT("&Help") ); 
	
	this->SetMenuBar( m_menubar3 );
	
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( menuFileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( _MainFrame::OnExit ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( _MainFrame::OnAbout ) );
}

_MainFrame::~_MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( _MainFrame::OnExit ) );
	this->Disconnect( wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( _MainFrame::OnAbout ) );
	
}

_ThumbPane::_ThumbPane( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	this->SetSizer( mainSizer );
	this->Layout();
}

_ThumbPane::~_ThumbPane()
{
}

_SqlCommandPanel::_SqlCommandPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer3->AddGrowableCol( 0 );
	fgSizer3->AddGrowableRow( 0 );
	fgSizer3->AddGrowableRow( 2 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_LIVE_UPDATE );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( _SqlCommandPanel::m_splitter1OnIdle ), NULL, this );
	
	m_panel13 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer14;
	fgSizer14 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer14->AddGrowableCol( 0 );
	fgSizer14->AddGrowableRow( 0 );
	fgSizer14->SetFlexibleDirection( wxBOTH );
	fgSizer14->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_scintillaSQL = new wxScintilla( m_panel13, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0, wxEmptyString );
	m_scintillaSQL->SetUseTabs( true );
	m_scintillaSQL->SetTabWidth( 4 );
	m_scintillaSQL->SetIndent( 4 );
	m_scintillaSQL->SetTabIndents( true );
	m_scintillaSQL->SetBackSpaceUnIndents( true );
	m_scintillaSQL->SetViewEOL( false );
	m_scintillaSQL->SetViewWhiteSpace( false );
	m_scintillaSQL->SetMarginWidth( 2, 0 );
	m_scintillaSQL->SetIndentationGuides( true );
	m_scintillaSQL->SetMarginType( 1, wxSCI_MARGIN_SYMBOL );
	m_scintillaSQL->SetMarginMask( 1, wxSCI_MASK_FOLDERS );
	m_scintillaSQL->SetMarginWidth( 1, 16);
	m_scintillaSQL->SetMarginSensitive( 1, true );
	m_scintillaSQL->SetProperty( wxT("fold"), wxT("1") );
	m_scintillaSQL->SetFoldFlags( wxSCI_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSCI_FOLDFLAG_LINEAFTER_CONTRACTED );
	m_scintillaSQL->SetMarginType( 0, wxSCI_MARGIN_NUMBER );
	m_scintillaSQL->SetMarginWidth( 0, m_scintillaSQL->TextWidth( wxSCI_STYLE_LINENUMBER, wxT("_99999") ) );
	m_scintillaSQL->MarkerDefine( wxSCI_MARKNUM_FOLDER, wxSCI_MARK_BOXPLUS );
	m_scintillaSQL->MarkerSetBackground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	m_scintillaSQL->MarkerSetForeground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	m_scintillaSQL->MarkerDefine( wxSCI_MARKNUM_FOLDEROPEN, wxSCI_MARK_BOXMINUS );
	m_scintillaSQL->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	m_scintillaSQL->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	m_scintillaSQL->MarkerDefine( wxSCI_MARKNUM_FOLDERSUB, wxSCI_MARK_EMPTY );
	m_scintillaSQL->MarkerDefine( wxSCI_MARKNUM_FOLDEREND, wxSCI_MARK_BOXPLUS );
	m_scintillaSQL->MarkerSetBackground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	m_scintillaSQL->MarkerSetForeground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	m_scintillaSQL->MarkerDefine( wxSCI_MARKNUM_FOLDEROPENMID, wxSCI_MARK_BOXMINUS );
	m_scintillaSQL->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	m_scintillaSQL->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	m_scintillaSQL->MarkerDefine( wxSCI_MARKNUM_FOLDERMIDTAIL, wxSCI_MARK_EMPTY );
	m_scintillaSQL->MarkerDefine( wxSCI_MARKNUM_FOLDERTAIL, wxSCI_MARK_EMPTY );
	m_scintillaSQL->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_scintillaSQL->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	m_scintillaSQL->SetMinSize( wxSize( -1,150 ) );
	
	fgSizer14->Add( m_scintillaSQL, 1, wxEXPAND, 5 );
	
	m_panel13->SetSizer( fgSizer14 );
	m_panel13->Layout();
	fgSizer14->Fit( m_panel13 );
	m_panel14 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer15;
	fgSizer15 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer15->AddGrowableCol( 0 );
	fgSizer15->AddGrowableRow( 1 );
	fgSizer15->SetFlexibleDirection( wxBOTH );
	fgSizer15->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_panel3 = new wxPanel( m_panel14, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 1, 4, 0, 0 );
	fgSizer7->AddGrowableCol( 1 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_btnExecute = new wxButton( m_panel3, wxID_ANY, wxT("Execute"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_btnExecute, 0, wxALL, 5 );
	
	m_labelStatus = new wxStaticText( m_panel3, wxID_ANY, wxT("Result:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labelStatus->Wrap( -1 );
	fgSizer7->Add( m_labelStatus, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_btnSave = new wxButton( m_panel3, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_btnSave, 0, wxALL, 5 );
	
	m_btnLoad = new wxButton( m_panel3, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_btnLoad, 0, wxALL, 5 );
	
	m_panel3->SetSizer( fgSizer7 );
	m_panel3->Layout();
	fgSizer7->Fit( m_panel3 );
	fgSizer15->Add( m_panel3, 1, wxEXPAND, 5 );
	
	m_gridTable = new wxGrid( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gridTable->CreateGrid( 5, 5 );
	m_gridTable->EnableEditing( true );
	m_gridTable->EnableGridLines( true );
	m_gridTable->EnableDragGridSize( false );
	m_gridTable->SetMargins( 0, 0 );
	
	// Columns
	m_gridTable->AutoSizeColumns();
	m_gridTable->EnableDragColMove( false );
	m_gridTable->EnableDragColSize( true );
	m_gridTable->SetColLabelSize( 30 );
	m_gridTable->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridTable->SetRowSize( 0, 25 );
	m_gridTable->SetRowSize( 1, 25 );
	m_gridTable->SetRowSize( 2, 25 );
	m_gridTable->SetRowSize( 3, 26 );
	m_gridTable->SetRowSize( 4, 25 );
	m_gridTable->EnableDragRowSize( true );
	m_gridTable->SetRowLabelSize( 80 );
	m_gridTable->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridTable->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer15->Add( m_gridTable, 1, wxEXPAND, 5 );
	
	m_panel14->SetSizer( fgSizer15 );
	m_panel14->Layout();
	fgSizer15->Fit( m_panel14 );
	m_splitter1->SplitHorizontally( m_panel13, m_panel14, 120 );
	fgSizer3->Add( m_splitter1, 1, wxEXPAND, 5 );
	
	this->SetSizer( fgSizer3 );
	this->Layout();
	
	// Connect Events
	m_scintillaSQL->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( _SqlCommandPanel::OnScintilaKeyDown ), NULL, this );
	m_btnExecute->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _SqlCommandPanel::OnExecuteClick ), NULL, this );
	m_btnSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _SqlCommandPanel::OnSaveClick ), NULL, this );
	m_btnLoad->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _SqlCommandPanel::OnLoadClick ), NULL, this );
}

_SqlCommandPanel::~_SqlCommandPanel()
{
	// Disconnect Events
	m_scintillaSQL->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( _SqlCommandPanel::OnScintilaKeyDown ), NULL, this );
	m_btnExecute->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _SqlCommandPanel::OnExecuteClick ), NULL, this );
	m_btnSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _SqlCommandPanel::OnSaveClick ), NULL, this );
	m_btnLoad->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _SqlCommandPanel::OnLoadClick ), NULL, this );
	
}

_AdapterSelectDlg::_AdapterSelectDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_btnMySql = new wxButton( this, wxID_ANY, wxT("MySql"), wxDefaultPosition, wxSize( 175,-1 ), 0 );
	bSizer9->Add( m_btnMySql, 0, wxALL|wxEXPAND, 5 );
	
	m_btnSqlite = new wxButton( this, wxID_ANY, wxT("SQLite"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_btnSqlite, 0, wxALL|wxEXPAND, 5 );
	
	m_button24 = new wxButton( this, wxID_ANY, wxT("PostgreSQL"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button24, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer9 );
	this->Layout();
	bSizer9->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_btnMySql->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _AdapterSelectDlg::OnMysqlClick ), NULL, this );
	m_btnSqlite->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _AdapterSelectDlg::OnSqliteClick ), NULL, this );
	m_button24->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _AdapterSelectDlg::OnPostgresClick ), NULL, this );
}

_AdapterSelectDlg::~_AdapterSelectDlg()
{
	// Disconnect Events
	m_btnMySql->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _AdapterSelectDlg::OnMysqlClick ), NULL, this );
	m_btnSqlite->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _AdapterSelectDlg::OnSqliteClick ), NULL, this );
	m_button24->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _AdapterSelectDlg::OnPostgresClick ), NULL, this );
	
}

_DbViewerPanel::_DbViewerPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook2 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel19 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer18->AddGrowableCol( 0 );
	fgSizer18->AddGrowableRow( 0 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_splitterPanels = new wxSplitterWindow( m_panel19, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitterPanels->Connect( wxEVT_IDLE, wxIdleEventHandler( _DbViewerPanel::m_splitterPanelsOnIdle ), NULL, this );
	
	m_panelData = new wxPanel( m_splitterPanels, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_toolBar1 = new wxToolBar( m_panelData, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	m_toolBar1->AddTool( wxID_CONNECT, wxT("Open connection"), wxBitmap( database_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Open new connection"), wxT("Open new connection"), NULL ); 
	m_toolBar1->AddTool( wxID_CLOSE_CONNECTION, wxT("tool"), wxBitmap( delete_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Close selected connection"), wxT("Close selected connection"), NULL ); 
	m_toolBar1->AddTool( wxID_TOOL_REFRESH, wxT("tool"), wxBitmap( refresh_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	m_toolBar1->AddTool( wxID_TOOL_ERD, wxT("ERD"), wxBitmap( Grid_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	m_toolBar1->Realize(); 
	
	bSizer4->Add( m_toolBar1, 0, wxEXPAND, 5 );
	
	m_treeDatabases = new wxTreeCtrl( m_panelData, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTR_DEFAULT_STYLE|wxTR_HIDE_ROOT|wxTR_LINES_AT_ROOT );
	m_treeDatabases->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	bSizer4->Add( m_treeDatabases, 1, wxEXPAND, 5 );
	
	m_panelData->SetSizer( bSizer4 );
	m_panelData->Layout();
	bSizer4->Fit( m_panelData );
	m_panelThumb = new wxPanel( m_splitterPanels, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_thmSizer = new wxBoxSizer( wxVERTICAL );
	
	m_panelThumb->SetSizer( m_thmSizer );
	m_panelThumb->Layout();
	m_thmSizer->Fit( m_panelThumb );
	m_splitterPanels->SplitHorizontally( m_panelData, m_panelThumb, 305 );
	fgSizer18->Add( m_splitterPanels, 1, wxEXPAND, 5 );
	
	m_panel19->SetSizer( fgSizer18 );
	m_panel19->Layout();
	fgSizer18->Fit( m_panel19 );
	m_notebook2->AddPage( m_panel19, wxT("Databases"), false );
	
	bSizer2->Add( m_notebook2, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxID_CONNECT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnConncectClick ) );
	this->Connect( wxID_CONNECT, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DbViewerPanel::OnConncectUI ) );
	this->Connect( wxID_CLOSE_CONNECTION, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnToolCloseClick ) );
	this->Connect( wxID_CLOSE_CONNECTION, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DbViewerPanel::OnToolCloseUI ) );
	this->Connect( wxID_TOOL_REFRESH, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnRefreshClick ) );
	this->Connect( wxID_TOOL_ERD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnERDClick ) );
	m_treeDatabases->Connect( wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler( _DbViewerPanel::OnDnDStart ), NULL, this );
	m_treeDatabases->Connect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( _DbViewerPanel::OnItemActivate ), NULL, this );
	m_treeDatabases->Connect( wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK, wxTreeEventHandler( _DbViewerPanel::OnItemRightClick ), NULL, this );
	m_treeDatabases->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( _DbViewerPanel::OnItemSelectionChange ), NULL, this );
}

_DbViewerPanel::~_DbViewerPanel()
{
	// Disconnect Events
	this->Disconnect( wxID_CONNECT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnConncectClick ) );
	this->Disconnect( wxID_CONNECT, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DbViewerPanel::OnConncectUI ) );
	this->Disconnect( wxID_CLOSE_CONNECTION, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnToolCloseClick ) );
	this->Disconnect( wxID_CLOSE_CONNECTION, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DbViewerPanel::OnToolCloseUI ) );
	this->Disconnect( wxID_TOOL_REFRESH, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnRefreshClick ) );
	this->Disconnect( wxID_TOOL_ERD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnERDClick ) );
	m_treeDatabases->Disconnect( wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler( _DbViewerPanel::OnDnDStart ), NULL, this );
	m_treeDatabases->Disconnect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( _DbViewerPanel::OnItemActivate ), NULL, this );
	m_treeDatabases->Disconnect( wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK, wxTreeEventHandler( _DbViewerPanel::OnItemRightClick ), NULL, this );
	m_treeDatabases->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( _DbViewerPanel::OnItemSelectionChange ), NULL, this );
	
}

_DBSettingsDialog::_DBSettingsDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook2 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_MySqlPanel = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer3->AddGrowableRow( 2 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_MySqlPanel, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText10 = new wxStaticText( m_MySqlPanel, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer4->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txName = new wxTextCtrl( m_MySqlPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_txName, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText1 = new wxStaticText( m_MySqlPanel, wxID_ANY, wxT("Server:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer4->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txServer = new wxTextCtrl( m_MySqlPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer4->Add( m_txServer, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( m_MySqlPanel, wxID_ANY, wxT("User name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer4->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txUserName = new wxTextCtrl( m_MySqlPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer4->Add( m_txUserName, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText3 = new wxStaticText( m_MySqlPanel, wxID_ANY, wxT("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer4->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txPassword = new wxTextCtrl( m_MySqlPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), wxTE_PASSWORD );
	fgSizer4->Add( m_txPassword, 0, wxALL|wxEXPAND, 5 );
	
	sbSizer3->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	fgSizer3->Add( sbSizer3, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_MySqlPanel, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnOK = new wxButton( m_MySqlPanel, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnOK, 1, wxALL, 5 );
	
	m_btnCancel = new wxButton( m_MySqlPanel, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnCancel, 1, wxALL, 5 );
	
	m_btnSave = new wxButton( m_MySqlPanel, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnSave->SetToolTip( wxT("Invalide value in \"Name\".") );
	
	bSizer8->Add( m_btnSave, 1, wxALL, 5 );
	
	m_btnRemove = new wxButton( m_MySqlPanel, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnRemove, 1, wxALL, 5 );
	
	sbSizer4->Add( bSizer8, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizer3->Add( sbSizer4, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_listBox2 = new wxListBox( m_MySqlPanel, wxID_ANY, wxDefaultPosition, wxSize( -1,100 ), 0, NULL, 0 ); 
	fgSizer3->Add( m_listBox2, 1, wxALL|wxEXPAND, 5 );
	
	m_MySqlPanel->SetSizer( fgSizer3 );
	m_MySqlPanel->Layout();
	fgSizer3->Fit( m_MySqlPanel );
	m_notebook2->AddPage( m_MySqlPanel, wxT("MySql"), true );
	m_Sqlite = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer31;
	fgSizer31 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer31->AddGrowableCol( 0 );
	fgSizer31->AddGrowableCol( 1 );
	fgSizer31->AddGrowableRow( 0 );
	fgSizer31->SetFlexibleDirection( wxBOTH );
	fgSizer31->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer31;
	sbSizer31 = new wxStaticBoxSizer( new wxStaticBox( m_Sqlite, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer41;
	fgSizer41 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer41->AddGrowableCol( 1 );
	fgSizer41->AddGrowableRow( 1 );
	fgSizer41->SetFlexibleDirection( wxBOTH );
	fgSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText11 = new wxStaticText( m_Sqlite, wxID_ANY, wxT("Database file:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer41->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_filePickerSqlite = new wxFilePickerCtrl( m_Sqlite, wxID_ANY, wxT("/home/jankup/SourcesCpp/wxdbexplorer/build/gsdgsdg.sqlite"), wxT("Select a file"), wxT("Database file (*.sqlite)|*.sqlite"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	fgSizer41->Add( m_filePickerSqlite, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	sbSizer31->Add( fgSizer41, 1, wxEXPAND, 5 );
	
	fgSizer31->Add( sbSizer31, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( m_Sqlite, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnOKSqlite = new wxButton( m_Sqlite, wxID_Sqlite_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_btnOKSqlite, 1, wxALL, 5 );
	
	m_btnCancel1 = new wxButton( m_Sqlite, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_btnCancel1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer41->Add( bSizer81, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizer31->Add( sbSizer41, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_Sqlite->SetSizer( fgSizer31 );
	m_Sqlite->Layout();
	fgSizer31->Fit( m_Sqlite );
	m_notebook2->AddPage( m_Sqlite, wxT("Sqlite"), false );
	m_PostgrePanel = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer32;
	fgSizer32 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer32->SetFlexibleDirection( wxBOTH );
	fgSizer32->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer32;
	sbSizer32 = new wxStaticBoxSizer( new wxStaticBox( m_PostgrePanel, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer42;
	fgSizer42 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer42->AddGrowableCol( 1 );
	fgSizer42->SetFlexibleDirection( wxBOTH );
	fgSizer42->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText101 = new wxStaticText( m_PostgrePanel, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	fgSizer42->Add( m_staticText101, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txPgName = new wxTextCtrl( m_PostgrePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer42->Add( m_txPgName, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText12 = new wxStaticText( m_PostgrePanel, wxID_ANY, wxT("Server:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	fgSizer42->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txPgServer = new wxTextCtrl( m_PostgrePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer42->Add( m_txPgServer, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText21 = new wxStaticText( m_PostgrePanel, wxID_ANY, wxT("User name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer42->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txPgUserName = new wxTextCtrl( m_PostgrePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer42->Add( m_txPgUserName, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText31 = new wxStaticText( m_PostgrePanel, wxID_ANY, wxT("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer42->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txPgPassword = new wxTextCtrl( m_PostgrePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), wxTE_PASSWORD );
	fgSizer42->Add( m_txPgPassword, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText24 = new wxStaticText( m_PostgrePanel, wxID_ANY, wxT("Default database:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer42->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txPgDatabase = new wxTextCtrl( m_PostgrePanel, wxID_ANY, wxT("postgres"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer42->Add( m_txPgDatabase, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer32->Add( fgSizer42, 1, wxEXPAND, 5 );
	
	fgSizer32->Add( sbSizer32, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer42;
	sbSizer42 = new wxStaticBoxSizer( new wxStaticBox( m_PostgrePanel, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnPgOK = new wxButton( m_PostgrePanel, wxID_PG_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_btnPgOK, 1, wxALL, 5 );
	
	m_btnPgCancel = new wxButton( m_PostgrePanel, wxID_PG_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_btnPgCancel, 1, wxALL, 5 );
	
	m_btnPgSave = new wxButton( m_PostgrePanel, wxID_PG_SAVE, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnPgSave->SetToolTip( wxT("Invalide value in \"Name\".") );
	
	bSizer82->Add( m_btnPgSave, 1, wxALL, 5 );
	
	m_btnPgRemove = new wxButton( m_PostgrePanel, wxID_PG_REMOVE, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_btnPgRemove, 1, wxALL, 5 );
	
	sbSizer42->Add( bSizer82, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizer32->Add( sbSizer42, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_listBoxPg = new wxListBox( m_PostgrePanel, wxID_PG_LIST, wxDefaultPosition, wxSize( -1,100 ), 0, NULL, 0 ); 
	fgSizer32->Add( m_listBoxPg, 1, wxALL|wxEXPAND, 5 );
	
	m_PostgrePanel->SetSizer( fgSizer32 );
	m_PostgrePanel->Layout();
	fgSizer32->Fit( m_PostgrePanel );
	m_notebook2->AddPage( m_PostgrePanel, wxT("PostgreSQL"), false );
	
	bSizer4->Add( m_notebook2, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnOkClick ), NULL, this );
	m_btnOK->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnOKUI ), NULL, this );
	m_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnCancelClick ), NULL, this );
	m_btnSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnSaveClick ), NULL, this );
	m_btnSave->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnSaveUI ), NULL, this );
	m_btnRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnRemoveClick ), NULL, this );
	m_btnRemove->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnRmoveUI ), NULL, this );
	m_listBox2->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( _DBSettingsDialog::OnHistoryClick ), NULL, this );
	m_listBox2->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( _DBSettingsDialog::OnHistoryDClick ), NULL, this );
	m_listBox2->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnHistoruUI ), NULL, this );
	m_btnOKSqlite->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnSqliteOkClick ), NULL, this );
	m_btnCancel1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnCancelClick ), NULL, this );
	m_btnPgOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnPgOkClick ), NULL, this );
	m_btnPgOK->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnPgOKUI ), NULL, this );
	m_btnPgCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnPgCancelClick ), NULL, this );
	m_btnPgSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnPgSaveClick ), NULL, this );
	m_btnPgSave->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnPgSaveUI ), NULL, this );
	m_btnPgRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnPgRemoveClick ), NULL, this );
	m_btnPgRemove->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnPgRmoveUI ), NULL, this );
	m_listBoxPg->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( _DBSettingsDialog::OnPgHistoryClick ), NULL, this );
	m_listBoxPg->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( _DBSettingsDialog::OnPgHistoryDClick ), NULL, this );
	m_listBoxPg->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnHistoruUI ), NULL, this );
}

_DBSettingsDialog::~_DBSettingsDialog()
{
	// Disconnect Events
	m_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnOkClick ), NULL, this );
	m_btnOK->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnOKUI ), NULL, this );
	m_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnCancelClick ), NULL, this );
	m_btnSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnSaveClick ), NULL, this );
	m_btnSave->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnSaveUI ), NULL, this );
	m_btnRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnRemoveClick ), NULL, this );
	m_btnRemove->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnRmoveUI ), NULL, this );
	m_listBox2->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( _DBSettingsDialog::OnHistoryClick ), NULL, this );
	m_listBox2->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( _DBSettingsDialog::OnHistoryDClick ), NULL, this );
	m_listBox2->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnHistoruUI ), NULL, this );
	m_btnOKSqlite->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnSqliteOkClick ), NULL, this );
	m_btnCancel1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnCancelClick ), NULL, this );
	m_btnPgOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnPgOkClick ), NULL, this );
	m_btnPgOK->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnPgOKUI ), NULL, this );
	m_btnPgCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnPgCancelClick ), NULL, this );
	m_btnPgSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnPgSaveClick ), NULL, this );
	m_btnPgSave->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnPgSaveUI ), NULL, this );
	m_btnPgRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnPgRemoveClick ), NULL, this );
	m_btnPgRemove->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnPgRmoveUI ), NULL, this );
	m_listBoxPg->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( _DBSettingsDialog::OnPgHistoryClick ), NULL, this );
	m_listBoxPg->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( _DBSettingsDialog::OnPgHistoryDClick ), NULL, this );
	m_listBoxPg->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DBSettingsDialog::OnHistoruUI ), NULL, this );
	
}

_ErdPanel::_ErdPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer7->AddGrowableCol( 0 );
	fgSizer7->AddGrowableRow( 1 );
	fgSizer7->AddGrowableRow( 2 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_toolBarErd = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	m_toolBarErd->Realize(); 
	
	fgSizer7->Add( m_toolBarErd, 0, wxEXPAND, 5 );
	
	m_wxsfPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_wxsfSizer = new wxBoxSizer( wxVERTICAL );
	
	m_wxsfPanel->SetSizer( m_wxsfSizer );
	m_wxsfPanel->Layout();
	m_wxsfSizer->Fit( m_wxsfPanel );
	fgSizer7->Add( m_wxsfPanel, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	this->SetSizer( fgSizer7 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( _ErdPanel::OnMouseWheel ) );
}

_ErdPanel::~_ErdPanel()
{
	// Disconnect Events
	this->Disconnect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( _ErdPanel::OnMouseWheel ) );
	
}

_TableSettings::_TableSettings( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer9->AddGrowableRow( 1 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_panel7 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer10->SetFlexibleDirection( wxBOTH );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_panel8 = new wxPanel( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel8, wxID_ANY, wxEmptyString ), wxHORIZONTAL );
	
	m_staticText7 = new wxStaticText( m_panel8, wxID_ANY, wxT("Table name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	sbSizer5->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txTableName = new wxTextCtrl( m_panel8, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	sbSizer5->Add( m_txTableName, 1, wxALL, 5 );
	
	m_panel8->SetSizer( sbSizer5 );
	m_panel8->Layout();
	sbSizer5->Fit( m_panel8 );
	fgSizer10->Add( m_panel8, 1, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panel9 = new wxPanel( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel9, wxID_ANY, wxT("Columns") ), wxHORIZONTAL );
	
	m_panel13 = new wxPanel( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer11->AddGrowableRow( 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_listColumns = new wxListBox( m_panel13, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, 0 ); 
	fgSizer11->Add( m_listColumns, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_panel14 = new wxPanel( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button8 = new wxButton( m_panel14, wxID_NEW_COL, wxT("New column"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button8, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button15 = new wxButton( m_panel14, wxID_NEW_CONSTRAIN, wxT("New constraint"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button15, 0, wxALL, 5 );
	
	m_button10 = new wxButton( m_panel14, wxID_DEL, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button10, 0, wxALL, 5 );
	
	m_panel14->SetSizer( bSizer8 );
	m_panel14->Layout();
	bSizer8->Fit( m_panel14 );
	fgSizer11->Add( m_panel14, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_panel13->SetSizer( fgSizer11 );
	m_panel13->Layout();
	fgSizer11->Fit( m_panel13 );
	sbSizer6->Add( m_panel13, 1, wxEXPAND|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticline2 = new wxStaticLine( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizer6->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook3 = new wxNotebook( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_pageType = new wxPanel( m_notebook3, wxID_PAGE_TYPE, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText8 = new wxStaticText( m_pageType, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer7->Add( m_staticText8, 0, wxALL, 5 );
	
	m_txColName = new wxTextCtrl( m_pageType, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_txColName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText9 = new wxStaticText( m_pageType, wxID_ANY, wxT("Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer7->Add( m_staticText9, 0, wxALL, 5 );
	
	m_comboType = new wxComboBox( m_pageType, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer7->Add( m_comboType, 0, wxALL|wxEXPAND, 5 );
	
	m_stSize = new wxStaticText( m_pageType, wxID_ANY, wxT("Size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stSize->Wrap( -1 );
	bSizer7->Add( m_stSize, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer19->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( m_pageType, wxID_ANY, wxT("("), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer19->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txSize = new wxTextCtrl( m_pageType, wxID_TX_SIZE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	bSizer19->Add( m_txSize, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_staticText2511 = new wxStaticText( m_pageType, wxID_ANY, wxT(","), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2511->Wrap( -1 );
	bSizer19->Add( m_staticText2511, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txSize2 = new wxTextCtrl( m_pageType, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	bSizer19->Add( m_txSize2, 0, wxALL, 5 );
	
	m_staticText251 = new wxStaticText( m_pageType, wxID_ANY, wxT(")"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText251->Wrap( -1 );
	bSizer19->Add( m_staticText251, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer7->Add( bSizer19, 0, wxEXPAND|wxALIGN_RIGHT, 5 );
	
	m_chNotNull = new wxCheckBox( m_pageType, wxID_ANY, wxT("Not null"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_chNotNull, 0, wxALL, 5 );
	
	m_chAutoIncrement = new wxCheckBox( m_pageType, wxID_ANY, wxT("Auto increment"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_chAutoIncrement, 0, wxALL, 5 );
	
	m_pageType->SetSizer( bSizer7 );
	m_pageType->Layout();
	bSizer7->Fit( m_pageType );
	m_notebook3->AddPage( m_pageType, wxT("Column"), true );
	m_pageConstraint = new wxPanel( m_notebook3, wxID_PAGE_CONSTRAINT, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText11 = new wxStaticText( m_pageConstraint, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer11->Add( m_staticText11, 0, wxALL, 5 );
	
	m_txConstraintName = new wxTextCtrl( m_pageConstraint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_txConstraintName, 0, wxALL|wxALIGN_RIGHT|wxEXPAND, 5 );
	
	m_staticText12 = new wxStaticText( m_pageConstraint, wxID_ANY, wxT("Local column name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer11->Add( m_staticText12, 0, wxALL, 5 );
	
	m_comboLocalColumn = new wxComboBox( m_pageConstraint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY ); 
	bSizer11->Add( m_comboLocalColumn, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	wxString m_radioBox1Choices[] = { wxT("Primary key"), wxT("Foreign key") };
	int m_radioBox1NChoices = sizeof( m_radioBox1Choices ) / sizeof( wxString );
	m_radioBox1 = new wxRadioBox( m_pageConstraint, wxID_ANY, wxT("Constraint type:"), wxDefaultPosition, wxDefaultSize, m_radioBox1NChoices, m_radioBox1Choices, 1, 0 );
	m_radioBox1->SetSelection( 0 );
	bSizer11->Add( m_radioBox1, 0, wxALL|wxEXPAND, 5 );
	
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText13 = new wxStaticText( m_pageConstraint, wxID_ANY, wxT("Reference table:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	gbSizer2->Add( m_staticText13, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_comboRefTable = new wxComboBox( m_pageConstraint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY ); 
	gbSizer2->Add( m_comboRefTable, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticText14 = new wxStaticText( m_pageConstraint, wxID_ANY, wxT("Reference column:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	gbSizer2->Add( m_staticText14, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_comboRefColumn = new wxComboBox( m_pageConstraint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY ); 
	gbSizer2->Add( m_comboRefColumn, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString m_radioOnDeleteChoices[] = { wxT("restrict"), wxT("cascade"), wxT("set null"), wxT("no action") };
	int m_radioOnDeleteNChoices = sizeof( m_radioOnDeleteChoices ) / sizeof( wxString );
	m_radioOnDelete = new wxRadioBox( m_pageConstraint, wxID_ANY, wxT("OnDelete"), wxDefaultPosition, wxDefaultSize, m_radioOnDeleteNChoices, m_radioOnDeleteChoices, 1, wxRA_SPECIFY_COLS );
	m_radioOnDelete->SetSelection( 0 );
	gbSizer2->Add( m_radioOnDelete, wxGBPosition( 0, 1 ), wxGBSpan( 4, 1 ), wxALL|wxEXPAND, 5 );
	
	wxString m_radioOnUpdateChoices[] = { wxT("restrict"), wxT("cascade"), wxT("set null"), wxT("no action") };
	int m_radioOnUpdateNChoices = sizeof( m_radioOnUpdateChoices ) / sizeof( wxString );
	m_radioOnUpdate = new wxRadioBox( m_pageConstraint, wxID_ON_UPDATE, wxT("OnUpdate"), wxDefaultPosition, wxDefaultSize, m_radioOnUpdateNChoices, m_radioOnUpdateChoices, 1, wxRA_SPECIFY_COLS );
	m_radioOnUpdate->SetSelection( 0 );
	gbSizer2->Add( m_radioOnUpdate, wxGBPosition( 0, 2 ), wxGBSpan( 4, 1 ), wxALL|wxEXPAND|wxALIGN_RIGHT, 5 );
	
	bSizer11->Add( gbSizer2, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_pageConstraint->SetSizer( bSizer11 );
	m_pageConstraint->Layout();
	bSizer11->Fit( m_pageConstraint );
	m_notebook3->AddPage( m_pageConstraint, wxT("Constraint"), false );
	
	bSizer18->Add( m_notebook3, 1, wxEXPAND | wxALL, 5 );
	
	m_button9 = new wxButton( m_panel9, wxID_SAVE, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_button9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	sbSizer6->Add( bSizer18, 0, 0, 5 );
	
	m_panel9->SetSizer( sbSizer6 );
	m_panel9->Layout();
	sbSizer6->Fit( m_panel9 );
	fgSizer10->Add( m_panel9, 1, wxEXPAND | wxALL, 5 );
	
	m_panel7->SetSizer( fgSizer10 );
	m_panel7->Layout();
	fgSizer10->Fit( m_panel7 );
	fgSizer9->Add( m_panel7, 1, wxEXPAND | wxALL, 5 );
	
	m_sdbSizer2 = new wxStdDialogButtonSizer();
	m_sdbSizer2OK = new wxButton( this, wxID_OK );
	m_sdbSizer2->AddButton( m_sdbSizer2OK );
	m_sdbSizer2->Realize();
	fgSizer9->Add( m_sdbSizer2, 1, wxEXPAND|wxBOTTOM|wxRIGHT, 5 );
	
	this->SetSizer( fgSizer9 );
	this->Layout();
	fgSizer9->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_listColumns->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( _TableSettings::OnListBoxClick ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _TableSettings::OnNewColumnClick ), NULL, this );
	m_button15->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _TableSettings::OnNewConstrainClick ), NULL, this );
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _TableSettings::OnDeleteColumn ), NULL, this );
	m_notebook3->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnNotebookUI ), NULL, this );
	m_pageType->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnPageTypeUI ), NULL, this );
	m_txColName->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnColNameUI ), NULL, this );
	m_comboType->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( _TableSettings::OnTypeSelect ), NULL, this );
	m_comboType->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnColTypeUI ), NULL, this );
	m_txSize->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnColSizeUI ), NULL, this );
	m_txSize2->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnColSize2UI ), NULL, this );
	m_chNotNull->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnNotNullUI ), NULL, this );
	m_chAutoIncrement->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnAutoIncrementUI ), NULL, this );
	m_pageConstraint->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnPageConstraintUI ), NULL, this );
	m_comboRefTable->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( _TableSettings::OnRefTabChange ), NULL, this );
	m_comboRefTable->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnRefTabUI ), NULL, this );
	m_comboRefColumn->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnRefColUI ), NULL, this );
	m_radioOnDelete->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnDeleteUI ), NULL, this );
	m_radioOnUpdate->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnUpdateUI ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _TableSettings::OnSaveColumnClick ), NULL, this );
	m_sdbSizer2OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _TableSettings::OnOKClick ), NULL, this );
}

_TableSettings::~_TableSettings()
{
	// Disconnect Events
	m_listColumns->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( _TableSettings::OnListBoxClick ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _TableSettings::OnNewColumnClick ), NULL, this );
	m_button15->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _TableSettings::OnNewConstrainClick ), NULL, this );
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _TableSettings::OnDeleteColumn ), NULL, this );
	m_notebook3->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnNotebookUI ), NULL, this );
	m_pageType->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnPageTypeUI ), NULL, this );
	m_txColName->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnColNameUI ), NULL, this );
	m_comboType->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( _TableSettings::OnTypeSelect ), NULL, this );
	m_comboType->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnColTypeUI ), NULL, this );
	m_txSize->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnColSizeUI ), NULL, this );
	m_txSize2->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnColSize2UI ), NULL, this );
	m_chNotNull->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnNotNullUI ), NULL, this );
	m_chAutoIncrement->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnAutoIncrementUI ), NULL, this );
	m_pageConstraint->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnPageConstraintUI ), NULL, this );
	m_comboRefTable->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( _TableSettings::OnRefTabChange ), NULL, this );
	m_comboRefTable->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnRefTabUI ), NULL, this );
	m_comboRefColumn->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnRefColUI ), NULL, this );
	m_radioOnDelete->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnDeleteUI ), NULL, this );
	m_radioOnUpdate->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _TableSettings::OnUpdateUI ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _TableSettings::OnSaveColumnClick ), NULL, this );
	m_sdbSizer2OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _TableSettings::OnOKClick ), NULL, this );
	
}

_CreateForeignKey::_CreateForeignKey( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer12->AddGrowableCol( 0 );
	fgSizer12->AddGrowableCol( 2 );
	fgSizer12->AddGrowableRow( 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Referencing table:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	sbSizer7->Add( m_staticText15, 0, wxALL, 5 );
	
	m_txSrcTable = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), wxTE_READONLY );
	sbSizer7->Add( m_txSrcTable, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Column:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	sbSizer7->Add( m_staticText17, 0, wxALL, 5 );
	
	m_cmbSrcCol = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY ); 
	sbSizer7->Add( m_cmbSrcCol, 0, wxALL, 5 );
	
	fgSizer12->Add( sbSizer7, 1, wxEXPAND|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 0, 0 );
	gbSizer1->AddGrowableCol( 0 );
	gbSizer1->AddGrowableRow( 0 );
	gbSizer1->SetFlexibleDirection( wxVERTICAL );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString m_radioRelationChoices[] = { wxT("N :1"), wxT("N : M") };
	int m_radioRelationNChoices = sizeof( m_radioRelationChoices ) / sizeof( wxString );
	m_radioRelation = new wxRadioBox( this, wxID_ANY, wxT("Relation"), wxDefaultPosition, wxDefaultSize, m_radioRelationNChoices, m_radioRelationChoices, 1, wxRA_SPECIFY_ROWS );
	m_radioRelation->SetSelection( 0 );
	gbSizer1->Add( m_radioRelation, wxGBPosition( 0, 0 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxString m_radioOnDeleteChoices[] = { wxT("restrict"), wxT("cascade"), wxT("set null"), wxT("no action") };
	int m_radioOnDeleteNChoices = sizeof( m_radioOnDeleteChoices ) / sizeof( wxString );
	m_radioOnDelete = new wxRadioBox( this, wxID_ANY, wxT("OnDelete"), wxPoint( -1,-1 ), wxDefaultSize, m_radioOnDeleteNChoices, m_radioOnDeleteChoices, 1, wxRA_SPECIFY_COLS );
	m_radioOnDelete->SetSelection( 0 );
	gbSizer1->Add( m_radioOnDelete, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString m_radioOnUpdateChoices[] = { wxT("restrict"), wxT("cascade"), wxT("set null"), wxT("no action") };
	int m_radioOnUpdateNChoices = sizeof( m_radioOnUpdateChoices ) / sizeof( wxString );
	m_radioOnUpdate = new wxRadioBox( this, wxID_ANY, wxT("OnUpdate"), wxDefaultPosition, wxDefaultSize, m_radioOnUpdateNChoices, m_radioOnUpdateChoices, 1, wxRA_SPECIFY_COLS );
	m_radioOnUpdate->SetSelection( 0 );
	gbSizer1->Add( m_radioOnUpdate, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	fgSizer12->Add( gbSizer1, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Referenced table:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	sbSizer8->Add( m_staticText16, 0, wxALL, 5 );
	
	m_txDstTable = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), wxTE_READONLY );
	sbSizer8->Add( m_txDstTable, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Column:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	sbSizer8->Add( m_staticText18, 0, wxALL, 5 );
	
	m_cmbDstCol = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY ); 
	sbSizer8->Add( m_cmbDstCol, 0, wxALL, 5 );
	
	fgSizer12->Add( sbSizer8, 1, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	fgSizer12->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer12->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnCancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_btnCancel, 1, wxALL|wxEXPAND, 5 );
	
	m_btnOK = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_btnOK, 1, wxALL|wxEXPAND, 5 );
	
	fgSizer12->Add( bSizer12, 1, wxEXPAND|wxALIGN_RIGHT, 5 );
	
	this->SetSizer( fgSizer12 );
	this->Layout();
	fgSizer12->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _CreateForeignKey::OnCancelClick ), NULL, this );
	m_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _CreateForeignKey::OnOKClick ), NULL, this );
	m_btnOK->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _CreateForeignKey::OnOKUI ), NULL, this );
}

_CreateForeignKey::~_CreateForeignKey()
{
	// Disconnect Events
	m_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _CreateForeignKey::OnCancelClick ), NULL, this );
	m_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _CreateForeignKey::OnOKClick ), NULL, this );
	m_btnOK->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _CreateForeignKey::OnOKUI ), NULL, this );
	
}

_LogDialog::_LogDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 640,460 ), wxDefaultSize );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer13->AddGrowableCol( 0 );
	fgSizer13->AddGrowableRow( 0 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer13->SetMinSize( wxSize( 635,430 ) ); 
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Log") ), wxVERTICAL );
	
	m_textCtrl11 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 600,350 ), wxTE_MULTILINE|wxTE_READONLY );
	m_textCtrl11->SetMinSize( wxSize( 600,350 ) );
	
	sbSizer9->Add( m_textCtrl11, 1, wxALL|wxEXPAND, 5 );
	
	fgSizer13->Add( sbSizer9, 1, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	m_button18 = new wxButton( this, wxID_ANY, wxT("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_button18, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizer13->Add( bSizer13, 1, wxEXPAND|wxBOTTOM, 5 );
	
	this->SetSizer( fgSizer13 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button18->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _LogDialog::OnCloseClick ), NULL, this );
	m_button18->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _LogDialog::OnCloseUI ), NULL, this );
}

_LogDialog::~_LogDialog()
{
	// Disconnect Events
	m_button18->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _LogDialog::OnCloseClick ), NULL, this );
	m_button18->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _LogDialog::OnCloseUI ), NULL, this );
	
}

_ViewSettings::_ViewSettings( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 650,450 ), wxDefaultSize );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	bSizer15->SetMinSize( wxSize( 650,420 ) ); 
	wxStaticBoxSizer* sbSizer12;
	sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer14;
	fgSizer14 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer14->AddGrowableCol( 0 );
	fgSizer14->AddGrowableRow( 2 );
	fgSizer14->SetFlexibleDirection( wxBOTH );
	fgSizer14->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("View name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer14->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_txName, 1, wxALL, 5 );
	
	fgSizer14->Add( bSizer14, 1, wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer14->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	m_scintilla2 = new wxScintilla( this, wxID_ANY, wxDefaultPosition, wxSize( -1,300 ), 0, wxEmptyString );
	m_scintilla2->SetUseTabs( true );
	m_scintilla2->SetTabWidth( 4 );
	m_scintilla2->SetIndent( 4 );
	m_scintilla2->SetTabIndents( true );
	m_scintilla2->SetBackSpaceUnIndents( true );
	m_scintilla2->SetViewEOL( false );
	m_scintilla2->SetViewWhiteSpace( false );
	m_scintilla2->SetMarginWidth( 2, 0 );
	m_scintilla2->SetIndentationGuides( true );
	m_scintilla2->SetMarginType( 1, wxSCI_MARGIN_SYMBOL );
	m_scintilla2->SetMarginMask( 1, wxSCI_MASK_FOLDERS );
	m_scintilla2->SetMarginWidth( 1, 16);
	m_scintilla2->SetMarginSensitive( 1, true );
	m_scintilla2->SetProperty( wxT("fold"), wxT("1") );
	m_scintilla2->SetFoldFlags( wxSCI_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSCI_FOLDFLAG_LINEAFTER_CONTRACTED );
	m_scintilla2->SetMarginType( 0, wxSCI_MARGIN_NUMBER );
	m_scintilla2->SetMarginWidth( 0, m_scintilla2->TextWidth( wxSCI_STYLE_LINENUMBER, wxT("_99999") ) );
	m_scintilla2->MarkerDefine( wxSCI_MARKNUM_FOLDER, wxSCI_MARK_BOXPLUS );
	m_scintilla2->MarkerSetBackground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	m_scintilla2->MarkerSetForeground( wxSCI_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	m_scintilla2->MarkerDefine( wxSCI_MARKNUM_FOLDEROPEN, wxSCI_MARK_BOXMINUS );
	m_scintilla2->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	m_scintilla2->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	m_scintilla2->MarkerDefine( wxSCI_MARKNUM_FOLDERSUB, wxSCI_MARK_EMPTY );
	m_scintilla2->MarkerDefine( wxSCI_MARKNUM_FOLDEREND, wxSCI_MARK_BOXPLUS );
	m_scintilla2->MarkerSetBackground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	m_scintilla2->MarkerSetForeground( wxSCI_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	m_scintilla2->MarkerDefine( wxSCI_MARKNUM_FOLDEROPENMID, wxSCI_MARK_BOXMINUS );
	m_scintilla2->MarkerSetBackground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	m_scintilla2->MarkerSetForeground( wxSCI_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	m_scintilla2->MarkerDefine( wxSCI_MARKNUM_FOLDERMIDTAIL, wxSCI_MARK_EMPTY );
	m_scintilla2->MarkerDefine( wxSCI_MARKNUM_FOLDERTAIL, wxSCI_MARK_EMPTY );
	m_scintilla2->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_scintilla2->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	m_scintilla2->SetMinSize( wxSize( -1,300 ) );
	
	fgSizer14->Add( m_scintilla2, 1, wxEXPAND | wxALL, 5 );
	
	m_btnOK = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer14->Add( m_btnOK, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	sbSizer12->Add( fgSizer14, 1, wxEXPAND, 5 );
	
	bSizer15->Add( sbSizer12, 1, wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _ViewSettings::OnOKClick ), NULL, this );
}

_ViewSettings::~_ViewSettings()
{
	// Disconnect Events
	m_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _ViewSettings::OnOKClick ), NULL, this );
	
}

_ClassGenerateDialog::_ClassGenerateDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer19->SetFlexibleDirection( wxBOTH );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("Class prefix:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	fgSizer19->Add( m_staticText30, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txPrefix = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_txPrefix, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Class postfix:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer19->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txPostfix = new wxTextCtrl( this, wxID_ANY, wxT("Base"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_txPostfix, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Folder:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer19->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dirPicker1 = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	fgSizer19->Add( m_dirPicker1, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Log:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer19->Add( m_staticText29, 0, wxALL, 5 );
	
	m_textCtrl19 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,300 ), wxTE_MULTILINE|wxTE_READONLY );
	fgSizer19->Add( m_textCtrl19, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer19->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer22->Add( fgSizer19, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button25 = new wxButton( this, wxID_GENERATE, wxT("Generate"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button26 = new wxButton( this, wxID_CLOSE, wxT("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button26, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer22->Add( bSizer20, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer22 );
	this->Layout();
	bSizer22->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button25->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _ClassGenerateDialog::OnGenerateClick ), NULL, this );
	m_button26->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _ClassGenerateDialog::OnCancelClick ), NULL, this );
}

_ClassGenerateDialog::~_ClassGenerateDialog()
{
	// Disconnect Events
	m_button25->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _ClassGenerateDialog::OnGenerateClick ), NULL, this );
	m_button26->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _ClassGenerateDialog::OnCancelClick ), NULL, this );
	
}
