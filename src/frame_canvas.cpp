#include "frame_canvas.h"
#include "erd_table.h"

FrameCanvas::FrameCanvas(wxSFDiagramManager* manager,IDbAdapter* dbAdapter, wxWindow* parent, wxPanel* parentPanel, wxWindowID id):
	wxSFShapeCanvas(manager,parent,id, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL | wxSTATIC_BORDER) {
	m_pParentPanel = (ErdPanel*) parentPanel;

	m_pDbAdapter = dbAdapter;

	AddStyle(sfsGRID_USE);
	AddStyle(sfsGRID_SHOW);

	GetDiagramManager()->ClearAcceptedShapes();
	GetDiagramManager()->AcceptShape(wxT("All"));

}

FrameCanvas::~FrameCanvas() {
}

void FrameCanvas::OnConnectionFinished(wxSFLineShape* connection) {
}

void FrameCanvas::OnLeftDown(wxMouseEvent& event) {
	wxSFShapeBase* pShape;

	switch(m_pParentPanel->GetToolMode()) {

	case ErdPanel::modeTABLE: {
		pShape = GetDiagramManager()->AddShape(new ErdTable(), NULL, event.GetPosition(), sfINITIALIZE, sfDONT_SAVE_STATE);
		//pShape = GetDiagramManager()->AddShape(CLASSINFO(wxSFRoundRectShape), event.GetPosition(), sfDONT_SAVE_STATE);
		if (pShape) {
			pShape->AcceptConnection(wxT("All"));
			pShape->AcceptSrcNeighbour(wxT("All"));
			pShape->AcceptTrgNeighbour(wxT("All"));
		}
	}
	break;
	default:

		ErdTable* table = wxDynamicCast(GetShapeUnderCursor(),ErdTable);
		if (table) {
			m_pParentPanel->UpdateDetail(table);
		} else {
			m_pParentPanel->UpdateDetail(NULL);
		}
		// do default actions
		wxSFShapeCanvas::OnLeftDown(event);
	}
	if( pShape ) {
		if(!event.ControlDown()) {
			m_pParentPanel->SetToolMode(ErdPanel::modeDESIGN);
		}
	}

}
void FrameCanvas::OnRightDown(wxMouseEvent& event) {
	ErdTable* table = (ErdTable*) GetShapeUnderCursor();
	if (table) {
		//void *data = reinterpret_cast<void *>(event.GetItem().GetData());
		wxMenu mnu;
		//mnu.SetClientData( data );
		mnu.Append(IDR_POPUP_MI1, 	wxT("Add column"));
		mnu.Append(IDR_POPUP_MI2, 	wxT("Add create sql to clippoard"));
		mnu.Connect(wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&FrameCanvas::OnPopupClick, NULL, this);
		PopupMenu(&mnu);
	}
}


void FrameCanvas::OnKeyDown(wxKeyEvent& event) {
	wxSFShapeCanvas::OnKeyDown(event);
}

void FrameCanvas::OnPopupClick(wxCommandEvent &evt) {
	void *data=static_cast<wxMenu *>(evt.GetEventObject())->GetClientData();
	switch(evt.GetId()) {
	case IDR_POPUP_MI1: {
		//ErdTable* table = wxDynamicCast(GetShapeUnderCursor(),ErdTable);

		ErdTable* table = wxDynamicCast(GetShapeUnderCursor()->GetGrandParentShape(), ErdTable);
		if (table) {
			table->addColumn(wxT("NewCol"),m_pDbAdapter->GetDbTypeByName(wxT("VARCHAR")));
			table->addColumn(wxT("NewColInt"),m_pDbAdapter->GetDbTypeByName(wxT("INT")));			
			table->updateColumns();
			wxMessageBox(wxT("Column added!"));
		}
	}
	break;
	case IDR_POPUP_MI2: {
		if (wxTheClipboard->Open()) {
			ErdTable* table = wxDynamicCast(GetShapeUnderCursor()->GetGrandParentShape(), ErdTable);
			if (table) {
				wxTheClipboard->SetData(new wxTextDataObject(MySqlDbAdapter::GetCreateTableSql(table->getTable())));
				wxTheClipboard->Close();
			}
		}
	}
	break;
	}
}
void FrameCanvas::OnLeftDoubleClick(wxMouseEvent& event) {
	wxSFShapeBase* sp = GetShapeUnderCursor();
	if (sp){
		ErdTable* table = wxDynamicCast(sp->GetGrandParentShape(),ErdTable);
		if (table && table->getTable() ) {
			TableSettings settingDialog(this);
			settingDialog.SetTable(table->getTable());
			settingDialog.ShowModal();	
			}
	}
}
