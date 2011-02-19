#ifndef DATABASE_H
#define DATABASE_H
#include <wx/wx.h>
#include <wx/dblayer/DatabaseResultSet.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "tablecol.h"


// -------------------------------------------------
// Trida databaze
// -------------------------------------------------
class IDbAdapter;
class Database : public xsSerializable {
	
	
protected:
	wxString m_name;
	bool m_isSaved;	
	IDbAdapter* m_pDbAdapter;
	
public:
	XS_DECLARE_CLONABLE_CLASS(Database);
	Database();
	Database(const Database& obj);
	Database(IDbAdapter* dbAdapter,const wxString& dbName);
	virtual ~Database();
	void RefreshChildren();

	IDbAdapter* getDbAdapter() { return this->m_pDbAdapter; }
	// nazev databáze
	wxString getName() { return this->m_name; }
	// priznak isSaved
	bool IsSaved() { return this->m_isSaved; }
	//TableCol *tables;

};

#endif // DATABASE_H
