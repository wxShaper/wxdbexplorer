#include "dbitem.h"


DbItem::~DbItem()
{
}

DbItem::DbItem(Database* pDatabase, Table* pTable)
{
	this->m_pDatabase = pDatabase;
	this->m_pTable = pTable;
}

