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
		foreignKey,
		noKey
	};

	enum constraintAction {
		restrict,
		cascade,
		setNull,
		noAction
	};

	XS_DECLARE_CLONABLE_CLASS(Constraint);
	Constraint();
	Constraint(const Constraint& obj);
	Constraint(const wxString& name, const wxString& localColumn, constraintType type, constraintAction onDelete, constraintAction onUpdate);
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
	void SetType(constraintType type) {
		this->m_type = type;
	}
	void SetOnDelete(constraintAction onDelete) {
		this->m_onDelete = onDelete;
	}
	void SetOnUpdate(constraintAction onUpdate) {
		this->m_onUpdate = onUpdate;
	}
	constraintAction GetOnDelete() const {
		return m_onDelete;
	}
	constraintAction GetOnUpdate() const {
		return m_onUpdate;
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
	constraintType GetType() const {
		return m_type;
	}

protected:
	constraintType m_type;
	wxString m_name;
	wxString m_localColumn;
	wxString m_refTable;
	wxString m_refCol;
	constraintAction m_onDelete;
	constraintAction m_onUpdate;

	void InitSerializable();
};

#endif // CONSTRAINT_H
