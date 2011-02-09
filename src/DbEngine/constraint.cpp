#include "constraint.h"
XS_IMPLEMENT_CLONABLE_CLASS(Constraint,xsSerializable);
Constraint::Constraint()
{
}
Constraint::Constraint(const Constraint& obj):xsSerializable(obj)
{
	m_name = obj.m_name;
	m_localColumn = obj.m_localColumn;
	m_type = obj.m_type;
	m_refTable = obj.m_refTable;
	m_refCol = obj.m_refCol;
	
	
}
Constraint::Constraint(const wxString& name, const wxString& localColumn, constraintType type)
{
	m_name = name;
	m_localColumn = localColumn;
	m_type = type;
}
Constraint::~Constraint()
{
}

