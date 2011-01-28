#include "DbViewerPanel.h"
#include "DbSettingDialog.h"
#include "SqlCommandPanel.h"
#include "ErdPanel.h"

#include <wx/propgrid/propgrid.h>
#include <wx/imaglist.h>
DbViewerPanel::DbViewerPanel(wxWindow *parent, wxAuiNotebook* notebook):_DbViewerPanel(parent) {
	m_pNotebook = notebook;
	m_pDbAdapter = NULL;
	m_pConnections = new xsSerializable();
}

DbViewerPanel::~DbViewerPanel() {
	//if ((m_pDbConnector != NULL)&&(m_pDbConnector->IsConnected())) m_pDbConnector->CloseConnection();
	//delete m_pDbConnector;
	delete m_pDbAdapter;
}

void DbViewerPanel::OnConncectClick(wxCommandEvent& event) {
	DbSettingDialog dlg(this);
	dlg.ShowModal();
	RefreshDbView();
}
void DbViewerPanel::OnConncectUI(wxUpdateUIEvent& event) {
	if (m_pDbAdapter == NULL ) event.Enable(true);
	//else event.Enable(false);
}
void DbViewerPanel::OnItemActivate(wxTreeEvent& event) {
	DbItem* item = (DbItem*) m_treeDatabases->GetItemData(event.GetItem());
	if ((item != NULL)&&(item->GetTable() != NULL)) {
		Table* table = item->GetTable();
		wxString dbName = table->getParentName();
		wxString dbTable = table->getName();
		m_pNotebook->AddPage(new SQLCommandPanel(m_pNotebook,m_pDbAdapter,dbName,dbTable),dbName,true);

	}
}
void DbViewerPanel::OnRefreshClick(wxCommandEvent& event) {
	RefreshDbView();
}
void DbViewerPanel::RefreshDbView() {
	// clear items from tree
	m_treeDatabases->DeleteAllItems();
	// create imageList for icons
	wxImageList *pImageList = new wxImageList(16,16,true,3);
	pImageList->Add(wxIcon(folder_xpm));						// folder icon
	pImageList->Add(wxIcon(form_blue_xpm));						// table icon
	m_treeDatabases->SetImageList(pImageList);

	wxTreeItemId totalRootID = m_treeDatabases->AddRoot(wxString::Format(wxT("Databases")),-1);

	// ---------------- load connections ----------------------------
	SerializableList::compatibility_iterator connectionNode = m_pConnections->GetFirstChildNode();
	while(connectionNode) {
		DbConnection* pDbCon = wxDynamicCast(connectionNode->GetData(),DbConnection);
		if (pDbCon) {
			wxTreeItemId rootID = m_treeDatabases->AppendItem(totalRootID,wxString::Format(wxT("Databases (%s)"),pDbCon->GetServerName().c_str()),-1);

			// ----------------------- load databases -------------------------------
			SerializableList::compatibility_iterator dbNode = pDbCon->GetFirstChildNode();
			while(dbNode) {
				Database* pDatabase = wxDynamicCast(dbNode->GetData(), Database);
				if (pDatabase) {
					wxTreeItemId dbID = m_treeDatabases->AppendItem(rootID,pDatabase->getName(),-1,-1, new DbItem(pDatabase,NULL));//new DbDatabase(db->getName()));
					m_treeDatabases->Expand(rootID);
					wxTreeItemId idFolder = m_treeDatabases->AppendItem(dbID, wxT("Tables"),0);
					m_treeDatabases->Expand(dbID);

					// ----------------------------- load tables ----------------------------------
					SerializableList::compatibility_iterator tabNode = pDatabase->GetFirstChildNode();
					while(tabNode) {
						Table* pTable = wxDynamicCast(tabNode->GetData(), Table);
						if (pTable) {
							wxTreeItemId tabID = m_treeDatabases->AppendItem(idFolder,pTable->getName(),1,-1,new DbItem(NULL,pTable)); //NULL);
						}
						tabNode = tabNode->GetNext();
					}
					// ----------------------------------------------------------------------------
				}
				dbNode = dbNode->GetNext();
			}
			// -----------------------------------------------------------------------
		}
		connectionNode = connectionNode->GetNext();
	}





	/*	// add root item
		wxTreeItemId rootID = m_treeDatabases->AddRoot(wxString::Format(wxT("Databases (%s)"),m_server.GetData()),-1);



		for (int i = 0 ; i<dbCol->GetDbCount(); i++) {
			Database *db = dbCol->GetByIndex(i);
			wxTreeItemId dbID = m_treeDatabases->AppendItem(rootID,db->getName(),-1,-1, new DbItem(db,NULL));//new DbDatabase(db->getName()));
			m_treeDatabases->Expand(rootID);
			wxTreeItemId idFolder = m_treeDatabases->AppendItem(dbID, wxT("Tables"),0);
			m_treeDatabases->Expand(dbID);
			if (db->tables) {
				for (int tabC = 0; tabC < db->tables->GetTableCount(); tabC++) {
					Table *tab =  db->tables->GetByIndex(tabC);
					wxTreeItemId tabID = m_treeDatabases->AppendItem(idFolder,tab->getName(),1,-1,new DbItem(NULL,tab)); //NULL);
				}
			}
		}*/


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
	if (m_pDbAdapter) {
		m_pNotebook->AddPage(new ErdPanel(m_pNotebook, m_pDbAdapter),wxT("ERD diagram"));
	}
}
void DbViewerPanel::OnDnDStart(wxTreeEvent& event) {
	ShapeList lstDnD;
	lstDnD.DeleteContents(true);


	DbItem* item = (DbItem*) m_treeDatabases->GetItemData(event.GetItem());
	if ((item != NULL)&&(item->GetTable() != NULL)) {
		Table* table =(Table*)((Table*)item->GetTable())->Clone();

		wxSFShapeBase *pShape = new dndTableShape(table);
		lstDnD.Append(pShape);

		if (m_pNotebook->GetSelection()!= wxNOT_FOUND) {

			ErdPanel* panel = wxDynamicCast(m_pNotebook->GetPage(m_pNotebook->GetSelection()), ErdPanel);
			panel->getCanvas()->DoDragDrop(lstDnD);
		}
		//delete pShape;
	}
}
void DbViewerPanel::OnItemRightClick(wxTreeEvent& event) {



}
void DbViewerPanel::OnToolCloseClick(wxCommandEvent& event) {
}

void DbViewerPanel::OnToolCloseUI(wxUpdateUIEvent& event) {
}
