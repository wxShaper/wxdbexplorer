#include "ErdPanel.h"

BEGIN_EVENT_TABLE(ErdPanel, _ErdPanel)
	EVT_MENU(wxID_OPEN, ErdPanel::OnLoad)
	EVT_MENU(wxID_SAVE, ErdPanel::OnSave)
	EVT_MENU(IDS_ERD_SAVE_SQL, ErdPanel::OnSaveSql)
	EVT_TOOL_RANGE(IDT_ERD_FIRST, IDT_ERD_LAST, ErdPanel::OnTool)
	EVT_UPDATE_UI_RANGE(IDT_ERD_FIRST, IDT_ERD_LAST, ErdPanel::OnToolUpdate)
END_EVENT_TABLE()

ErdPanel::ErdPanel(wxWindow *parent, IDbAdapter* dbAdapter):_ErdPanel(parent) {
	m_pErdTable = NULL;
	m_pDbAdapter = dbAdapter;
    Init(parent, dbAdapter);


}
ErdPanel::ErdPanel(wxWindow* parent, IDbAdapter* dbAdapter, Table* pTable):_ErdPanel(parent) 
{
	m_pErdTable = NULL;
	m_pDbAdapter = dbAdapter;
	Init(parent, dbAdapter);
	if (pTable){
		ErdTable* pErdTab = new ErdTable(pTable);
		pErdTab->updateColumns();		
		pErdTab->Refresh();
		m_diagramManager.AddShape(pErdTab, NULL, wxPoint( 10,10), sfINITIALIZE, sfDONT_SAVE_STATE);
		}
}

ErdPanel::ErdPanel(wxWindow* parent, IDbAdapter* dbAdapter, xsSerializable* pItems):_ErdPanel(parent) 
{
	m_pErdTable = NULL;
	m_pDbAdapter = dbAdapter;
	Init(parent, dbAdapter);
	int i = 10;
	SerializableList::compatibility_iterator node = pItems->GetFirstChildNode();
	while( node ){
		Table* pTable = wxDynamicCast(node->GetData(), Table);
		if( pTable ) {
			ErdTable* pErdTab = new ErdTable(pTable);
			pErdTab->updateColumns();		
			pErdTab->Refresh();
			m_diagramManager.AddShape(pErdTab, NULL, wxPoint( i ,10), sfINITIALIZE, sfDONT_SAVE_STATE);
			i+= 200;
			}
		node = node->GetNext();
		}	
}

ErdPanel::~ErdPanel() {
	// delete
}


void ErdPanel::Init(wxWindow* parent, IDbAdapter* dbAdapter)
{
	m_pFrameCanvas = new FrameCanvas(&m_diagramManager,dbAdapter,m_wxsfPanel,this, wxID_ANY);
	m_wxsfSizer->Add(m_pFrameCanvas,  1, wxEXPAND, 2);
	m_wxsfPanel->Layout();


	m_toolBarErd->SetToolBitmapSize(wxSize(16, 15));
	m_toolBarErd->AddTool(wxID_OPEN, wxT("Open"), wxBitmap(fileopen_xpm),  wxT("Open diagram"));
	m_toolBarErd->AddTool(wxID_SAVE, wxT("Save"), wxBitmap(filesave_xpm),  wxT("Save diagram"));
	m_toolBarErd->AddTool(IDS_ERD_SAVE_SQL, wxT("Save SQL"), wxBitmap(filesavesql_xpm),wxT("Save SQL"));
	m_toolBarErd->AddSeparator();
	m_toolBarErd->AddRadioTool(IDT_ERD_TOOL, wxT("Tool"), wxBitmap(Tool_xpm), wxNullBitmap, wxT("Design tool"));
	m_toolBarErd->AddRadioTool(IDT_ERD_TABLE, wxT("Table"), wxBitmap(Grid_xpm),wxNullBitmap, wxT("Database table"));
	m_toolBarErd->AddRadioTool(IDT_ERD_LINE, wxT("Constraint 1:N"), wxBitmap(link_editor_xpm),wxNullBitmap, wxT("Foreign key connection"));
	
	m_toolBarErd->AddSeparator();
	m_toolBarErd->Realize();
}

void ErdPanel::OnTool(wxCommandEvent& event) {
	switch(event.GetId()) {
	case IDT_ERD_TOOL:
		m_nToolMode = modeDESIGN;
		break;
	case IDT_ERD_TABLE:
		m_nToolMode = modeTABLE;
		break;
	case IDT_ERD_LINE:
		m_nToolMode = modeLine;
	}

}
void ErdPanel::OnToolUpdate(wxUpdateUIEvent& event) {
	switch(event.GetId()) {
	case IDT_ERD_TOOL:
		event.Check(m_nToolMode == modeDESIGN);
		break;
	case IDT_ERD_TABLE:
		event.Check(m_nToolMode == modeTABLE);
		break;
	case IDT_ERD_LINE:
		event.Check(m_nToolMode == modeLine);
	default:
		event.Skip();
		break;

	}

}
void ErdPanel::OnLoad(wxCommandEvent& WXUNUSED(event)) {
	wxFileDialog dlg(this, wxT("Load canvas from XML..."), wxGetCwd(), wxT(""), wxT("XML Files (*.xml)|*.xml"), wxOPEN | wxFD_FILE_MUST_EXIST);

	if(dlg.ShowModal() == wxID_OK) {
		m_pFrameCanvas->LoadCanvas(dlg.GetPath());
	}
}

void ErdPanel::OnSave(wxCommandEvent& WXUNUSED(event)) {
	wxFileDialog dlg(this, wxT("Save canvas to XML..."), wxGetCwd(), wxT(""), wxT("XML Files (*.xml)|*.xml"), wxSAVE | wxFD_OVERWRITE_PROMPT);

	if(dlg.ShowModal() == wxID_OK) {
		m_pFrameCanvas->SaveCanvas(dlg.GetPath());

		wxMessageBox(wxString::Format(wxT("The chart has been saved to '%s'."), dlg.GetPath().GetData()), wxT("ShapeFramework"));
	}
}


wxSFShapeCanvas* ErdPanel::getCanvas()
{	
	return m_pFrameCanvas;
}

void ErdPanel::OnSaveSql(wxCommandEvent& event)
{
	wxFileDialog dlg(this, wxT("Save SQL create query..."), wxGetCwd(), wxT(""), wxT("SQL Files (*.sql)|*.sql"), wxSAVE | wxFD_OVERWRITE_PROMPT);

	if(dlg.ShowModal() == wxID_OK) {
		wxTextFile file(dlg.GetPath());
		if (!file.Exists()) file.Create();
		file.Open();
		if (file.IsOpened()){
			file.Clear();
			file.AddLine(wxT("-- SQL script created by DatabaseExplorer "));
			file.AddLine(wxT(""));
			file.AddLine(m_pFrameCanvas->GetSqlScript());	
			file.Write();
			file.Close();
			}			
		wxMessageBox(wxString::Format(wxT("The chart has been saved to '%s'."), dlg.GetPath().GetData()), wxT("ShapeFramework"));
	}
}




