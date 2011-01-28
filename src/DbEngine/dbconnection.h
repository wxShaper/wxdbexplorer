#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <wx/wx.h>
#include <wx/dblayer/DatabaseResultSet.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "Interfaces/IDbAdapter.h"

class DbConnection : public xsSerializable {

public:
	XS_DECLARE_CLONABLE_CLASS(DbConnection);

	DbConnection();
	DbConnection(IDbAdapter* dbAdapter, const wxString& serverName);
	DbConnection(const DbConnection& obj);
	virtual ~DbConnection();
	
	void Load();
	IDbAdapter* GetDbAdapter() { return m_pDbAdapter; }
	
protected:
	IDbAdapter* m_pDbAdapter;
	wxString m_serverName;
};

#endif // DBCONNECTION_H
