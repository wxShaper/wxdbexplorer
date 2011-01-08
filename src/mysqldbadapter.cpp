#include "mysqldbadapter.h"

MySqlDbAdapter::MySqlDbAdapter(const wxString& serverName, const wxString& userName, const wxString& password) {
	this->m_serverName = serverName;
	this->m_userName = userName;
	this->m_password = password;
}

MySqlDbAdapter::~MySqlDbAdapter() {
}

void MySqlDbAdapter::CloseConnection() {
	this->m_pDbLayer->Close();
}

ColumnCol* MySqlDbAdapter::GetColumns(const wxString& tableName) {
	return new ColumnCol(tableName);
}

DatabaseLayer* MySqlDbAdapter::GetDatabaseLayer() {
	DatabaseLayer* dbLayer = new MysqlDatabaseLayer(this->m_serverName, wxT(""), this->m_userName, this->m_password);
	return dbLayer;
}

TableCol* MySqlDbAdapter::GetTables(const wxString& dbName) {
	TableCol* tab = new TableCol(dbName);

	DatabaseLayer* dbLayer = this->GetDatabaseLayer();
	if (!dbLayer->IsOpen()) return NULL;
	// lading tables for database
	//TODO:SQL:
	DatabaseResultSet *tabulky = dbLayer->RunQueryWithResults(wxString::Format(wxT("SHOW TABLES IN `%s`"), dbName.c_str()) );
	while (tabulky->Next()) {
		tab->AddTable(new Table(this, tabulky->GetResultString(1), dbName, 0));
	}
	dbLayer->CloseResultSet(tabulky);
	dbLayer->Close();
	delete dbLayer;
	return tab;
}

bool MySqlDbAdapter::IsConnected() {
	return this->m_pDbLayer->IsOpen();
}
DatabaseCol* MySqlDbAdapter::GetDatabases() {
	DatabaseCol* col = new DatabaseCol();

	DatabaseLayer* dbLayer = this->GetDatabaseLayer();

	if (!dbLayer->IsOpen()) return NULL;
	// loading databases
	//TODO:SQL:
	DatabaseResultSet *databaze = dbLayer->RunQueryWithResults(wxT("SHOW DATABASES"));
	while (databaze->Next()) {
		//wxString dbName = databaze->GetResultString(1);
		col->AddDatabase(new Database(this, databaze->GetResultString(1)));
	}
	dbLayer->CloseResultSet(databaze);
	dbLayer->Close();
	delete dbLayer;
	return col;
}


wxString MySqlDbAdapter::GetCreateTableSql(Table* tab) {
	wxString str = wxString::Format(wxT("DROP TABLE EXIST `%s`; \n"),tab->getName().c_str());
	str.append(wxString::Format(wxT("CREATE TABLE `%s` (\n"),tab->getName().c_str()));

	for (int i = 0; i < tab->columns->GetColCount(); ++i) {

		Column* col = (Column*) tab->columns->GetByIndex(i);
		if (col) {
			str.append(wxString::Format(wxT("\t`%s` %s "),col->getName().c_str(), col->getType().c_str()));
			if (i != tab->columns->GetColCount()-1) str.append(wxT(",\n ")) ;
			else  str.append(wxT("\n ")) ;
		}
	}

	str.append(wxT(")"));
	return str;
}


IDbType* MySqlDbAdapter::GetDbTypeByName(const wxString& typeName) {
	IDbType* type;
	if (typeName == wxT("INT")){
			type = new MySqlType(wxT("INT"),true,false,true,false,false);
	}else if (typeName == wxT("VARCHAR")){	
			type = new MySqlType(wxT("VARCHAR"),false,true,false,true,true);
	}
	return type;
}

wxArrayString* MySqlDbAdapter::GetDbTypes() {
	wxArrayString* pNames = new wxArrayString();
	pNames->Add(wxT("INT"));
	pNames->Add(wxT("VARCHAR"));
	return pNames;
}
