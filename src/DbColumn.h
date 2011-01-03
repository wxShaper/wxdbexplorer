#ifndef DBCOLUMN_H
#define DBCOLUMN_H

#include <wx/wx.h>
#include "IDbItem.h" // Base class: IDbItem

class DbColumn : public IDbItem {

public:
	DbColumn(wxString parentName, wxString name, wxString type, wxString notNull, wxString key );
	virtual ~DbColumn();

public:
	virtual wxString GetParentName() { return m_parentName; }
	virtual wxString GetName() { return m_name; }
	virtual DbItemType GetType() { return DbColumnType; }
	virtual void SetParentName(wxString& databaseName);
	virtual void SetName(wxString& name);
	
	wxString GetColumnType() { return m_type; }
	bool IsPrimaryKey() { return m_primaryKey; }
	bool IsForeignKey() { return m_foreignKey; }
	bool IsNotNull() { return m_notNull; }
	
protected:
	wxString m_name;
	wxString m_parentName;
	wxString m_type;
	wxString m_key;
	
	bool m_notNull;
	bool m_primaryKey;
	bool m_foreignKey;
	
};

#endif // DBCOLUMN_H
