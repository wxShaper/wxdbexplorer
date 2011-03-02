#include "DbViewerPanel.h"
#include "DbSettingDialog.h"
#include "SqlCommandPanel.h"
#include "ErdPanel.h"
#include "AdapterSelectDlg.h"

#include <wx/wfstream.h>
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
	if (item){
		if (Table* tab =  wxDynamicCast(item->GetData(), Table)){
			wxString dbName = tab->getParentName();
			wxString dbTable = tab->getName();
			m_pNotebook->AddPage(new SQLCommandPanel(m_pNotebook,tab->GetDbAdapter(),dbName,dbTable),dbName,true);			
			}	
		if (View* pView = wxDynamicCast(item->GetData(), View)){
			m_pNotebook->AddPage(new SQLCommandPanel(m_pNotebook,pView->GetDbAdapter(),pView->GetParentName(),pView->GetName()),pView->GetParentName(),true);
			}
	
		
		if (Database* db = wxDynamicCast(item->GetData(), Database)){
			wxMouseState cState = wxGetMouseState();
			if( cState.ControlDown() ){
				m_pNotebook->AddPage(new ErdPanel(m_pNotebook,db->getDbAdapter(),db),db->getName(),true);
			}else{
				m_pNotebook->AddPage(new SQLCommandPanel(m_pNotebook,db->getDbAdapter(),db->getName(),wxT("")),db->getName(),true);	
				}
			}	
		}
	
	
