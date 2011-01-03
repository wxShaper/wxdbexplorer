#include "frame_canvas.h"
#include "erd_table.h"

FrameCanvas::FrameCanvas(wxSFDiagramManager* manager, wxWindow* parent, wxPanel* parentPanel, wxWindowID id):
	wxSFShapeCanvas(manager,parent,id, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL | wxSTATIC_BORDER) {
	m_pParentPanel = (ErdPanel*) parentPanel;

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

	case ErdPanel::modeTABLE:
		{
			pShape = GetDiagramManager()->AddShape(new ErdTable(), NULL, event.GetPosition(), sfINITIALIZE, sfDONT_SAVE_STATE);
			//pShape = GetDiagramManager()->AddShape(CLASSINFO(wxSFRoundRectShape), event.GetPosition(), sfDONT_SAVE_STATE);
			if (pShape){
				pShape->AcceptConnection(wxT("All"));
				pShape->AcceptSrcNeighbour(wxT("All"));
				pShape->AcceptTrgNeighbour(wxT("All"));			
				}
		}	
		break;
	default:
	
		ErdTable* table = wxDynamicCast(GetShapeUnderCursor(),ErdTable);
		if (table){
			m_pParentPanel->UpdateDetail(table);			
			}else{
			m_pParentPanel->UpdateDetail(NULL);			
			}
	
		// do default actions
		wxSFShapeCanvas::OnLeftDown(event);
	}
	if( pShape )
	{
        if(!event.ControlDown())
        {
            m_pParentPanel->SetToolMode(ErdPanel::modeDESIGN);
        }
	}

}
void FrameCanvas::OnRightDown(wxMouseEvent& event) {
	ErdTable* table = (ErdTable*) GetShapeUnderCursor();
		if (table){
			//void *data = reinterpret_cast<void *>(event.GetItem().GetData());
			wxMenu mnu;
			//mnu.SetClientData( data );
			mnu.Append(IDR_POPUP_MI1, 	wxT("Do something"));
			mnu.Append(IDR_POPUP_MI2, 	wxT("Do something else"));
	//mnu.Connect(wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&MyFrame::OnPopupClick, NULL, this);
			PopupMenu(&mnu);		
			}
}


void FrameCanvas::OnKeyDown(wxKeyEvent& event) {
	wxSFShapeCanvas::OnKeyDown(event);
}
