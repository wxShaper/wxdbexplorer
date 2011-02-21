#include "MySqlDbAdapter.h"
#include "../DbEngine/dbconnection.h"
#include "../DbEngine/database.h"
#include "../DbEngine/table.h"


MySqlDbAdapter::MySqlDbAdapter() {
	this->m_serverName = wxT("");
	this->m_userName = wxT("");
	this->m_password = wxT("");
}
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

DatabaseLayer* MySqlDbAdapter::GetDatabaseLayer() {
	DatabaseLayer* dbLayer = NULL;
	
	#ifdef DBL_USE_MYSQL
	if (!CanConnect())  return new MysqlDatabaseLayer();
	dbLayer = new MysqlDatabaseLayer(this->m_serverName, wxT(""), this->m_userName, this->m_password);
	#endif
	
	return dbLayer;
}

/*TableCol* MySqlDbAdapter::GetTables(const wxString& dbName) {
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
}*/

bool MySqlDbAdapter::IsConnected() {
	return this->m_pDbLayer->IsOpen();
}
/*DatabaseCol* MySqlDbAdapter::GetDatabases() {
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
}*/


wxString MySqlDbAdapter::GetCreateTableSql(Table* tab, bool dropTable) {
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

	/*	Column* col = tab->GetFristColumn();
		while (col) {
			str.append(wxString::Format(wxT("\t`%s` %s"),col->getName().c_str(), col->getPType()->ReturnSql().c_str()));
			col = wxDynamicCast(col->GetSibbling(),Column);
			if (col) str.append(wxT(",\n ")) ;
			else  str.append(wxT("\n ")) ;
		}*/

	str.append(wxT(");\n"));
	str.append(wxT("-- -------------------------------------------------------------\n"));
	return str;
}


IDbType* MySqlDbAdapter::GetDbTypeByName(const wxString& typeName) {
	IDbType* type = NULL;
	if (typeName == wxT("INT")) {
		type = new MySqlType(wxT("INT"), IDbType::dbtAUTO_INCREMENT | IDbType::dbtNOT_NULL | IDbType::dbtSIZE );
	} else if (typeName == wxT("VARCHAR")) {
		type = new MySqlType(wxT("VARCHAR"),IDbType::dbtUNIQUE | IDbType::dbtNOT_NULL | IDbType::dbtSIZE);
	} else if (typeName == wxT("DOUBLE")) {
		type = new MySqlType(wxT("DOUBLE"), IDbType::dbtAUTO_INCREMENT | IDbType::dbtNOT_NULL | IDbType::dbtSIZE);
	} else if (typeName == wxT("FLOAT")) {
		type = new MySqlType(wxT("FLOAT"),IDbType::dbtUNIQUE | IDbType::dbtNOT_NULL );
	} else if (typeName == wxT("DECIMAL")) {
		type = new MySqlType(wxT("DECIMAL"),IDbType::dbtUNIQUE | IDbType::dbtNOT_NULL | IDbType::dbtSIZE | IDbType::dbtSIZE_TWO);
	}  else if (typeName == wxT("BOOL")) {
		type = new MySqlType(wxT("BOOL"), 0);
	} else if (typeName == wxT("DATETIME")) {
		type = new MySqlType(wxT("DATETIME"), IDbType::dbtUNIQUE | IDbType::dbtNOT_NULL);
	} else if (typeName == wxT("TINYINT")) {
		type = new MySqlType(wxT("TINYINT"), IDbType::dbtAUTO_INCREMENT | IDbType::dbtNOT_NULL | IDbType::dbtSIZE);
	} else if (typeName == wxT("BIGINT")) {
		type = new MySqlType(wxT("BIGINT"), IDbType::dbtAUTO_INCREMENT | IDbType::dbtNOT_NULL | IDbType::dbtSIZE);
	}  else if (typeName == wxT("SMALLINT")) {
		type = new MySqlType(wxT("SMALLINT"), IDbType::dbtAUTO_INCREMENT | IDbType::dbtNOT_NULL | IDbType::dbtSIZE);
	} else if (typeName == wxT("CHAR")) {
		type = new MySqlType(wxT("CHAR"), IDbType::dbtNOT_NULL | IDbType::dbtSIZE);
	} else if (typeName == wxT("TIMESTAMP")) {
		type = new MySqlType(wxT("TIMESTAMP"), 0);
	} else if (typeName == wxT("ENUM")) {
		type = new MySqlType(wxT("ENUM"), 0);
	} else if (typeName == wxT("SET")) {
		type = new MySqlType(wxT("SET"), 0);
	} else if (typeName == wxT("LONGBLOB")) {
		type = new MySqlType(wxT("LONGBLOB"), 0);
	} else if (typeName == wxT("BLOB")) {
		type = new MySqlType(wxT("BLOB"), 0);
	} else if (typeName == wxT("MEDIUMTEXT")) {
		type = new MySqlType(wxT("MEDIUMTEXT"), IDbType::dbtNOT_NULL);
	} else if (typeName == wxT("TEXT")) {
		type = new MySqlType(wxT("TEXT"), 0);
	} else if (typeName == wxT("LONGTEXT")) {
		type = new MySqlType(wxT("LONGTEXT"), 0);
	}
	wxASSERT(type);
	return type;
}

