#include "ErdTable.h"
#include "wx/wxsf/CommonFcn.h"

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
	
	//AddConnectionPoint( wxSFConnectionPoint::cpCENTERLEFT );
	//AddConnectionPoint( wxSFConnectionPoint::cpCENTERRIGHT );
	AcceptConnection(wxT("All"));
	AcceptTrgNeighbour(wxT("All"));
	AcceptSrcNeighbour(wxT("All"));
	
	AddStyle( sfsLOCK_CHILDREN );
	AddStyle( sfsSHOW_SHADOW );
	
	SetBorder( wxPen( wxColour(70, 125, 170), 1, wxSOLID ) );
	SetFill( wxBrush( wxColour(210, 225, 245) ) );
	
	m_pLabel = new wxSFTextShape();
	
	m_pGrid = new wxSFFlexGridShape();
	
	if (m_pLabel && m_pGrid){
		m_pLabel->SetVAlign(wxSFShapeBase::valignTOP);
        m_pLabel->SetHAlign(wxSFShapeBase::halignCENTER);
        m_pLabel->SetVBorder(3);
		m_pLabel->SetHBorder(5);
		
		m_pLabel->GetFont().SetPointSize( 9 );
		m_pLabel->GetFont().SetWeight(wxFONTWEIGHT_BOLD);

		m_pLabel->SetText(wxT("Table name"));
		m_pLabel->SetStyle( sfsHOVERING | sfsALWAYS_INSIDE | sfsPROCESS_DEL | sfsEMIT_EVENTS |sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION);

        SF_ADD_COMPONENT( m_pLabel, wxT("title") );		
		
		// set grid
		m_pGrid->SetRelativePosition( 0, 25 );
		m_pGrid->SetStyle( sfsALWAYS_INSIDE | sfsPROCESS_DEL |sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION  );
		m_pGrid->SetDimensions( 1, 1 );
		
		m_pGrid->SetFill( *wxTRANSPARENT_BRUSH );
		m_pGrid->SetBorder( *wxTRANSPARENT_PEN );
		
		m_pGrid->SetHAlign( wxSFShapeBase::halignLEFT );
		m_pGrid->SetCellSpace( 1 );
		m_pGrid->SetVBorder( 15 );
		m_pGrid->SetHBorder( 5 );
		m_pGrid->AcceptChild( wxT("wxSFTextShape") );
		m_pGrid->Activate( false );
		
		SF_ADD_COMPONENT( m_pGrid, wxT("main_grid") );
	}
}

void ErdTable::DrawHighlighted(wxDC& dc)
{
	wxSFRoundRectShape::DrawHighlighted(dc);
	drawDetails(dc);
}

void ErdTable::drawDetails(wxDC& dc)
{
	dc.SetPen( *wxWHITE_PEN );
	dc.SetBrush( *wxWHITE_BRUSH );
	
	dc.DrawRectangle( Conv2Point(GetAbsolutePosition() + wxRealPoint(1, m_nRadius - 2)),
					  Conv2Size(m_nRectSize - wxRealPoint(2, 2*m_nRadius - 4)) );
}

void ErdTable::DrawHover(wxDC& dc)
{
	wxSFRoundRectShape::DrawHover(dc);
	drawDetails(dc);
}

void ErdTable::DrawNormal(wxDC& dc)
{
	wxSFRoundRectShape::DrawNormal(dc);
	drawDetails(dc);
}

void ErdTable::updateColumns()
{	
	clearGrid();
	clearConnections();
	ShapeList list;
	if (GetShapeManager()){
		GetShapeManager()->GetShapes(CLASSINFO(ErdTable), list);
		}
	
	int i = 0;
	
	Table* tab = (Table*) wxDynamicCast(GetUserData(),Table);
	if (tab){		
		m_pLabel->SetText(tab->getName());
		SerializableList::compatibility_iterator node = tab->GetFirstChildNode();
		while( node ){
			if( node->GetData()->IsKindOf( CLASSINFO(Column)) )  addColumnShape(wxString::Format(wxT("col: %s"),((Column*) node->GetData())->getName().c_str()),i++);
			node = node->GetNext();
			}		
			
		node = tab->GetFirstChildNode();
		while( node ){
			if( node->GetData()->IsKindOf( CLASSINFO(Constraint)) ) {
				ErdTable* pSecondTab = NULL;
				Constraint* pConstr = wxDynamicCast(node->GetData(), Constraint);
				addColumnShape(wxString::Format(wxT("key: %s"),pConstr->GetName().c_str()),i++);
				
				ShapeList::compatibility_iterator nodeTab = list.GetFirst();
				while(nodeTab){
					ErdTable* pTab = wxDynamicCast(nodeTab->GetData(), ErdTable);
					if (pTab){
						if (pTab->getTable()->getName() == pConstr->GetRefTable()) pSecondTab = pTab;						
						}					
					nodeTab = nodeTab->GetNext();
					}			
				if (pSecondTab){
						GetShapeManager()->CreateConnection(GetId(), pSecondTab->GetId(), new ErdForeignKey(pConstr));					
					}			
				} 
			node = node->GetNext();
			}
	}
	
	m_pGrid->Update();
	Update();
	Refresh();
}
void ErdTable::clearGrid()
{
	/*SerializableList::compatibility_iterator node;
	while( node = m_pGrid->GetFirstChildNode() )
	{
		GetParentManager()->RemoveItem( node->GetData() );
	}*/
	m_pGrid->RemoveChildren();
	// re-initialize grid control
	m_pGrid->ClearGrid();
	m_pGrid->SetDimensions( 1, 1 );	
	m_pGrid->Update();
	Refresh();
}

void ErdTable::addColumnShape(const wxString& colName, int id)
{
	wxSFTextShape* m_pCol = new wxSFTextShape();
	if (m_pCol){	
		m_pCol->SetStyle(sfsHOVERING |sfsEMIT_EVENTS| sfsALWAYS_INSIDE | sfsSIZE_CHANGE | sfsPROPAGATE_DRAGGING | sfsPROPAGATE_SELECTION );
		m_pCol->SetId(id + constOffset);
		if (m_pGrid->AppendToGrid(m_pCol)){
			m_pCol->SetText( wxString::Format(wxT("%s"), colName.c_str()));			
			m_pCol->SetHAlign(wxSFShapeBase::halignLEFT);
			m_pCol->SetVAlign(wxSFShapeBase::valignMIDDLE);
			m_pCol->SetVBorder(0);
			m_pCol->SetHBorder(0);
			m_pCol->GetFont().SetPointSize(8);
			m_pCol->Activate(false);
			
		}else{			
			delete m_pCol;
			m_pCol = NULL;			
			m_pGrid->Update();
			
			}
		}
}

void ErdTable::addColumn(const wxString& colName, IDbType* type)
{
	Table* tab = (Table*) wxDynamicCast(GetUserData(),Table);
	tab->AddColumn(new Column(colName,wxT("New table"),type));
}

void ErdTable::clearConnections()
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
