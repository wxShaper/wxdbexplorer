#include "erd_table.h"
#define constOffset MAX_ID

XS_IMPLEMENT_CLONABLE_CLASS(ErdTable,wxSFRoundRectShape);


ErdTable::ErdTable():wxSFRoundRectShape()
{
	m_pTable = new Table();
	m_pTable->setName(wxT("New table"));
	
	//m_pTable->AddColumn(new Column(wxT("ID"),wxT("New table"),wxT("int"), true, true));
	//m_pTable->AddColumn(new Column(wxT("Name"),wxT("New table"),wxT("string"), true, true));
	//m_pTable->AddColumn(new Column(wxT("Value"),wxT("New table"),wxT("long"), true, true));
	XS_SERIALIZE_DYNAMIC_OBJECT(m_pTable, wxT("Table"));
	Initialize();
}
ErdTable::ErdTable(const ErdTable& obj):wxSFRoundRectShape(obj)
{
	m_pTable = (Table*) obj.m_pTable->Clone();
	//m_pTable->setName(wxT("New table"));
	XS_SERIALIZE_DYNAMIC_OBJECT(m_pTable, wxT("Table"));
	
	m_pLabel = (wxSFTextShape*) obj.m_pLabel->Clone();
	if (m_pLabel){
		SF_ADD_COMPONENT( m_pLabel, wxT("title") );	
		XS_SERIALIZE_DYNAMIC_OBJECT_NO_CREATE(m_pLabel, wxT("TableNameLabel"));	
		}

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

		XS_SERIALIZE_DYNAMIC_OBJECT_NO_CREATE(m_pLabel, wxT("TableNameLabel"));
		
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
	int i = 0;
	
	
	SerializableList::compatibility_iterator node = m_pTable->GetFirstChildNode();
	while( node )
		{
		if( node->GetData()->IsKindOf( CLASSINFO(Column)) )  addColumnShape(((Column*) node->GetData())->getName(),i++);
		node = node->GetNext();
		}
	
	
	/*
	
	Column* pCol = m_pTable->GetFristColumn();
	while(pCol){
		addColumnShape(pCol->getName(),i++);		
		pCol = wxDynamicCast(pCol->GetSibbling(CLASSINFO(Column)),Column);
		}	*/
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
	m_pTable->AddColumn(new Column(colName,wxT("New table"),type, true, true));
}

