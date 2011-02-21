#include "ErdForeignKey.h"

XS_IMPLEMENT_CLONABLE_CLASS(ErdForeignKey,wxSFOrthoLineShape);

ErdForeignKey::ErdForeignKey():wxSFOrthoLineShape()
{
	m_pConstraint = NULL;
}

ErdForeignKey::ErdForeignKey(Constraint* pConstraint):wxSFOrthoLineShape()
{
	m_pConstraint = pConstraint;
}

ErdForeignKey::ErdForeignKey(const ErdForeignKey& obj):wxSFOrthoLineShape(obj)
{
	m_pConstraint = obj.m_pConstraint;
}
ErdForeignKey::~ErdForeignKey()
{
}

