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
	if (m_pLabel){
		m_pLabel->SetVAlign(wxSFShapeBase::valignTOP);
        m_pLabel->SetHAlign(wxSFShapeBase::halignCENTER);
        m_pLabel->SetVBorder(5);
		m_pLabel->SetHBorder(5);

		m_pLabel->SetText(wxT("Table name"));
		m_pLabel->SetStyle( sfsHOVERING | sfsALWAYS_INSIDE | sfsPROCESS_DEL | sfsEMIT_EVENTS );

        SF_ADD_COMPONENT( m_pLabel, wxT("title") );		
		}
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



