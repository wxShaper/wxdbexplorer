#include "ErdForeignKey.h"

XS_IMPLEMENT_CLONABLE_CLASS(ErdForeignKey,wxSFOrthoLineShape);

ErdForeignKey::ErdForeignKey():wxSFOrthoLineShape()
{
	m_pConstraint = NULL;
}

ErdForeignKey::ErdForeignKey(Constraint* pConstraint):wxSFOrthoLineShape()
{
	m_pConstraint = pConstraint;
	wxSFTextShape* pLabel = new wxSFTextShape();
	pLabel->GetFont().SetPointSize(10);
	//pLabel->SetFont(pLabel->GetFont().SetPixelSize(20));
	pLabel->SetText(pConstraint->GetName());
	pLabel->SetVAlign(valignMIDDLE);
	pLabel->SetHAlign(halignCENTER);
	pLabel->SetFill(*wxWHITE_BRUSH);
	pLabel->SetStyle(sfsLOCK_CHILDREN | sfsPARENT_CHANGE);
	pLabel->RemoveStyle(sfsPARENT_CHANGE);
	pLabel->RemoveStyle(sfsSHOW_HANDLES);
	
	AddChild(pLabel);


	SetTrgArrow(CLASSINFO(OneArrow));
	SetSrcArrow(CLASSINFO(NArrow));
	
	RemoveHandle(wxSFShapeHandle::hndLINESTART);
	RemoveHandle(wxSFShapeHandle::hndLINEEND);

	SetDockPoint(INT_MAX);
	
	
}

ErdForeignKey::ErdForeignKey(const ErdForeignKey& obj):wxSFOrthoLineShape(obj)
{
	m_pConstraint = obj.m_pConstraint;
}
ErdForeignKey::~ErdForeignKey()
{
}

