#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include <wx/wx.h>
#include <wx/dblayer/include/DatabaseResultSet.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "Interfaces/IDbAdapter.h"

class Constraint : public xsSerializable {

public: 
	enum constraintType {
		primaryKey,
		foreignKey
	}; 
	
	
	XS_DECLARE_CLONABLE_CLASS(Constraint);
	Constraint();
	Constraint(const Constraint& obj);
	Constraint(const wxString& name, const wxString& localColumn, constraintType type);
	virtual ~Constraint();



	void SetLocalColumn(const wxString & localColumn) {
		this->m_localColumn = localColumn;
	}
	void SetName(const wxString & name) {
		this->m_name = name;
	}
	void SetRefCol(const wxString & refCol) {
		this->m_refCol = refCol;
	}
	void SetRefTable(const wxString & refTable) {
		this->m_refTable = refTable;
	}
	void SetType(const constraintType & type) {
		this->m_type = type;
	}
	const wxString & GetLocalColumn() const {
		return m_localColumn;
	}
	const wxString & GetName() const {
		return m_name;
	}
	const wxString & GetRefCol() const {
		return m_refCol;
	}
	const wxString & GetRefTable() const {
		return m_refTable;
	}
	const constraintType & GetType() const {
		return m_type;
	}
	
protected:
	constraintType m_type;
	wxString m_name;
	wxString m_localColumn;
	wxString m_refTable;
	wxString m_refCol;

};

#endif // CONSTRAINT_H
