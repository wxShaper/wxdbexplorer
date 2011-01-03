#include "erd_table.h"

ErdTable::ErdTable():wxSFRoundRectShape()
{
	m_pTable = new Table();
	m_pTable->setName(wxT("New table"));
	
	m_pTable->columns->AddColumn(new Column(wxT("ID"),wxT("New table"),wxT("int"), true, true));
	
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
	delete m_pLabel;
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

