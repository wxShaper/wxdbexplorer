#include "MySqlDbConnector.h"

MySqlDbConnector::MySqlDbConnector( MysqlDatabaseLayer* dbLayer) {
	this->m_pDbLayer = dbLayer;
}

MySqlDbConnector::~MySqlDbConnector() {
}

wxArrayString MySqlDbConnector::GetSP(wxString& dbName) {
	return NULL;
}
void MySqlDbConnector::CloseConnection() {
	this->m_pDbLayer->Close();
}

DatabaseLayer* MySqlDbConnector::GetDatabaseLayer() {
	return m_pDbLayer;
}

wxArrayString MySqlDbConnector::GetDatabases() {
	wxArrayString retValue;
	if (!this->IsConnected()) return NULL;
	// loading databases
	//TODO:SQL:
	DatabaseResultSet *databaze = m_pDbLayer->RunQueryWithResults(wxT("SHOW DATABASES"));
	while (databaze->Next()) {
		retValue.Add(databaze->GetResultString(1));
	}
	m_pDbLayer->CloseResultSets();
	return retValue;
}

wxArrayString MySqlDbConnector::GetTablses(wxString& dbName) {
	wxArrayString retValue;
	if (!this->IsConnected()) return NULL;
	// lading tables for database
	//TODO:SQL:
	DatabaseResultSet *tabulky = m_pDbLayer->RunQueryWithResults( wxT("SHOW TABLES IN ") + dbName );
	while (tabulky->Next()) {
		retValue.Add(tabulky->GetResultString(1));
	}
	m_pDbLayer->CloseResultSet(tabulky);
	return retValue;
}

wxArrayString MySqlDbConnector::GetViews(wxString& dbName) {
	return NULL;
}
bool MySqlDbConnector::IsConnected() {
	return this->m_pDbLayer->IsOpen();
}

DatabaseResultSet* MySqlDbConnector::GetTableInfo(wxString& dbName, wxString& tableName) {
	wxString query = wxT("SHOW COLUMNS IN " ) + dbName + wxT(".") + tableName;
	DatabaseResultSet *cols = m_pDbLayer->RunQueryWithResults(query);
	return cols;
}
