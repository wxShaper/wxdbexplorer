///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov 18 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

#include "../res/elements/Bound.xpm"
#include "../res/gui/fileopen.xpm"
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

_SqlCommandPanel::_SqlCommandPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer3->AddGrowableCol( 0 );
	fgSizer3->AddGrowableRow( 0 );
	fgSizer3->AddGrowableRow( 2 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_scintillaSQL = new wxScintilla( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0, wxEmptyString );
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
	
	fgSizer3->Add( m_scintillaSQL, 1, wxEXPAND, 5 );
	
	m_panel3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
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
	fgSizer3->Add( m_panel3, 0, wxEXPAND, 5 );
	
	m_gridTable = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gridTable->CreateGrid( 5, 5 );
	m_gridTable->EnableEditing( true );
	m_gridTable->EnableGridLines( true );
	m_gridTable->EnableDragGridSize( false );
	m_gridTable->SetMargins( 0, 0 );
	
	// Columns
	m_gridTable->EnableDragColMove( false );
	m_gridTable->EnableDragColSize( true );
	m_gridTable->SetColLabelSize( 30 );
	m_gridTable->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridTable->EnableDragRowSize( true );
	m_gridTable->SetRowLabelSize( 80 );
	m_gridTable->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridTable->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer3->Add( m_gridTable, 1, wxEXPAND, 5 );
	
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

_DbViewerPanel::_DbViewerPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook2 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel2 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_toolBar1 = new wxToolBar( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( fileopen_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	m_toolBar1->AddTool( wxID_TOOL_REFRESH, wxT("tool"), wxBitmap( refresh_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	m_toolBar1->AddTool( wxID_TOOL_ERD, wxT("ERD"), wxBitmap( Bound_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	m_toolBar1->Realize(); 
	
	bSizer4->Add( m_toolBar1, 0, wxEXPAND, 5 );
	
	m_treeDatabases = new wxTreeCtrl( m_panel2, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTR_DEFAULT_STYLE );
	bSizer4->Add( m_treeDatabases, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer4->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_propertyGrid = new wxPropertyGrid(m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE);
	bSizer4->Add( m_propertyGrid, 1, wxEXPAND, 5 );
	
	m_panel2->SetSizer( bSizer4 );
	m_panel2->Layout();
	bSizer4->Fit( m_panel2 );
	m_notebook2->AddPage( m_panel2, wxT("Databases"), false );
	
	bSizer2->Add( m_notebook2, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxID_ANY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnConncectClick ) );
	this->Connect( wxID_ANY, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DbViewerPanel::OnConncectUI ) );
	this->Connect( wxID_TOOL_REFRESH, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnRefreshClick ) );
	this->Connect( wxID_TOOL_ERD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnERDClick ) );
	m_treeDatabases->Connect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( _DbViewerPanel::OnItemActivate ), NULL, this );
	m_treeDatabases->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( _DbViewerPanel::OnItemSelectionChange ), NULL, this );
}

_DbViewerPanel::~_DbViewerPanel()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnConncectClick ) );
	this->Disconnect( wxID_ANY, wxEVT_UPDATE_UI, wxUpdateUIEventHandler( _DbViewerPanel::OnConncectUI ) );
	this->Disconnect( wxID_TOOL_REFRESH, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnRefreshClick ) );
	this->Disconnect( wxID_TOOL_ERD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( _DbViewerPanel::OnERDClick ) );
	m_treeDatabases->Disconnect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( _DbViewerPanel::OnItemActivate ), NULL, this );
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
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_MySqlPanel, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( m_MySqlPanel, wxID_ANY, wxT("Server:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer4->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txServer = new wxTextCtrl( m_MySqlPanel, wxID_ANY, wxT("localhost"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer4->Add( m_txServer, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( m_MySqlPanel, wxID_ANY, wxT("User name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer4->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txUserName = new wxTextCtrl( m_MySqlPanel, wxID_ANY, wxT("root"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	fgSizer4->Add( m_txUserName, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( m_MySqlPanel, wxID_ANY, wxT("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer4->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txPassword = new wxTextCtrl( m_MySqlPanel, wxID_ANY, wxT("madoma"), wxDefaultPosition, wxSize( 150,-1 ), wxTE_PASSWORD );
	fgSizer4->Add( m_txPassword, 0, wxALL, 5 );
	
	sbSizer3->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	fgSizer3->Add( sbSizer3, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_MySqlPanel, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnOK = new wxButton( m_MySqlPanel, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnOK, 1, wxALL, 5 );
	
	m_btnCancel = new wxButton( m_MySqlPanel, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btnCancel, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer4->Add( bSizer8, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizer3->Add( sbSizer4, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_MySqlPanel->SetSizer( fgSizer3 );
	m_MySqlPanel->Layout();
	fgSizer3->Fit( m_MySqlPanel );
	m_notebook2->AddPage( m_MySqlPanel, wxT("MySql"), false );
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
	fgSizer41->AddGrowableRow( 0 );
	fgSizer41->SetFlexibleDirection( wxBOTH );
	fgSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText11 = new wxStaticText( m_Sqlite, wxID_ANY, wxT("Database file:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer41->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_filePickerSqlite = new wxFilePickerCtrl( m_Sqlite, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("Database file (*.sqlite)|*.sqlite"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE|wxFLP_USE_TEXTCTRL );
	fgSizer41->Add( m_filePickerSqlite, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
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
	m_notebook2->AddPage( m_Sqlite, wxT("Sqlite"), true );
	
	bSizer4->Add( m_notebook2, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnOkClick ), NULL, this );
	m_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnCancelClick ), NULL, this );
	m_btnOKSqlite->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnSqliteOkClick ), NULL, this );
	m_btnCancel1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnCancelClick ), NULL, this );
}

_DBSettingsDialog::~_DBSettingsDialog()
{
	// Disconnect Events
	m_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnOkClick ), NULL, this );
	m_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnCancelClick ), NULL, this );
	m_btnOKSqlite->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnSqliteOkClick ), NULL, this );
	m_btnCancel1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _DBSettingsDialog::OnCancelClick ), NULL, this );
	
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
	
	m_notebook3 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_nbMainPanel = new wxPanel( m_notebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText6 = new wxStaticText( m_nbMainPanel, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer8->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_txName = new wxTextCtrl( m_nbMainPanel, wxID_TX_NAME, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer8->Add( m_txName, 0, wxALL, 5 );
	
	m_nbMainPanel->SetSizer( fgSizer8 );
	m_nbMainPanel->Layout();
	fgSizer8->Fit( m_nbMainPanel );
	m_notebook3->AddPage( m_nbMainPanel, wxT("Main info"), false );
	
	fgSizer7->Add( m_notebook3, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( fgSizer7 );
	this->Layout();
	
	// Connect Events
	m_txName->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( _ErdPanel::OnTxNameChange ), NULL, this );
}

_ErdPanel::~_ErdPanel()
{
	// Disconnect Events
	m_txName->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( _ErdPanel::OnTxNameChange ), NULL, this );
	
}
