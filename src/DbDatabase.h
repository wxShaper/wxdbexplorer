#ifndef DBDATABASE_H
#define DBDATABASE_H

#include <wx/wx.h>
#include "IDbItem.h" // Base class: IDbItem

class DbDatabase : public IDbItem {

public:
	DbDatabase(const wxString databaseName);
	~DbDatabase();

	virtual wxString GetParentName();
	virtual wxString GetName();
	virtual DbItemType GetType() { return DbDatabaseType; }
	virtual void SetParentName(wxString& databaseName);
	virtual void SetName(wxString& name);
	
protected:
	wxString m_databaseName;
};

#endif // DBDATABASE_H
