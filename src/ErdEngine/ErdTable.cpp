#include "ErdTable.h"
#include "wx/wxsf/CommonFcn.h"
#include "wx/wxsf/ShapeCanvas.h"

#include <wx/recguard.h>

using namespace wxSFCommonFcn;

#define constOffset MAX_ID

XS_IMPLEMENT_CLONABLE_CLASS(ErdTable,wxSFRoundRectShape);

ErdTable::ErdTable():wxSFRoundRectShape()
{
	Initialize();
}

ErdTable::ErdTable(Table* tab):wxSFRoundRectShape()
{
	SetUserData(tab);
	Initialize();
}

ErdTable::ErdTable(const ErdTable& obj):wxSFRoundRectShape(obj)
{

	m_pLabel = (wxSFTextShape*) obj.m_pLabel->Clone();
	if (m_pLabel){
		m_pLabel->SetStyle(sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION);
		SF_ADD_COMPONENT( m_pLabel, wxT("title") );	
	}
}

ErdTable::~ErdTable()
{
}

void ErdTable::Initialize()
{
	SetFill(wxBrush(wxColour(254, 253, 211)));
	
	AcceptConnection(wxT("All"));
	AcceptTrgNeighbour(wxT("All"));
	AcceptSrcNeighbour(wxT("All"));
	
	AddStyle( sfsLOCK_CHILDREN );
	AddStyle( sfsSHOW_SHADOW );
	
	SetBorder( wxPen( wxColour(70, 125, 170), 1, wxSOLID ) );
	SetFill( wxBrush( wxColour(210, 225, 245) ) );
	
	SetRadius(15);
	
	m_pLabel = new wxSFTextShape();
	m_pGrid = new wxSFFlexGridShape();
	
	if (m_pLabel && m_pGrid){
		m_pLabel->SetVAlign(wxSFShapeBase::valignTOP);
        m_pLabel->SetHAlign(wxSFShapeBase::halignCENTER);
        m_pLabel->SetVBorder(1);
		m_pLabel->SetHBorder(5);
		
		m_pLabel->GetFont().SetPointSize( 8 );
		m_pLabel->GetFont().SetWeight(wxFONTWEIGHT_BOLD);

		m_pLabel->SetText(wxT("Table name"));
		m_pLabel->SetStyle( sfsHOVERING | sfsALWAYS_INSIDE | sfsPROCESS_DEL | sfsEMIT_EVENTS |sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION );

        SF_ADD_COMPONENT( m_pLabel, wxT("title") );		
		
		// set grid
		m_pGrid->SetRelativePosition( 0, 17 );
		m_pGrid->SetStyle( sfsALWAYS_INSIDE | sfsPROCESS_DEL |sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION  );
		m_pGrid->SetDimensions( 1, 1 );
		
		m_pGrid->SetFill( *wxTRANSPARENT_BRUSH );
		m_pGrid->SetBorder( *wxTRANSPARENT_PEN);
		
		m_pGrid->SetHAlign( wxSFShapeBase::halignLEFT );
		m_pGrid->SetVBorder( 13 );
		m_pGrid->SetHBorder( 10 );
		m_pGrid->AcceptChild( wxT("wxSFTextShape") );
		m_pGrid->Activate( false );
		
		SF_ADD_COMPONENT( m_pGrid, wxT("main_grid") );
	}
}

void ErdTable::DrawHighlighted(wxDC& dc)
{
	wxSFRoundRectShape::DrawHighlighted(dc);
	DrawDetails(dc);
}

void ErdTable::DrawDetails(wxDC& dc)
{
	dc.SetPen( *wxWHITE_PEN );
	dc.SetBrush( *wxWHITE_BRUSH );
	
	dc.DrawRectangle( Conv2Point(GetAbsolutePosition() + wxRealPoint(1, m_nRadius)),
					  Conv2Size(m_nRectSize - wxRealPoint(2, 2*m_nRadius - 4)) );
}

void ErdTable::DrawHover(wxDC& dc)
{
	wxSFRoundRectShape::DrawHover(dc);
	DrawDetails(dc);
}

void ErdTable::DrawNormal(wxDC& dc)
{
	wxSFRoundRectShape::DrawNormal(dc);
	DrawDetails(dc);
}

