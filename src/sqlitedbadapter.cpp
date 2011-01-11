#include "sqlitedbadapter.h"

SQLiteDbAdapter::SQLiteDbAdapter(const wxString& fileName) {
	m_sFileName = fileName;
}

SQLiteDbAdapter::~SQLiteDbAdapter() {
}

void SQLiteDbAdapter::CloseConnection() {
}
DatabaseLayer* SQLiteDbAdapter::GetDatabaseLayer() {
	DatabaseLayer* pDatabase = new SqliteDatabaseLayer(m_sFileName);
	return pDatabase;
}
DatabaseCol* SQLiteDbAdapter::GetDatabases() {
	DatabaseCol* col = new DatabaseCol();
	DatabaseLayer* dbLayer = this->GetDatabaseLayer();
	if (!dbLayer->IsOpen()) return NULL;

	// loading databases
	//TODO:SQL:
	DatabaseResultSet *databaze = dbLayer->RunQueryWithResults(wxT("PRAGMA database_list;"));
	while (databaze->Next()) {
		col->AddDatabase(new Database(this, databaze->GetResultString(2)));
	}
	dbLayer->CloseResultSet(databaze);
	dbLayer->Close();
	delete dbLayer;
	return col;

}
IDbType* SQLiteDbAdapter::GetDbTypeByName(const wxString& typeName) {
}
wxArrayString* SQLiteDbAdapter::GetDbTypes() {
}
TableCol* SQLiteDbAdapter::GetTables(const wxString& dbName) {
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

}
bool SQLiteDbAdapter::IsConnected() {
}
wxString SQLiteDbAdapter::GetDefaultSelect(const wxString& dbName, const wxString& tableName) {
	return wxString::Format(wxT("SELECT * FROM '%s'.'%s';"),dbName.c_str(),tableName.c_str());
}
