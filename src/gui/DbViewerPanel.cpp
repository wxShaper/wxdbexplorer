#include "DbViewerPanel.h"
#include "DbSettingDialog.h"
#include "SqlCommandPanel.h"
#include "ErdPanel.h"

#include <wx/propgrid/propgrid.h>
#include <wx/imaglist.h>
DbViewerPanel::DbViewerPanel(wxWindow *parent, wxAuiNotebook* notebook):_DbViewerPanel(parent) {
	m_pNotebook = notebook;
	//m_pDbLayer = NULL;
	m_pDbConnector = NULL;
}

DbViewerPanel::~DbViewerPanel() {
	//if ((m_pDbLayer != NULL)&&(m_pDbLayer->IsOpen())) m_pDbLayer->Close();
	//delete m_pDbLayer;
	if ((m_pDbConnector != NULL)&&(m_pDbConnector->IsConnected())) m_pDbConnector->CloseConnection();
	delete m_pDbConnector;
}

void DbViewerPanel::OnConncectClick(wxCommandEvent& event) {
	DbSettingDialog dlg(this);
	dlg.ShowModal();
	RefreshDbView();
}
void DbViewerPanel::OnConncectUI(wxUpdateUIEvent& event) {
	//if (m_pDbLayer == NULL) event.Enable(true);
	if (m_pDbConnector == NULL) event.Enable(true);

	//else event.Enable(false);
}
void DbViewerPanel::OnItemActivate(wxTreeEvent& event) {
	DbItem* item = (DbItem*) m_treeDatabases->GetItemData(event.GetItem());
	if ((item != NULL)&&(item->GetTable() != NULL)) {
		Table* table = item->GetTable();
		wxString dbName = table->getParentName();
		wxString dbTable = table->getName();
		m_pNotebook->AddPage(new SQLCommandPanel(m_pNotebook,dbName,m_pDbAdapter->GetDatabaseLayer(),dbTable),dbName,true);

	}

	/*DbTable* table = (DbTable*) m_treeDatabases->GetItemData(event.GetItem());


	if ((table!=NULL)&&(table->GetType() == DbTableType)) {

		wxString dbName = table->GetParentName();
		wxString dbTable = table->GetName();
		//m_pNotebook->AddPage(new SQLCommandPanel(m_pNotebook,dbName,m_pDbLayer,dbTable),dbName,true);
		m_pNotebook->AddPage(new SQLCommandPanel(m_pNotebook,dbName,m_pDbConnector->GetDatabaseLayer(),dbTable),dbName,true);

	}
	//	m_propertyGrid->Append(wxT("Nova"));*/
}
void DbViewerPanel::OnRefreshClick(wxCommandEvent& event) {
	RefreshDbView();
}
void DbViewerPanel::RefreshDbView() {
	DatabaseCol* dbCol = this->m_pDbAdapter->GetDatabases();


	// clear items from tree
	m_treeDatabases->DeleteAllItems();
	// create imageList for icons
	wxImageList *pImageList = new wxImageList(16,16,true,3);
	pImageList->Add(wxIcon(folder_xpm));						// folder icon
	pImageList->Add(wxIcon(form_blue_xpm));						// table icon
	m_treeDatabases->SetImageList(pImageList);

	// add root item
	wxTreeItemId rootID = m_treeDatabases->AddRoot(wxString::Format(wxT("Databases (%s)"),m_server.GetData()),0);



	for (int i = 0 ; i<dbCol->GetDbCount(); i++) {
		Database *db = dbCol->GetByIndex(i);
		wxTreeItemId dbID = m_treeDatabases->AppendItem(rootID,db->getName(),0,-1, new DbItem(db,NULL));//new DbDatabase(db->getName()));
		m_treeDatabases->Expand(rootID);
		wxTreeItemId idFolder = m_treeDatabases->AppendItem(dbID, wxT("Tables"),0);
		m_treeDatabases->Expand(dbID);
		for (int tabC = 0; tabC < db->tables->GetTableCount(); tabC++) {
			Table *tab =  db->tables->GetByIndex(tabC);
			wxTreeItemId tabID = m_treeDatabases->AppendItem(idFolder,tab->getName(),1,-1,new DbItem(NULL,tab)); //NULL);
		}
	}


	/*DatabaseResultSet *tabulky;
	//if ((m_pDbLayer != NULL)&&(m_pDbLayer->IsOpen())) {
	if ((m_pDbConnector != NULL)&&(m_pDbConnector->IsConnected())) {
		try{
			// clear items from tree
			m_treeDatabases->DeleteAllItems();

			// create imageList for icons
			wxImageList *pImageList = new wxImageList(16,16,true,3);
			pImageList->Add(wxIcon(folder_xpm));						// folder icon
			pImageList->Add(wxIcon(form_blue_xpm));						// table icon
			m_treeDatabases->SetImageList(pImageList);

			// add root item
			wxTreeItemId rootID = m_treeDatabases->AddRoot(wxString::Format(wxT("Databases (%s)"),m_server.GetData()),0);


			// loading databases
			//TODO:SQL:
			//DatabaseResultSet *databaze = m_pDbLayer->RunQueryWithResults(wxT("SHOW DATABASES"));
			//while (databaze->Next()) {
			//	wxString dbName = databaze->GetResultString(1);
			//	wxTreeItemId dbID = m_treeDatabases->AppendItem(rootID,dbName,0,-1,new DbDatabase(dbName));
			//}
			//m_pDbLayer->CloseResultSets();

			wxArrayString databases = m_pDbConnector->GetDatabases();
			for (int i =0 ; i< databases.Count(); i++){
				wxTreeItemId dbID = m_treeDatabases->AppendItem(rootID,databases[i],0,-1,new DbDatabase(databases[i]));
				}
			m_treeDatabases->Expand(rootID);

			// define items for browsing databases
			wxTreeItemIdValue  cookie;
			wxTreeItemId dbID = m_treeDatabases->GetFirstChild(rootID,cookie);

			//TODO:SQL:
			while (dbID.IsOk()) {
				DbDatabase* dbData = (DbDatabase*) m_treeDatabases->GetItemData(dbID);

				// add virtual folder "tables"
				wxTreeItemId idFolder = m_treeDatabases->AppendItem(dbID, wxT("Tables"),0);
				m_treeDatabases->Expand(dbID);

				// lading tables for database
				//TODO:SQL:
	//				tabulky = m_pDbLayer->RunQueryWithResults( wxT("SHOW TABLES IN ") + dbData->GetParentName() );
	//				while (tabulky->Next()) {
	//					wxString databaseName = dbData->GetParentName();
	//					wxString tableName = tabulky->GetResultString(1);
	//					wxTreeItemId id = m_treeDatabases->AppendItem(idFolder,tableName, 1, -1, new DbTable( tableName, databaseName));
	//					m_hashTables[databaseName+wxT("-")+tableName] = id;
	//				}
	//				m_pDbLayer->CloseResultSet(tabulky);
	//				dbID = m_treeDatabases->GetNextChild(rootID, cookie);
				wxString databaseName = dbData->GetParentName();
				wxArrayString tables = m_pDbConnector->GetTablses(databaseName);
				for (int i=0; i<tables.Count(); ++i){
					wxTreeItemId id = m_treeDatabases->AppendItem(idFolder,tables[i], 1, -1, new DbTable( tables[i], databaseName));
					m_hashTables[databaseName+wxT("-")+tables[i]] = id;
					}
				dbID = m_treeDatabases->GetNextChild(rootID, cookie);
				}
	//			m_pDbLayer->CloseResultSets();


			TableHashMap::iterator it;
			for( it = m_hashTables.begin(); it != m_hashTables.end(); ++it )
			{
				//wxString key = it->first, value = it->second;
				wxTreeItemId id = it->second;
				if (id.IsOk()){
					IDbItem* tabData = (DbTable* ) m_treeDatabases->GetItemData(id);
					//wxString query = wxT("SHOW COLUMNS IN " ) + tabData->GetParentName() + wxT(".") + tabData->GetName();
					//wxMessageBox(query);
					//wxString query2 = wxT("SHOW COLUMNS IN TestDb.Jmena");
					//DatabaseResultSet *cols = m_pDbLayer->RunQueryWithResults(query);
					//DatabaseResultSet *cols = m_pDbConnector->GetDatabaseLayer()->RunQueryWithResults(query);
					DatabaseResultSet *cols = m_pDbConnector->GetTableInfo(tabData->GetParentName(),tabData->GetName());
					while (cols->Next()){
						DbColumn* col = new DbColumn(tabData->GetName(),cols->GetResultString(1),cols->GetResultString(2),cols->GetResultString(3), cols->GetResultString(4));
						m_treeDatabases->AppendItem(id,cols->GetResultString(1),-1,-1,col);
						}
					//m_pDbLayer->CloseResultSet(cols);
					m_pDbConnector->GetDatabaseLayer()->CloseResultSet(cols);
					}
				// do something useful with key and value
			}


			//m_pDbLayer->CloseResultSets();
			m_pDbConnector->GetDatabaseLayer()->CloseResultSets();
		} catch (DatabaseLayerException& e){
			wxMessageBox(e.GetErrorMessage());
			}
	}*/
}

