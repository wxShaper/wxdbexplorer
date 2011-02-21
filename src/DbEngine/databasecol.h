#ifndef DATABASECOL_H
#define DATABASECOL_H
#include <wx/wx.h>
#include <wx/dynarray.h>
#include <wx/dblayer/include/DatabaseResultSet.h>
#include "database.h"
#include "Interfaces/IDbAdapter.h"

WX_DECLARE_OBJARRAY(Database, ArrayOfDatabase);

// -------------------------------------------------
// Colekce databazi
// -------------------------------------------------
class DatabaseCol {
protected:
	ArrayOfDatabase m_al;
	
public:
	DatabaseCol();
	~DatabaseCol();
	
	Database* GetByIndex(int i);
	Database& operator[](int i);
	int	GetDbCount();
	void AddDatabase(Database* db);
};

#endif // DATABASECOL_H