wxArrayString* MySqlDbAdapter::GetDbTypes() {
	wxArrayString* pNames = new wxArrayString();
	pNames->Add(wxT("INT"));
	pNames->Add(wxT("SMALLINT"));
	pNames->Add(wxT("BIGINT"));
	pNames->Add(wxT("TINYINT"));
	pNames->Add(wxT("VARCHAR"));
	pNames->Add(wxT("DOUBLE"));
	pNames->Add(wxT("FLOAT"));
	pNames->Add(wxT("DECIMAL"));
	pNames->Add(wxT("BOOL"));
	pNames->Add(wxT("DATETIME"));
	pNames->Add(wxT("CHAR"));
	pNames->Add(wxT("TIMESTAMP"));
	pNames->Add(wxT("ENUM"));
	pNames->Add(wxT("SET"));
	pNames->Add(wxT("LONGBLOB"));
	pNames->Add(wxT("BLOB"));
	pNames->Add(wxT("MEDIUMTEXT"));
	pNames->Add(wxT("TEXT"));
	pNames->Add(wxT("LONGTEXT"));


	return pNames;
}
wxString MySqlDbAdapter::GetDefaultSelect(const wxString& dbName, const wxString& tableName) {
	//TODO:SQL:
	wxString ret = wxString::Format(wxT("SELECT * FROM `%s`.`%s`"), dbName.c_str(), tableName.c_str());
	return ret;
}

bool MySqlDbAdapter::GetColumns(Table* pTab) {
	DatabaseLayer* dbLayer = this->GetDatabaseLayer();

	if (!dbLayer->IsOpen()) return NULL;
	// loading columns
	//TODO:SQL:
	DatabaseResultSet *database = dbLayer->RunQueryWithResults(wxString::Format(wxT("SHOW COLUMNS IN `%s`.`%s`"),pTab->getParentName().c_str(),pTab->getName().c_str()));
	while (database->Next()) {
		IDbType* pType = parseTypeString(database->GetResultString(2));
		if (pType) {
			Column* pCol = new Column(database->GetResultString(1),pTab->getName(), pType);
			pTab->AddChild(pCol);
		}
	}
	dbLayer->CloseResultSet(database);
	dbLayer->Close();
	delete dbLayer;
	return true;
}
IDbType* MySqlDbAdapter::parseTypeString(const wxString& typeString) {
	wxString text   = typeString.Upper().Trim();
	wxString typeName ;
	//int iMezera = text.Find(wxT(" "));
	int iZavorka = text.Find(wxT("("));
	if (iZavorka == -1)typeName = text;
	else {
		typeName = text.Mid(0,iZavorka);
		text = text.Mid(iZavorka);
	}

	IDbType* type = this->GetDbTypeByName(typeName);
	if (type) {
		//TODO:Doresit enum
		if ((iZavorka > 0) && (typeName.compare(wxT("ENUM")))) {
			int iKonecZavorky = text.Find(wxT(")"));
			int iCarka = text.Find(wxT(","));
			if ((iCarka > 0) && (iCarka<iKonecZavorky)) {
				long s = 0;
				long s2 = 0;
				text.Mid(1,iCarka-1).ToLong(&s);
				text.Mid(iCarka+1, iZavorka-iCarka+1).ToLong(&s2);
				type->SetSize(s);
				type->SetSize2(s2);
				type->SetPropertyFlags(type->GetPropertyFlags() | IDbType::dbtSIZE | IDbType::dbtSIZE_TWO);
			} else {
				long s = 0;
				text.Mid(1,iKonecZavorky-1).ToLong(&s);
				type->SetSize(s);
			}
		}
	}
	return type;
}

bool MySqlDbAdapter::CanConnect() {
	return ((m_serverName != wxT(""))&&(m_userName != wxT("")));
}
void MySqlDbAdapter::GetDatabases(DbConnection* dbCon) {
	if (dbCon) {
		DatabaseLayer* dbLayer = this->GetDatabaseLayer();
		if (dbLayer) {
			if (!dbLayer->IsOpen()) return;

			// loading databases
			//TODO:SQL:
			DatabaseResultSet *databaze = dbLayer->RunQueryWithResults(wxT("SHOW DATABASES"));
			while (databaze->Next()) {
				dbCon->AddChild( new Database(this, databaze->GetResultString(1)) );
			}
			dbLayer->CloseResultSet(databaze);
			dbLayer->Close();
			delete dbLayer;
		}
	}
	return;
}

void MySqlDbAdapter::GetTables(Database* db) {
	if (db) {
		DatabaseLayer* dbLayer = this->GetDatabaseLayer();
		if (dbLayer) {
			if (!dbLayer->IsOpen()) return;
			// lading tables for database
			//TODO:SQL:
			DatabaseResultSet *tabulky = dbLayer->RunQueryWithResults(wxString::Format(wxT("SHOW TABLES IN `%s`"), db->getName().c_str()) );
			while (tabulky->Next()) {
				db->AddChild(new Table(this,  tabulky->GetResultString(1), db->getName(),0));
			}
			dbLayer->CloseResultSet(tabulky);
			dbLayer->Close();
			delete dbLayer;
		}
	}
	return;
}
wxString MySqlDbAdapter::GetCreateDatabaseSql(const wxString& dbName) {
	return wxString::Format(wxT("CREATE DATABASE `%s`"), dbName.c_str());
}
wxString MySqlDbAdapter::GetDropTableSql(Table* pTab) {
	return wxString::Format(wxT("DROP TABLE `%s`.`%s`"), pTab->getParentName().c_str(),pTab->getName().c_str());
}
