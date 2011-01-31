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
	if (item){
		if (Table* tab =  wxDynamicCast(item->GetData(), Table)){
			wxString dbName = tab->getParentName();
			wxString dbTable = tab->getName();
			m_pNotebook->AddPage(new SQLCommandPanel(m_pNotebook,tab->GetDbAdapter(),dbName,dbTable),dbName,true);			
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
					wxTreeItemId idFolder = m_treeDatabases->AppendItem(dbID, wxT("Tables"),0);
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
	
	// getting selected item data
	DbItem* data = (DbItem*) m_treeDatabases->GetItemData(m_treeDatabases->GetSelection());
	if (data){
		DbConnection* pCon = wxDynamicCast(data->GetData(), DbConnection);
		if (pCon) {
			wxMessageDialog dlg(this,wxT("Close connection?"),wxT("Close"),wxYES_NO);		
			if (dlg.ShowModal() == wxID_YES){
				delete pCon;
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
