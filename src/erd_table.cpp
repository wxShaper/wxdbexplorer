#include "erd_table.h"

ErdTable::ErdTable():wxSFRoundRectShape()
{
	m_pTable = new Table();
	m_pTable->setName(wxT("New table 0"));
	
	Initialize();
}

ErdTable::~ErdTable()
{
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

