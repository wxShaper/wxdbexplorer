#include "SqliteDbAdapter.h"
#include "../DbEngine/dbconnection.h"
#include "../DbEngine/database.h"
#include "../DbEngine/table.h"

SQLiteDbAdapter::SQLiteDbAdapter() {
	m_sFileName = wxT("");
}
SQLiteDbAdapter::SQLiteDbAdapter(const wxString& fileName) {
	m_sFileName = fileName;
}

SQLiteDbAdapter::~SQLiteDbAdapter() {
}

void SQLiteDbAdapter::CloseConnection() {
}
DatabaseLayer* SQLiteDbAdapter::GetDatabaseLayer() {
	DatabaseLayer* pDatabase = NULL;
	
	#ifdef DBL_USE_SQLITE
	pDatabase = new SqliteDatabaseLayer(m_sFileName);
	#endif
	
	return pDatabase;
}
/*DatabaseCol* SQLiteDbAdapter::GetDatabases() {
	//DatabaseCol* col = new DatabaseCol();
	DatabaseLayer* dbLayer = this->GetDatabaseLayer();
	if (!dbLayer->IsOpen()) return NULL;

	// loading databases
	//TODO:SQL:
	DatabaseResultSet *databaze = dbLayer->RunQueryWithResults(wxT("PRAGMA database_list;"));
	while (databaze->Next()) {
		//col->AddDatabase(new Database(this, databaze->GetResultString(2)));
	}
	dbLayer->CloseResultSet(databaze);
	dbLayer->Close();
	delete dbLayer;
//	return col;

}*/
IDbType* SQLiteDbAdapter::GetDbTypeByName(const wxString& typeName) {
	IDbType* type = NULL;
	if (typeName == wxT("NULL")) {
		type = new SqliteType(wxT("NULL"), IDbType::dbtNOT_NULL );
	} else if (typeName == wxT("INTEGER")) {
		type = new SqliteType(wxT("INTEGER"), IDbType::dbtNOT_NULL );
	} else if (typeName == wxT("REAL")) {
		type = new SqliteType(wxT("REAL"), IDbType::dbtNOT_NULL );
	} else if (typeName == wxT("TEXT")) {
		type = new SqliteType(wxT("TEXT"), IDbType::dbtNOT_NULL );
	} else if (typeName == wxT("BLOB")) {
		type = new SqliteType(wxT("BLOB"), IDbType::dbtNOT_NULL );
	}

	wxASSERT(type);
	return type;
}
wxArrayString* SQLiteDbAdapter::GetDbTypes() {
	wxArrayString* pNames = new wxArrayString();
	pNames->Add(wxT("NULL"));
	pNames->Add(wxT("INTEGER"));
	pNames->Add(wxT("REAL"));
	pNames->Add(wxT("TEXT"));
	pNames->Add(wxT("BLOB"));
	return pNames;
}
/*TableCol* SQLiteDbAdapter::GetTables(const wxString& dbName) {
	TableCol* tab = new TableCol(dbName);

	DatabaseLayer* dbLayer = this->GetDatabaseLayer();
	if (!dbLayer->IsOpen()) return NULL;
	// lading tables for database
	//TODO:SQL:
	DatabaseResultSet *tabulky = dbLayer->RunQueryWithResults(wxString::Format(wxT("SELECT * FROM '%s'.sqlite_master WHERE type='table'"), dbName.c_str()) );
	while (tabulky->Next()) {
		tab->AddTable(new Table(this, tabulky->GetResultString(2), dbName, 0));
	}
	dbLayer->CloseResultSet(tabulky);
	dbLayer->Close();
	delete dbLayer;
	return tab;

}*/
bool SQLiteDbAdapter::IsConnected() {
}
wxString SQLiteDbAdapter::GetDefaultSelect(const wxString& dbName, const wxString& tableName) {
	return wxString::Format(wxT("SELECT * FROM '%s'.'%s';"),dbName.c_str(),tableName.c_str());
}
bool SQLiteDbAdapter::GetColumns(Table* pTab) {

	DatabaseLayer* dbLayer = this->GetDatabaseLayer();
	if (dbLayer) {
		if (!dbLayer->IsOpen()) return NULL;
		// loading columns
		//TODO:SQL:
		DatabaseResultSet *database = dbLayer->RunQueryWithResults(wxString::Format(wxT("PRAGMA table_info('%s')"),pTab->getName().c_str()));
		while (database->Next()) {
			IDbType* pType = GetDbTypeByName(database->GetResultString(3));
			if (pType) {
				pType->SetNotNull(database->GetResultInt(4) == 1);
				Column* pCol = new Column(database->GetResultString(2),pTab->getName(), pType);
				pTab->AddChild(pCol);
			}
		}
		dbLayer->CloseResultSet(database);
		dbLayer->Close();
		delete dbLayer;

	}
	return true;
}
wxString SQLiteDbAdapter::GetCreateTableSql(Table* tab, bool dropTable) {
	//TODO:SQL:
	wxString str = wxT("");
	if (dropTable) str = wxString::Format(wxT("DROP TABLE IF EXISTS `%s`; \n"),tab->getName().c_str());
	str.append(wxString::Format(wxT("CREATE TABLE `%s` (\n"),tab->getName().c_str()));



	SerializableList::compatibility_iterator node = tab->GetFirstChildNode();
	while( node ) {
		Column* col = NULL;
		if( node->GetData()->IsKindOf( CLASSINFO(Column)) ) col = (Column*) node->GetData();
		if(col)	str.append(wxString::Format(wxT("\t`%s` %s"),col->getName().c_str(), col->getPType()->ReturnSql().c_str()));
		node = node->GetNext();
		if (node) str.append(wxT(",\n ")) ;
		else  str.append(wxT("\n ")) ;
	}

	str.append(wxT(");\n"));
	str.append(wxT("-- -------------------------------------------------------------\n"));
	return str;
}



bool SQLiteDbAdapter::CanConnect() {
	return m_sFileName != wxT("");
}

void SQLiteDbAdapter::GetDatabases(DbConnection* dbCon) {
	DatabaseLayer* dbLayer = this->GetDatabaseLayer();
	if (dbLayer) {
		if (!dbLayer->IsOpen()) return;

		//TODO:SQL:
		DatabaseResultSet *databaze = dbLayer->RunQueryWithResults(wxT("PRAGMA database_list;"));
		while (databaze->Next()) {
			dbCon->AddChild(new Database(this, databaze->GetResultString(2)));
		}
		dbLayer->CloseResultSet(databaze);
		dbLayer->Close();
		delete dbLayer;
	}
}

void SQLiteDbAdapter::GetTables(Database* db) {
	DatabaseLayer* dbLayer = this->GetDatabaseLayer();
	if (dbLayer) {
		if (!dbLayer->IsOpen()) return;
		//TODO:SQL:
		DatabaseResultSet *tabulky = dbLayer->RunQueryWithResults(wxString::Format(wxT("SELECT * FROM '%s'.sqlite_master WHERE type='table'"), db->getName().c_str()) );
		while (tabulky->Next()) {
			db->AddChild(new Table(this, tabulky->GetResultString(2), db->getName(), 0));
		}
		dbLayer->CloseResultSet(tabulky);
		dbLayer->Close();
		delete dbLayer;
	}

}
wxString SQLiteDbAdapter::GetCreateDatabaseSql(const wxString& dbName) {
	return wxT("");
}
wxString SQLiteDbAdapter::GetDropTableSql(Table* pTab) {
	return wxT("");
}