void DbViewerPanel::OnItemSelectionChange(wxTreeEvent& event) {
	/*
	// clear propertyGrid
	m_propertyGrid->Clear();
	m_propertyGrid->AppendCategory(wxT("Basic info"));

	// expand selected item
	m_treeDatabases->Expand(event.GetItem());

	// getting selected item data
	wxTreeItemData* data = m_treeDatabases->GetItemData(event.GetItem());

	// showing parameter in propertyGrid
	if ((data != NULL)){
		switch(((IDbItem* )data)->GetType()){
			case DbTableType:
				m_propertyGrid->Append(wxT("Table name"),wxPG_LABEL,((IDbItem* )data)->GetName());
				m_propertyGrid->Append(wxT("Database name"),wxPG_LABEL,((IDbItem* )data)->GetParentName());

				break;
			case DbColumnType:
				m_propertyGrid->Append(wxT("Column name"),wxPG_LABEL, ((IDbItem* )data)->GetName());
				m_propertyGrid->Append(wxT("Table name"),wxPG_LABEL, ((IDbItem* )data)->GetParentName());
				m_propertyGrid->AppendCategory(wxT("Parameters"));
				m_propertyGrid->Append(wxT("Type"),wxPG_LABEL, ((DbColumn* )data)->GetColumnType());
				m_propertyGrid->Append(wxT("Not null"),wxPG_LABEL, ((DbColumn* )data)->IsNotNull());
				m_propertyGrid->Append(wxT("Primary key"),wxPG_LABEL, ((DbColumn* )data)->IsPrimaryKey());
				m_propertyGrid->Append(wxT("Foreign key"),wxPG_LABEL, ((DbColumn* )data)->IsForeignKey());


				break;
			case DbDatabaseType:
				m_propertyGrid->Append(wxT("DB name"),wxPG_LABEL,((IDbItem* )data)->GetName());
				break;
			}
	}	*/
}
void DbViewerPanel::OnERDClick(wxCommandEvent& event) {
	if (m_pDbAdapter){
		m_pNotebook->AddPage(new ErdPanel(m_pNotebook, m_pDbAdapter),wxT("ERD diagram"));
		}
}
