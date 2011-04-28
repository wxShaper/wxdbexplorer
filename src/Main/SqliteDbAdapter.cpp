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
DatabaseLayer* SQLiteDbAdapter::GetDatabaseLayer(const wxString& dbName) {
	DatabaseLayer* pDatabase = NULL;

#ifdef DBL_USE_SQLITE
	pDatabase = new SqliteDatabaseLayer(m_sFileName);
#endif

	return pDatabase;
}

IDbType* SQLiteDbAdapter::GetDbTypeByName(const wxString& typeName) {
	IDbType* type = NULL;
	if (typeName == wxT("NULL")) {
		type = new SqliteType(wxT("NULL"), IDbType::dbtNOT_NULL, IDbType::dbtTYPE_OTHER);
	} else if (typeName == wxT("INTEGER")) {
		type = new SqliteType(wxT("INTEGER"), IDbType::dbtNOT_NULL, IDbType::dbtTYPE_INT );
	} else if (typeName == wxT("REAL")) {
		type = new SqliteType(wxT("REAL"), IDbType::dbtNOT_NULL, IDbType::dbtTYPE_DECIMAL );
	} else if (typeName == wxT("TEXT")) {
		type = new SqliteType(wxT("TEXT"), IDbType::dbtNOT_NULL, IDbType::dbtTYPE_TEXT );
	} else if (typeName == wxT("BLOB")) {
		type = new SqliteType(wxT("BLOB"), IDbType::dbtNOT_NULL, IDbType::dbtTYPE_OTHER );
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

bool SQLiteDbAdapter::IsConnected() {
	return false;
}
wxString SQLiteDbAdapter::GetDefaultSelect(const wxString& dbName, const wxString& tableName) {
	return wxString::Format(wxT("SELECT * FROM '%s'.'%s';"),dbName.c_str(),tableName.c_str());
}
bool SQLiteDbAdapter::GetColumns(Table* pTab) {
	int i = 0;
	DatabaseLayer* dbLayer = this->GetDatabaseLayer(wxT(""));
	if (dbLayer) {
		if (!dbLayer->IsOpen()) return NULL;
		// loading columns
		//TODO:SQL:
		DatabaseResultSet *database = dbLayer->RunQueryWithResults(wxString::Format(wxT("PRAGMA table_info('%s')"),pTab->GetName().c_str()));
		while (database->Next()) {
			IDbType* pType = GetDbTypeByName(database->GetResultString(3));
			if (pType) {
				pType->SetNotNull(database->GetResultInt(4) == 1);
				Column* pCol = new Column(database->GetResultString(2),pTab->GetName(), pType);
				pTab->AddChild(pCol);
				if (database->GetResultInt(6) == 1) {
					Constraint* constr = new Constraint();
					constr->SetName(wxString::Format(wxT("PK_%s"), pTab->GetName().c_str()));
					constr->SetLocalColumn(pCol->GetName());
					constr->SetType(Constraint::primaryKey);
					pTab->AddChild(constr);
				}

			}

		}
		dbLayer->CloseResultSet(database);

		database = dbLayer->RunQueryWithResults(wxString::Format(wxT("PRAGMA foreign_key_list('%s')"),pTab->GetName().c_str()));
		while (database->Next()) {
			Constraint* constr = new Constraint();
			constr->SetName(wxString::Format(wxT("FK_%s_%i"), pTab->GetName().c_str(), i++));
			constr->SetLocalColumn(database->GetResultString(4));
			constr->SetType(Constraint::foreignKey);
			constr->SetRefTable(database->GetResultString(3));
			constr->SetRefCol(database->GetResultString(5));

			wxString onDelete = database->GetResultString(6);
			if (onDelete == wxT("RESTRICT")) constr->SetOnUpdate(Constraint::restrict);
			if (onDelete == wxT("CASCADE")) constr->SetOnUpdate(Constraint::cascade);
			if (onDelete == wxT("SET NULL")) constr->SetOnUpdate(Constraint::setNull);
			if (onDelete == wxT("NO ACTION")) constr->SetOnUpdate(Constraint::noAction);

			wxString onUpdate = database->GetResultString(7);
			if (onUpdate == wxT("RESTRICT")) constr->SetOnDelete(Constraint::restrict);
			if (onUpdate == wxT("CASCADE")) constr->SetOnDelete(Constraint::cascade);
			if (onUpdate == wxT("SET NULL")) constr->SetOnDelete(Constraint::setNull);
			if (onUpdate == wxT("NO ACTION")) constr->SetOnDelete(Constraint::noAction);


			pTab->AddChild(constr);
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
	if (dropTable) str = wxString::Format(wxT("DROP TABLE IF EXISTS '%s'; \n"),tab->GetName().c_str());
	str.append(wxString::Format(wxT("CREATE TABLE '%s' (\n"),tab->GetName().c_str()));



	SerializableList::compatibility_iterator node = tab->GetFirstChildNode();
	while( node ) {
		Column* col = NULL;
		if( node->GetData()->IsKindOf( CLASSINFO(Column)) ) col = (Column*) node->GetData();
		if(col)	str.append(wxString::Format(wxT("\t`%s` %s"),col->GetName().c_str(), col->GetPType()->ReturnSql().c_str()));

		node = node->GetNext();
		if (node) {
			Column* pc =wxDynamicCast(node->GetData(),Column);
			if (pc) str.append(wxT(",\n ")) ;
		}
	}



	bool start = true;
	node = tab->GetFirstChildNode();
	while( node ) {
		Constraint* constr = wxDynamicCast(node->GetData(),Constraint);
		if (constr) {
			if (start) {
				//str.append(wxT(",\n "));
				start = false;
			}
			if (constr->GetType() == Constraint::primaryKey) str.append(wxString::Format(wxT("\tPRIMARY KEY ('%s')"), constr->GetLocalColumn().c_str()));
			if (constr->GetType() == Constraint::foreignKey) str.append(wxString::Format(wxT("\tFOREIGN KEY('%s') REFERENCES %s('%s')"), constr->GetLocalColumn().c_str(),constr->GetRefTable().c_str(),constr->GetRefCol().c_str()));

		}

		node = node->GetNext();
		if (node) {
			constr = wxDynamicCast(node->GetData(),Constraint);
			if (constr) {
				str.append(wxT(",\n ")) ;
			}
		}
	}



	str.append(wxT(");\n"));
	str.append(wxT("-- -------------------------------------------------------------\n"));
	return str;
}



bool SQLiteDbAdapter::CanConnect() {
	return m_sFileName != wxT("");
}

void SQLiteDbAdapter::GetDatabases(DbConnection* dbCon) {
	DatabaseLayer* dbLayer = this->GetDatabaseLayer(wxT(""));
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

void SQLiteDbAdapter::GetTables(Database* db, bool includeViews) {
	DatabaseLayer* dbLayer = this->GetDatabaseLayer(wxT(""));
	if (dbLayer) {
		if (!dbLayer->IsOpen()) return;
		//TODO:SQL:
		
		DatabaseResultSet *tabulky = NULL;
		if (includeViews){
			tabulky= dbLayer->RunQueryWithResults(wxString::Format(wxT("SELECT * FROM '%s'.sqlite_master WHERE type='table' OR type='view'"), db->GetName().c_str()) );
		}else{			
			tabulky= dbLayer->RunQueryWithResults(wxString::Format(wxT("SELECT * FROM '%s'.sqlite_master WHERE type='table'"), db->GetName().c_str()) );
			}
		
		
		while (tabulky->Next()) {
			db->AddChild(new Table(this, tabulky->GetResultString(2), db->GetName(), tabulky->GetResultString(wxT("type")).Contains(wxT("view"))));
		}
		dbLayer->CloseResultSet(tabulky);


		tabulky = dbLayer->RunQueryWithResults(wxString::Format(wxT("SELECT * FROM '%s'.sqlite_master WHERE type='view'"), db->GetName().c_str()) );
		while (tabulky->Next()) {
			wxString select = tabulky->GetResultString(5);
			select = select.Mid(select.Find(wxT("SELECT")));
			db->AddChild(new View(this, tabulky->GetResultString(2), db->GetName(),select));
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
	return wxString::Format(wxT("DROP TABLE '%s'.'%s'"), pTab->GetParentName().c_str(), pTab->GetName().c_str());
}
wxString SQLiteDbAdapter::GetAlterTableConstraintSql(Table* tab) {
	return wxT("");
}
wxString SQLiteDbAdapter::GetDropDatabaseSql(Database* pDb) {
	return wxT("");
}
wxString SQLiteDbAdapter::GetUseDb(const wxString& dbName) {
	return wxT("");
}
void SQLiteDbAdapter::GetViews(Database* db) {
}
wxString SQLiteDbAdapter::GetCreateViewSql(View* view, bool dropView) {
	wxString str = wxT("");
	if (view) {
		if (dropView) {
			str.append(wxString::Format(wxT("DROP VIEW IF EXISTS `%s`;\n"),view->GetName().c_str()));
		}
		str.append(wxString::Format(wxT("CREATE VIEW `%s` AS %s ;\n"),view->GetName().c_str(), view->GetSelect().c_str()));
	}
	str.append(wxT("-- -------------------------------------------------------------\n"));
	return str;
}
void SQLiteDbAdapter::ConvertTable(Table* pTab) {
	SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
	while( node ){
		if( node->GetData()->IsKindOf( CLASSINFO(Column)) )  {
			Column* col = (Column*) node->GetData();			
			col->SetPType(ConvertType(col->GetPType()));
			}
		node = node->GetNext();
		}	
}

IDbType* SQLiteDbAdapter::ConvertType(IDbType* pType) {
	SqliteType* newType = wxDynamicCast(pType, SqliteType);
	if (!newType ){
		newType = (SqliteType*) GetDbTypeByUniversalName(pType->GetUniversalType());	
		delete pType;
		pType = NULL;
	}
	return newType;
}
IDbType* SQLiteDbAdapter::GetDbTypeByUniversalName(IDbType::UNIVERSAL_TYPE type) {
	IDbType* newType = NULL;
	switch (type) {
		case IDbType::dbtTYPE_INT:
			newType = GetDbTypeByName(wxT("INTEGER"));
			break;
		case IDbType::dbtTYPE_BOOLEAN:
			newType = GetDbTypeByName(wxT("INTEGER"));
			break;
		case IDbType::dbtTYPE_DATE_TIME:
			newType = GetDbTypeByName(wxT("TEXT"));
			break;
		case IDbType::dbtTYPE_DECIMAL:
			newType = GetDbTypeByName(wxT("REAL"));
			break;
		case IDbType::dbtTYPE_FLOAT:
			newType = GetDbTypeByName(wxT("REAL"));
			break;
		case IDbType::dbtTYPE_TEXT:
			newType = GetDbTypeByName(wxT("TEXT"));
			break;
		case IDbType::dbtTYPE_OTHER:
			newType = GetDbTypeByName(wxT("BLOB"));
			break;
	}
	return newType;
}
IDbAdapter* SQLiteDbAdapter::Clone()
{
	return new SQLiteDbAdapter(m_sFileName);
}