/*	if ((item != NULL)&&(item->GetTable() != NULL)) {
		Table* table = item->GetTable();
		wxString dbName = table->getParentName();
		wxString dbTable = table->getName();
		m_pNotebook->AddPage(new SQLCommandPanel(m_pNotebook,m_pDbAdapter,dbName,dbTable),dbName,true);

	}*/
}
void DbViewerPanel::OnRefreshClick(wxCommandEvent& event) {
	
	DbItem* data = (DbItem*) m_treeDatabases->GetItemData(m_treeDatabases->GetSelection());
	if (data){
		DbConnection* pCon = wxDynamicCast(data->GetData(), DbConnection);
		if (pCon) pCon->RefreshChildren();
		Database* pDb = wxDynamicCast(data->GetData(),Database);
		if (pDb) pDb->RefreshChildren();
		Table* pTab = wxDynamicCast(data->GetData(), Table);
		if (pTab) pTab->RefreshChildren();
		
		}
	
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
		DbConnection* pDbCon = (DbConnection*) wxDynamicCast(connectionNode->GetData(),DbConnection);
		if (pDbCon) {
			wxTreeItemId rootID = m_treeDatabases->AppendItem(totalRootID,wxString::Format(wxT("Databases (%s)"),pDbCon->GetServerName().c_str()),-1,-1, new DbItem(pDbCon));

			// ----------------------- load databases -------------------------------
			SerializableList::compatibility_iterator dbNode = pDbCon->GetFirstChildNode();
			while(dbNode) {
				Database* pDatabase = wxDynamicCast(dbNode->GetData(), Database);
				if (pDatabase) {
					//wxTreeItemId dbID = m_treeDatabases->AppendItem(rootID,pDatabase->getName(),-1,-1, new DbItem(pDatabase,NULL));//new DbDatabase(db->getName()));
					wxTreeItemId dbID = m_treeDatabases->AppendItem(rootID,pDatabase->getName(),-1,-1, new DbItem(pDatabase));//new DbDatabase(db->getName()));
					m_treeDatabases->Expand(rootID);
					wxTreeItemId idFolder = m_treeDatabases->AppendItem(dbID, wxT("Tables"),0,0,NULL);
					//m_treeDatabases->Expand(dbID);

					// ----------------------------- load tables ----------------------------------
					SerializableList::compatibility_iterator tabNode = pDatabase->GetFirstChildNode();
					while(tabNode) {
						Table* pTable = wxDynamicCast(tabNode->GetData(), Table);
						if (pTable) {
							//wxTreeItemId tabID = m_treeDatabases->AppendItem(idFolder,pTable->getName(),1,-1,new DbItem(NULL,pTable)); //NULL);
							wxTreeItemId tabID = m_treeDatabases->AppendItem(idFolder,pTable->getName(),1,-1,new DbItem(pTable)); //NULL);
						}
						tabNode = tabNode->GetNext();
					}
					// ----------------------------------------------------------------------------
					
					
					idFolder = m_treeDatabases->AppendItem(dbID, wxT("Views"),0,0,NULL);
					//m_treeDatabases->Expand(dbID);

					// ----------------------------- load tables ----------------------------------
					tabNode = pDatabase->GetFirstChildNode();
					while(tabNode) {
						View* pView = wxDynamicCast(tabNode->GetData(),View);
						if (pView) {
							//wxTreeItemId tabID = m_treeDatabases->AppendItem(idFolder,pTable->getName(),1,-1,new DbItem(NULL,pTable)); //NULL);
							wxTreeItemId tabID = m_treeDatabases->AppendItem(idFolder,pView->GetName(),1,-1,new DbItem(pView)); //NULL);
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
	AdapterSelectDlg dlg(this, m_pNotebook);
	dlg.ShowModal();
	if (m_pDbAdapter) {
		

		
		
		//m_pNotebook->AddPage(new ErdPanel(m_pNotebook, m_pDbAdapter),wxT("ERD diagram"));
	}
}
void DbViewerPanel::OnDnDStart(wxTreeEvent& event) {
	ShapeList lstDnD;
	lstDnD.DeleteContents(true);


	DbItem* item = (DbItem*) m_treeDatabases->GetItemData(event.GetItem());
	
	
	if (item != NULL) {
		Table* table = wxDynamicCast(item->GetData(),Table);
		if (table){
			if (m_pNotebook->GetSelection()!= wxNOT_FOUND) {
				table = (Table*) table->Clone();
				wxSFShapeBase *pShape = new dndTableShape(table);
				lstDnD.Append(pShape);
				ErdPanel* panel = wxDynamicCast(m_pNotebook->GetPage(m_pNotebook->GetSelection()), ErdPanel);
				panel->getCanvas()->DoDragDrop(lstDnD);
				}				
			}
		//delete pShape;
	}
}
void DbViewerPanel::OnItemRightClick(wxTreeEvent& event) {
	//TODO:LANG:nekolikrat
	m_pEditedDatabase = NULL;
	m_pEditedConnection = NULL;
	DbItem* item = (DbItem*) m_treeDatabases->GetItemData(event.GetItem());
	wxMenu menu;
	int c = 0;
	if (item) {
		Database* db = wxDynamicCast(item->GetData(),Database);
		if (db) { 
			menu.Append(IDR_DBVIEWER_ADD_TABLE,wxT("Add table"),wxT("Run SQL command for creating Table"));
			menu.Append(IDR_DBVIEWER_DROP_DATABASE, wxT("Drop database"), wxT("Run SQL command for deleting Database"));
			c++;
			menu.AppendSeparator();
			menu.Append(IDR_DBVIEWER_ERD_DB, wxT("Create ERD from DB"),wxT("Create ERD diagram from database"));
			c++;
			menu.AppendSeparator();
			menu.Append(IDR_DBVIEWER_IMPORT_DATABASE, wxT("Import database from file"), wxT("Run SQL commands stored in *.sql file"));
			menu.Append(IDR_DBVIEWER_EXPORT_DATABASE, wxT("Export database to file"), wxT("Export database CREATE SQL statements into *.sql file"));
			c++;

			c++;
			m_pEditedDatabase = db;
			}
			
		DbConnection* con = wxDynamicCast(item->GetData(), DbConnection);
		if (con){
			menu.Append(IDR_DBVIEWER_ADD_DATABASE, wxT("Add database"),wxT("Run SQL command for create DB"));
			
			c++;
			
			m_pEditedConnection = con;
			}
		
		Table* tab = wxDynamicCast(item->GetData(), Table);
		if (tab){
			menu.Append(IDR_DBVIEWER_DROP_TABLE,wxT("Drop table"),wxT("Run SQL command for deleting Table"));
			c++;
			menu.AppendSeparator();
			menu.Append(IDR_DBVIEWER_ERD_TABLE, wxT("Create ERD from Table"),wxT("Create ERD diagram from table"));
			c++;			
		}
	}
		
	if ( c > 0 ) {
		menu.Connect(wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&DbViewerPanel::OnPopupClick, NULL, this);
		PopupMenu(&menu);	
		}
			

}
void DbViewerPanel::OnToolCloseClick(wxCommandEvent& event) {
	
	// getting selected item data
	DbItem* data = (DbItem*) m_treeDatabases->GetItemData(m_treeDatabases->GetSelection());
	if (data){
		DbConnection* pCon = wxDynamicCast(data->GetData(), DbConnection);
		if (pCon) {
			wxMessageDialog dlg(this,wxT("Close connection?"),wxT("Close"),wxYES_NO);		
			if (dlg.ShowModal() == wxID_YES){
				m_pConnections->GetChildrenList().DeleteContents(true);
				m_pConnections->GetChildrenList().DeleteObject(pCon);				
				RefreshDbView();				
				}
			}
		}
}

void DbViewerPanel::OnToolCloseUI(wxUpdateUIEvent& event) {	
	event.Enable(false);
	// getting selected item data
	DbItem* data = (DbItem*) m_treeDatabases->GetItemData(m_treeDatabases->GetSelection());
	if (data){
		DbConnection* pCon = wxDynamicCast(data->GetData(), DbConnection);
		if (pCon) event.Enable(true);		
		}
}
void DbViewerPanel::OnPopupClick(wxCommandEvent& evt)
{
	try{
		switch(evt.GetId()) {
			case IDR_DBVIEWER_ADD_TABLE: {
				//TODO:LANG:
				wxString tabName = wxGetTextFromUser(wxT("Table name"),wxT("New table"),wxT("NewTab"));
				
				}
				break;
			case IDR_DBVIEWER_ADD_DATABASE: {
				if (m_pEditedConnection){
					//TODO:LANG:
					wxString dbName = wxGetTextFromUser(wxT("Database name"), wxT("Add database"));
					if (!dbName.IsEmpty()){					
						DatabaseLayer* pDbLayer = m_pEditedConnection->GetDbAdapter()->GetDatabaseLayer();
						pDbLayer->RunQuery(m_pEditedConnection->GetDbAdapter()->GetCreateDatabaseSql(dbName));
						pDbLayer->Close();
						delete pDbLayer;
						//TODO:LANG:
						wxMessageBox(wxT("Database created succesfuly"));
						
						m_pEditedConnection->RefreshChildren();
						RefreshDbView();
						
						}		
					}
				}
				break;
			case IDR_DBVIEWER_DROP_DATABASE:{
				DbItem* data = (DbItem*) m_treeDatabases->GetItemData(m_treeDatabases->GetSelection());
				if (data){
					Database* pDb = (Database*) wxDynamicCast(data->GetData(),Database);
					if (pDb){
						wxMessageDialog dlg(this, wxString::Format(wxT("Remove database '%s'?"),pDb->getName().c_str()),wxT("Drop database"),wxYES_NO);
						if (dlg.ShowModal() == wxID_YES){
							DatabaseLayer* pDbLayer = pDb->getDbAdapter()->GetDatabaseLayer();
							pDbLayer->RunQuery(pDb->getDbAdapter()->GetDropDatabaseSql(pDb));
							pDbLayer->Close();
							delete pDbLayer;
							//TODO:LANG:
							wxMessageBox(wxT("Database dropped succesfuly"));
							
							DbConnection* pCon = wxDynamicCast(pDb->GetParent(), DbConnection);
							if (pCon) pCon->RefreshChildren();
							RefreshDbView();	
							}						
						}			
					}
				}
				break;
			case IDR_DBVIEWER_ERD_TABLE:{
				DbItem* data = (DbItem*) m_treeDatabases->GetItemData(m_treeDatabases->GetSelection());
				if (data){
					Table* pTab = (Table*) wxDynamicCast(data->GetData(),Table);
					if (pTab){
							m_pNotebook->AddPage(new ErdPanel(this,pTab->GetDbAdapter(),(Table*) pTab->Clone() ),wxT("ERD diagram"),true);
						}					
					}
				}
				break;
			case IDR_DBVIEWER_ERD_DB:{
				DbItem* data = (DbItem*) m_treeDatabases->GetItemData(m_treeDatabases->GetSelection());
				if (data){
					Database* pDb = (Database*) wxDynamicCast(data->GetData(),Database);
					if (pDb){
							m_pNotebook->AddPage(new ErdPanel(this,pDb->getDbAdapter(),(Database*) pDb->Clone() ),wxT("ERD diagram"),true);
						}					
					}
				}
				break;
			case IDR_DBVIEWER_DROP_TABLE:{
				DbItem* data = (DbItem*) m_treeDatabases->GetItemData(m_treeDatabases->GetSelection());
				if (data){
					Table* pTab = (Table*) wxDynamicCast(data->GetData(),Table);
					if (pTab){
						wxMessageDialog dlg(this, wxString::Format(wxT("Remove table '%s'?"),pTab->getName().c_str()),wxT("Drop table"),wxYES_NO);
						if (dlg.ShowModal() == wxID_YES){
							DatabaseLayer* pDbLayer = pTab->GetDbAdapter()->GetDatabaseLayer();
							pDbLayer->RunQuery(pTab->GetDbAdapter()->GetDropTableSql(pTab));
							pDbLayer->Close();
							delete pDbLayer;
							//TODO:LANG:
							wxMessageBox(wxT("Table dropped succesfuly"));
							
							Database* pDb = wxDynamicCast(pTab->GetParent(), Database);
							if (pDb) pDb->RefreshChildren();
							RefreshDbView();						
							}					
						}					
					}
				}
				break;
			case IDR_DBVIEWER_IMPORT_DATABASE:{
				DbItem* data = (DbItem*) m_treeDatabases->GetItemData(m_treeDatabases->GetSelection());
				if (data){
					Database* pDb = (Database*) wxDynamicCast(data->GetData(),Database);
					if (pDb){				
						wxFileDialog dlg(this, wxT("Import database from SQL file ..."), wxGetCwd(), wxT(""), wxT("SQL Files (*.sql)|*.sql"), wxOPEN | wxFILE_MUST_EXIST);
						if(dlg.ShowModal() == wxID_OK) {							
							ImportDb(dlg.GetPath(), pDb);
							}				
						}			
					}
				}
				break;			
			default:{
				wxMessageBox(wxT("Sorry, requested feature isn't implemented yet. "),wxT("Sorry"));
				}
				break;
		}
	}
	catch (DatabaseLayerException& e)
	{
		wxString errorMessage = wxString::Format(_("Error (%d): %s"), e.GetErrorCode(), e.GetErrorMessage().c_str());
		wxMessageDialog dlg(this,errorMessage,wxT("DB Error"),wxOK | wxCENTER | wxICON_ERROR);
		dlg.ShowModal();
	}
	catch( ... )
	{
		wxMessageDialog dlg(this,wxT("Unknown error."),wxT("DB Error"),wxOK | wxCENTER | wxICON_ERROR);
		dlg.ShowModal();
	}		
}

bool DbViewerPanel::ImportDb(const wxString& sqlFile, Database* pDb)
{
	DatabaseLayer* pDbLayer = NULL;
	LogDialog dialog(this);
	dialog.Show();
	
	try{
		wxFileInputStream input(sqlFile);
		wxTextInputStream text( input );	
		text.SetStringSeparators(wxT(";"));
		wxString command = wxT("");
		pDbLayer = pDb->getDbAdapter()->GetDatabaseLayer();
		pDbLayer->BeginTransaction();
		pDbLayer->RunQuery(wxString::Format(wxT("USE %s"), pDb->getName().c_str()));
	
		while (!input.Eof()){
			wxString line = text.ReadLine();			
			//dialog.AppendText(line);
			int index = line.Find(wxT("--"));
			if (index != wxNOT_FOUND) line = line.Mid(0,index);
			command.append(line);
			if (line.Find(wxT(";")) != wxNOT_FOUND){
				dialog.AppendSeparator();
				dialog.AppendComment(wxT("Run SQL command:"));
				dialog.AppendText(command);		
				pDbLayer->RunQuery(command);
				dialog.AppendComment(wxT("Succesful!"));			
				command.clear();				
				} 	
			}	
		pDbLayer->Commit();
		pDbLayer->Close();
		}
	catch (DatabaseLayerException& e)
	{
		if (pDbLayer){
			pDbLayer->RollBack();
			pDbLayer->Close();
			}
		wxString errorMessage = wxString::Format(_("Error (%d): %s"), e.GetErrorCode(), e.GetErrorMessage().c_str());
		
		dialog.AppendComment(wxT("Fail!"));
		dialog.AppendComment(errorMessage);		
		wxMessageDialog dlg(this,errorMessage,wxT("DB Error"),wxOK | wxCENTER | wxICON_ERROR);
		dlg.ShowModal();
	}
	catch( ... )
	{
		if (pDbLayer){
			pDbLayer->RollBack();
			pDbLayer->Close();
			}
		wxMessageDialog dlg(this,wxT("Unknown error."),wxT("DB Error"),wxOK | wxCENTER | wxICON_ERROR);
		dlg.ShowModal();
	}	
	dialog.EnableClose(true);
	dialog.ShowModal();


	return false;
}

