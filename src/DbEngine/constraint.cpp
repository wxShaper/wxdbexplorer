#include "constraint.h"
XS_IMPLEMENT_CLONABLE_CLASS(Constraint,xsSerializable);
Constraint::Constraint()
{
	InitSerializable();
}
Constraint::Constraint(const Constraint& obj):xsSerializable(obj)
{
	m_name = obj.m_name;
	m_localColumn = obj.m_localColumn;
	m_type = obj.m_type;
	m_refTable = obj.m_refTable;
	m_refCol = obj.m_refCol;
	InitSerializable();
	
}
Constraint::Constraint(const wxString& name, const wxString& localColumn, constraintType type)
{
	m_name = name;
	m_localColumn = localColumn;
	m_type = type;
	InitSerializable();
}
Constraint::~Constraint()
{
}

void Constraint::InitSerializable()
{
	XS_SERIALIZE(m_name, wxT("name"));
	XS_SERIALIZE(m_localColumn, wxT("localColumn"));
	XS_SERIALIZE_INT(m_type, wxT("type"));
	XS_SERIALIZE(m_refTable, wxT("refTable"));
	XS_SERIALIZE(m_refCol, wxT("refCol"));
}