void ErdTable::UpdateColumns()
{	
	ClearGrid();
	ClearConnections();
	
	SetRectSize(GetRectSize().x, 0);
	
	ShapeList list;
	if (GetShapeManager()){
		GetShapeManager()->GetShapes(CLASSINFO(ErdTable), list);
		}
	
	int i = 0;
	
	Table* tab = (Table*) wxDynamicCast(GetUserData(),Table);
	if (tab){		
		m_pLabel->SetText(tab->GetName());
		SerializableList::compatibility_iterator node = tab->GetFirstChildNode();
		while( node ){
			Column* pCol = wxDynamicCast(node->GetData(), Column);
			if( pCol ) {
				wxString prefix = wxT("\t");
				
				SerializableList::compatibility_iterator cstrNode = tab->GetFirstChildNode();
				while( cstrNode ){
					Constraint* constr = wxDynamicCast(cstrNode->GetData(), Constraint);
					if (constr){
						if (constr->GetLocalColumn() == pCol->GetName()) prefix = wxT("KEY:");
						}
					cstrNode = cstrNode->GetNext();
					}
				
				
				
				 AddColumnShape(wxString::Format(wxT("%s%s"),prefix.c_str(),pCol->GetName().c_str()),i++);
				
				
				
				}
			node = node->GetNext();
			}		
			
		node = tab->GetFirstChildNode();
		while( node ){
			if( node->GetData()->IsKindOf( CLASSINFO(Constraint)) ) {
				ErdTable* pSecondTab = NULL;
				Constraint* pConstr = wxDynamicCast(node->GetData(), Constraint);
				//AddColumnShape(wxString::Format(wxT("key: %s"),pConstr->GetName().c_str()),i++);
				
				ShapeList::compatibility_iterator nodeTab = list.GetFirst();
				while(nodeTab){
					ErdTable* pTab = wxDynamicCast(nodeTab->GetData(), ErdTable);
					if (pTab){
						if (pTab->GetTable()->GetName() == pConstr->GetRefTable()) pSecondTab = pTab;						
						}					
					nodeTab = nodeTab->GetNext();
					}	
				if (pSecondTab){
						GetShapeManager()->CreateConnection(GetId(), pSecondTab->GetId(), new ErdForeignKey(pConstr), sfDONT_SAVE_STATE);					
					}
				} 
			node = node->GetNext();
			}
	}
	
	m_pGrid->Update();
	Update();
}

void ErdTable::ClearGrid()
{
	m_pGrid->RemoveChildren();
	// re-initialize grid control
	m_pGrid->ClearGrid();
	m_pGrid->SetDimensions( 1, 1 );	
	m_pGrid->SetCellSpace( 2 );
	Refresh();
}

void ErdTable::AddColumnShape(const wxString& colName, int id)
{
	wxSFTextShape* m_pCol = new wxSFTextShape();
	if (m_pCol){	
		m_pCol->SetStyle(sfsALWAYS_INSIDE | sfsPROCESS_DEL | sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION);
		m_pCol->SetId(id + constOffset);
		if (m_pGrid->AppendToGrid(m_pCol)){
			m_pCol->GetFont().SetPointSize(8);
			m_pCol->SetText( wxString::Format(wxT("%s"), colName.c_str()));			
			m_pCol->SetHAlign(wxSFShapeBase::halignLEFT);
			m_pCol->SetVAlign(wxSFShapeBase::valignMIDDLE);
			m_pCol->SetVBorder(0);
			m_pCol->SetHBorder(0);
			m_pCol->Activate(false);
			
		}else{			
			delete m_pCol;
			m_pCol = NULL;			
		}
	}
}

void ErdTable::AddColumn(const wxString& colName, IDbType* type)
{
	Table* tab = (Table*) wxDynamicCast(GetUserData(),Table);
	tab->AddColumn(new Column(colName,wxT("New table"),type));
}

void ErdTable::ClearConnections()
{
	ShapeList lstShapes;
	GetShapeManager()->GetAssignedConnections(this,CLASSINFO(ErdForeignKey),lineSTARTING ,lstShapes);
	
	// remove all child shapes
	ShapeList::compatibility_iterator node = lstShapes.GetFirst();
	while( node ) {
		ErdForeignKey* key = wxDynamicCast(node->GetData(),ErdForeignKey);		
		if (key){
			GetShapeManager()->RemoveShape(key);		
			}
			node = node->GetNext();
		}
}
