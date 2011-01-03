#include "SqliteDbConnector.h"

SqliteDbConnector::SqliteDbConnector(SqliteDatabaseLayer* dbLayer) {
	this->m_pDbLayer = dbLayer;
}

SqliteDbConnector::~SqliteDbConnector() {
}

void SqliteDbConnector::CloseConnection() {
	m_pDbLayer->Close();
}
DatabaseLayer* SqliteDbConnector::GetDatabaseLayer() {
	return m_pDbLayer;
}
wxArrayString SqliteDbConnector::GetDatabases() {
	wxArrayString retValue;
	retValue.Add(wxT("Main"));
	return retValue;
}
wxArrayString SqliteDbConnector::GetSP(wxString& dbName) {
	return NULL;
}
wxArrayString SqliteDbConnector::GetTablses(wxString& dbName) {
	return m_pDbLayer->GetTables();
}
wxArrayString SqliteDbConnector::GetViews(wxString& dbName) {
	return NULL;
}
bool SqliteDbConnector::IsConnected() {
	return m_pDbLayer->IsOpen();
}
DatabaseResultSet* SqliteDbConnector::GetTableInfo(wxString& dbName, wxString& tableName) {
	return NULL;
}
