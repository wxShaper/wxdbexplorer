#ifndef DBITEM_H
#define DBITEM_H
#include "database.h"
#include "table.h"
#include <wx/treebase.h> // Base class: wxTreeItemData

class DbItem : public wxTreeItemData {
protected:
	Database* m_pDatabase;
	Table* m_pTable;	
public:
	DbItem(Database* pDatabase, Table* pTable);
	~DbItem();
	
	Database* GetDatabase(){ return this->m_pDatabase; }
	Table* GetTable(){ return this->m_pTable; }
};

#endif // DBITEM_H
