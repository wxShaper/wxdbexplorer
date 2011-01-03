#ifndef DBTABLE_H
#define DBTABLE_H

#include <wx/wx.h>
#include "IDbItem.h" // Base class: IDbItem

class DbTable : public IDbItem {

public:
	DbTable(wxString& tableName, wxString& databaseName);
	~DbTable();
	virtual wxString GetParentName();
	virtual wxString GetName();
	virtual DbItemType GetType() { return DbTableType; }
	
	virtual void SetParentName(wxString& databaseName);;
	virtual void SetName(wxString& name);

	
protected:
	wxString m_tableName;
	wxString m_databaseName;
};

#endif // DBTABLE_H
