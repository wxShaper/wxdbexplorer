#include "ErdView.h"

XS_IMPLEMENT_CLONABLE_CLASS(ErdView,wxSFRoundRectShape);

ErdView::ErdView():wxSFRoundRectShape()
{
	Initialize();
}
ErdView::ErdView(View* pView):wxSFRoundRectShape()
{
	SetUserData(pView);
	Initialize();
}

ErdView::ErdView(const ErdView& obj):wxSFRoundRectShape(obj)
{
	m_pLabel = (wxSFTextShape*) obj.m_pLabel->Clone();
	if (m_pLabel){
		m_pLabel->SetStyle(sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION);
		SF_ADD_COMPONENT( m_pLabel, wxT("title") );	
		XS_SERIALIZE_DYNAMIC_OBJECT_NO_CREATE(m_pLabel, wxT("TableNameLabel"));	
		}
}

ErdView::~ErdView()
{
}

void ErdView::DrawHover(wxDC& dc)
{
	wxSFRoundRectShape::DrawHover(dc);
}
void ErdView::DrawNormal(wxDC& dc)
{
	wxSFRoundRectShape::DrawNormal(dc);
}

void ErdView::DrawHighlighted(wxDC& dc)
{
	wxSFRoundRectShape::DrawHighlighted(dc);
}


void ErdView::Initialize()
{
	SetFill(wxBrush(wxColour(216, 227,230)));
	AcceptConnection(wxT("All"));
	AcceptTrgNeighbour(wxT("All"));
	AcceptSrcNeighbour(wxT("All"));
	
	m_pLabel = new wxSFTextShape();
	if (m_pLabel) {
		m_pLabel->SetVAlign(wxSFShapeBase::valignTOP);
        m_pLabel->SetHAlign(wxSFShapeBase::halignEXPAND);
        m_pLabel->SetVBorder(5);
		m_pLabel->SetHBorder(5);
		m_pLabel->GetFont().SetWeight(wxFONTWEIGHT_BOLD);

		m_pLabel->SetText(wxT("Table name"));
		m_pLabel->SetStyle( sfsHOVERING | sfsALWAYS_INSIDE | sfsPROCESS_DEL | sfsEMIT_EVENTS |sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION);

		//XS_SERIALIZE_DYNAMIC_OBJECT_NO_CREATE(m_pLabel, wxT("TableNameLabel"));
		
        SF_ADD_COMPONENT( m_pLabel, wxT("title") );		
		
		}
	m_pGrid = new wxSFFlexGridShape();
	if (m_pGrid){
		//XS_SERIALIZE_DYNAMIC_OBJECT_NO_CREATE(m_pLabel, wxT("TableNameLabel"));
		
				// set grid
		m_pGrid->SetRelativePosition( 20, 30 );
		m_pGrid->SetStyle( sfsALWAYS_INSIDE | sfsPROCESS_DEL |sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION  );
		m_pGrid->SetDimensions( 1, 1 );
		
		m_pGrid->SetFill( *wxTRANSPARENT_BRUSH );
		m_pGrid->SetBorder( *wxTRANSPARENT_PEN );
		
		m_pGrid->SetHAlign( wxSFShapeBase::halignEXPAND );
		m_pGrid->SetCellSpace( 1 );
		m_pGrid->SetVBorder(2);
		m_pGrid->SetHBorder(2);
		m_pGrid->AcceptChild( wxT("wxSFTextShape") );
		m_pGrid->Activate(false);
		
		
        SF_ADD_COMPONENT( m_pGrid, wxT("SelectGrid") );		

		
		}
}

void ErdView::UpdateView()
{
	m_pGrid->GetChildrenList().DeleteContents(true);
	m_pGrid->GetChildrenList().Clear();
	View* pView = wxDynamicCast(GetUserData(), View);
	if (pView){
		m_pLabel->SetText(pView->GetName());
		//m_pSelect->SetText(pView->GetSelect());		
		

		wxSFTextShape* m_pCol = new wxSFTextShape();
		if (m_pCol){	
			m_pCol->SetStyle(sfsHOVERING |sfsEMIT_EVENTS| sfsALWAYS_INSIDE | sfsSIZE_CHANGE | sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION );
			//m_pCol->SetId(1);
			if (m_pGrid->AppendToGrid(m_pCol)){
				
				if (pView->GetSelect().length()>100){					
					m_pCol->SetText(wxString::Format(wxT("%s  ...\n\t... %s"), pView->GetSelect().Mid(0,50).c_str(), pView->GetSelect().Right(50).c_str()));
					}else m_pCol->SetText( pView->GetSelect() );			
				m_pCol->SetHAlign(wxSFShapeBase::halignEXPAND);
				m_pCol->SetVAlign(wxSFShapeBase::valignEXPAND);
				//	m_pLabel->SetVAlign(wxSFShapeBase::valignTOP);
				//m_pLabel->SetHAlign(wxSFShapeBase::halignCENTER);
				m_pCol->SetVBorder(0);
				m_pCol->SetHBorder(2);
				m_pCol->GetFont().SetPointSize(9);
				m_pCol->Activate(false);
				
				//m_pCol->SetCustomDockPoint(wxSFConnectionPoint::cpCENTERLEFT | wxSFConnectionPoint::cpCENTERRIGHT );
							
			}else{			
				delete m_pCol;
				m_pCol = NULL;			
				m_pGrid->Update();
				
				}
			}	
		
		}
		
		
		
		
		
		
		
		
		
	m_pLabel->Update();
	Update();
	Refresh();
}


