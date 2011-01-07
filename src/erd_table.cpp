#include "erd_table.h"
#define constOffset MAX_ID

ErdTable::ErdTable():wxSFRoundRectShape()
{
	m_pTable = new Table();
	m_pTable->setName(wxT("New table"));
	
	m_pTable->columns->AddColumn(new Column(wxT("ID"),wxT("New table"),wxT("int"), true, true));
	m_pTable->columns->AddColumn(new Column(wxT("Name"),wxT("New table"),wxT("string"), true, true));
	m_pTable->columns->AddColumn(new Column(wxT("Value"),wxT("New table"),wxT("long"), true, true));
	
	Initialize();
}
ErdTable::ErdTable(const ErdTable& obj):wxSFRoundRectShape(obj)
{
	m_pTable = new Table();
	m_pTable->setName(wxT("New table"));
	
	Initialize();
}
ErdTable::~ErdTable()
{
	delete m_pTable;
	//delete m_pLabel;
}

void ErdTable::Initialize()
{
	SetFill(wxBrush(wxColour(254, 253, 211)));
	m_pLabel = new wxSFTextShape();
	
	m_pGrid = new wxSFFlexGridShape();
	
	if (m_pLabel){
		m_pLabel->SetVAlign(wxSFShapeBase::valignTOP);
        m_pLabel->SetHAlign(wxSFShapeBase::halignCENTER);
        m_pLabel->SetVBorder(5);
		m_pLabel->SetHBorder(5);
		m_pLabel->GetFont().SetWeight(wxFONTWEIGHT_BOLD);

		m_pLabel->SetText(wxT("Table name"));
		m_pLabel->SetStyle( sfsHOVERING | sfsALWAYS_INSIDE | sfsPROCESS_DEL | sfsEMIT_EVENTS );

        SF_ADD_COMPONENT( m_pLabel, wxT("title") );		
		
		
		// set grid
		m_pGrid->SetRelativePosition( 0, 20 );
		m_pGrid->SetStyle( sfsALWAYS_INSIDE | sfsPROCESS_DEL );
		m_pGrid->SetDimensions( 1, 1 );
		
		m_pGrid->SetFill( *wxTRANSPARENT_BRUSH );
		m_pGrid->SetBorder( *wxTRANSPARENT_PEN );
		
		m_pGrid->SetHAlign( wxSFShapeBase::halignLEFT );
		m_pGrid->SetHBorder( 0 );
		m_pGrid->SetVBorder( 5 );
		m_pGrid->SetCellSpace( 10 );
		
		m_pGrid->AcceptChild( wxT("All") );
		SF_ADD_COMPONENT( m_pGrid, wxT("main_grid") );
		
		}
		
		
		updateColumns();
		Update();
}


void ErdTable::DrawHighlighted(wxDC& dc)
{
	m_pLabel->SetText(m_pTable->getName());
	wxSFRoundRectShape::DrawHighlighted(dc);
}
void ErdTable::DrawHover(wxDC& dc)
{
	wxSFRoundRectShape::DrawHover(dc);
}
void ErdTable::DrawNormal(wxDC& dc)
{
	m_pLabel->SetText(m_pTable->getName());
	wxSFRoundRectShape::DrawNormal(dc);
}

void ErdTable::updateColumns()
{
	clearGrid();
	for(int i=0; i<m_pTable->columns->GetColCount();++i){
		Column* pCol = m_pTable->columns->GetByIndex(i);
		addColumnShape(pCol->getName(),i);		
		}	
	m_pGrid->Update();
	Update();
}
void ErdTable::clearGrid()
{
	SerializableList::compatibility_iterator node;
	while( node = m_pGrid->GetFirstChildNode() )
	{
		GetParentManager()->RemoveItem( node->GetData() );
	}
	// re-initialize grid control
	m_pGrid->ClearGrid();
	m_pGrid->SetDimensions( 1, 1 );	
	m_pGrid->Update();
}

void ErdTable::addColumnShape(const wxString& colName, int id)
{
	wxSFTextShape* m_pCol = new wxSFTextShape();
	if (m_pCol){	
		m_pCol->SetId(id + constOffset);
		if (m_pGrid->AppendToGrid(m_pCol)){
			m_pCol->SetText( wxString::Format(wxT("col: %s"), colName.c_str()));			
			m_pCol->SetHAlign(wxSFShapeBase::halignLEFT);
			m_pCol->SetVAlign(wxSFShapeBase::valignTOP);
			//	m_pLabel->SetVAlign(wxSFShapeBase::valignTOP);
			//m_pLabel->SetHAlign(wxSFShapeBase::halignCENTER);
			m_pCol->SetVBorder(2);
			m_pCol->SetHBorder(2);
			m_pCol->SetCustomDockPoint(wxSFConnectionPoint::cpCENTERLEFT);
			m_pCol->SetStyle(sfsALWAYS_INSIDE | sfsSIZE_CHANGE );			
		}else{			
			delete m_pCol;
			m_pCol = NULL;			
			m_pGrid->Update();
			
			}
		}
}

void ErdTable::addColumn(const wxString& colName, IDbType* type)
{
	m_pTable->columns->AddColumn(new Column(colName,wxT("New table"),type, true, true));
}

