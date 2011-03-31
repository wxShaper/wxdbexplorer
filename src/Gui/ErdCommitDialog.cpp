#include "ErdCommitDialog.h"

ErdCommitDialog::ErdCommitDialog(wxWindow* pParent, xsSerializable* pConnections, const wxString& createScript):_ErdCommitDialog(pParent) {
	m_pConnections = pConnections;
	m_createScript = createScript;
	Load();
	canTabChange = false;
	backuped = false;
	m_pSelectedDatabase = NULL;
}

ErdCommitDialog::~ErdCommitDialog() {
}

void ErdCommitDialog::OnBackupUI(wxUpdateUIEvent& event) {

}
void ErdCommitDialog::OnBtnBack(wxCommandEvent& event) {
	canTabChange = true;
	m_notebook4->SetSelection(m_notebook4->GetSelection()-1);
	canTabChange = false;
}
void ErdCommitDialog::OnBtnBackUI(wxUpdateUIEvent& event) {
	event.Enable(m_notebook4->GetSelection() > 0);
}
void ErdCommitDialog::OnBtnBackup(wxCommandEvent& event) {
	
	m_pSelectedDatabase->RefreshChildrenDetails();
	
	DumpClass* pDump = new DumpClass(m_pSelectedDatabase->GetDbAdapter(), m_pSelectedDatabase, m_fileData->GetPath());
	if (pDump) pDump->DumpData();

	wxMessageBox(wxT("Data saved!"));

	if (m_checkBox3->IsChecked()) {
		wxString retStr;


		SerializableList::compatibility_iterator tabNode = m_pSelectedDatabase->GetFirstChildNode();
		while(tabNode) {
			Table* tab = wxDynamicCast(tabNode->GetData(),Table);
			if (tab) {
				retStr.append(m_pSelectedDatabase->GetDbAdapter()->GetCreateTableSql(tab,true));
			}
			tabNode = tabNode->GetNext();
		}

		tabNode = m_pSelectedDatabase->GetFirstChildNode();
		while(tabNode) {
			View* view = wxDynamicCast(tabNode->GetData(),View);
			if (view) {
				retStr.append(m_pSelectedDatabase->GetDbAdapter()->GetCreateViewSql(view,true));
			}
			tabNode = tabNode->GetNext();
		}

		tabNode = m_pSelectedDatabase->GetFirstChildNode();
		while(tabNode) {
			Table* tab = wxDynamicCast(tabNode->GetData(),Table);
			if (tab) {
				retStr.append(m_pSelectedDatabase->GetDbAdapter()->GetAlterTableConstraintSql(tab));
			}
			tabNode = tabNode->GetNext();
		}

		wxTextFile pTextFile(m_fileStructure->GetPath());

		if (pTextFile.Exists()) {
			pTextFile.Open();
			pTextFile.Clear();
		} else {
			pTextFile.Create();
			pTextFile.Open();
		}
		if (pTextFile.IsOpened()) {
			pTextFile.AddLine(retStr);
			pTextFile.Write();
			pTextFile.Close();
			wxMessageBox(wxT("Structure saved!"));
		}

	}
	backuped = true;
}
void ErdCommitDialog::OnBtnWrite(wxCommandEvent& event) {
	DatabaseLayer* pDbLayer = NULL;


	try {
		pDbLayer = m_pSelectedDatabase->GetDbAdapter()->GetDatabaseLayer(m_pSelectedDatabase->GetName());
		if (pDbLayer) {
			pDbLayer->BeginTransaction();

			wxString useSql = m_pSelectedDatabase->GetDbAdapter()->GetUseDb(m_pSelectedDatabase->GetName());
			if (!useSql.IsEmpty()) pDbLayer->RunQuery(wxString::Format(wxT("USE %s"), m_pSelectedDatabase->GetName().c_str()));


			pDbLayer->RunQuery(m_createScript);

			pDbLayer->Commit();
			pDbLayer->Close();
			m_textCtrl22->SetValue(wxT("Data structure written successfully!"));
		}

	} catch (DatabaseLayerException& e) {
		if (pDbLayer) {
			pDbLayer->RollBack();
			pDbLayer->Close();
		}
		wxString errorMessage = wxString::Format(_("Error (%d): %s"), e.GetErrorCode(), e.GetErrorMessage().c_str());
		m_textCtrl22->SetValue(errorMessage);
	} catch( ... ) {
		if (pDbLayer) {
			pDbLayer->RollBack();
			pDbLayer->Close();
		}
		m_textCtrl22->SetValue(wxT("Uknow error!"));
	}

}
void ErdCommitDialog::OnNextUI(wxUpdateUIEvent& event) {
	event.Enable(m_notebook4->GetSelection() < 3);
}
void ErdCommitDialog::OnNtbPageChanging(wxNotebookEvent& event) {
	if (!canTabChange ) event.Veto();
	//event.Veto();
}
void ErdCommitDialog::OnStructureFileUI(wxUpdateUIEvent& event) {
	event.Enable(m_checkBox3->IsChecked());
}
void ErdCommitDialog::OnWriteUI(wxUpdateUIEvent& event) {






}
void ErdCommitDialog::OnBtnNext(wxCommandEvent& event) {

	if (m_notebook4->GetSelection() == 0) {
		DbItem* data = (DbItem*) m_treeConnection->GetItemData(m_treeConnection->GetSelection());
		if (data) {
			Database* pdb = wxDynamicCast(data->GetData(), Database);
			if (pdb) {
				canTabChange = true;
				m_pSelectedDatabase = pdb;
			}
		}
		//TODO:LANG:
		if (!canTabChange) wxMessageBox(wxT("At first time you have to select target database!"));
		backuped = false;
	}
	if (m_notebook4->GetSelection() == 1) {
		if (backuped == false) {

			wxMessageDialog dlg(this, wxT("Backup database data before changing structure is really good idea. Do you want to continue without it?"),wxT("Backup"),wxYES_NO);
			if (dlg.ShowModal() ==  wxID_YES) {
				backuped = true;
				canTabChange = true;

			}
		} else canTabChange = true;
	}
	if (m_notebook4->GetSelection() == 2) {
		m_fileRestore->SetPath(m_fileData->GetPath());
		canTabChange = true;
	}


	m_notebook4->SetSelection(m_notebook4->GetSelection()+1);
	canTabChange = false;
}
void ErdCommitDialog::Load() {

	// clear items from tree
	m_treeConnection->DeleteAllItems();
	// create imageList for icons
	wxImageList *pImageList = new wxImageList(16,16,true,3);
	pImageList->Add(wxIcon(folder_xpm));						// folder icon
	pImageList->Add(wxIcon(form_blue_xpm));						// table icon
	pImageList->Add(wxIcon(form_yellow_xpm));						// view icon
	m_treeConnection->SetImageList(pImageList);

	wxTreeItemId totalRootID = m_treeConnection->AddRoot(wxString::Format(wxT("Databases")),-1);

	// ---------------- load connections ----------------------------
	SerializableList::compatibility_iterator connectionNode = m_pConnections->GetFirstChildNode();
	while(connectionNode) {
		DbConnection* pDbCon = (DbConnection*) wxDynamicCast(connectionNode->GetData(),DbConnection);
		if (pDbCon) {
			wxTreeItemId rootID = m_treeConnection->AppendItem(totalRootID,wxString::Format(wxT("Databases (%s)"),pDbCon->GetServerName().c_str()),-1,-1, new DbItem(pDbCon));
			m_treeConnection->Expand(rootID);
			// ----------------------- load databases -------------------------------
			SerializableList::compatibility_iterator dbNode = pDbCon->GetFirstChildNode();
			while(dbNode) {
				Database* pDatabase = wxDynamicCast(dbNode->GetData(), Database);
				if (pDatabase) {
					//wxTreeItemId dbID = m_treeDatabases->AppendItem(rootID,pDatabase->getName(),-1,-1, new DbItem(pDatabase,NULL));//new DbDatabase(db->getName()));
					wxTreeItemId dbID = m_treeConnection->AppendItem(rootID,pDatabase->GetName(),-1,-1, new DbItem(pDatabase));//new DbDatabase(db->getName()));

					/*
										m_treeConnection->Expand(rootID);
										wxTreeItemId idFolder = m_treeConnection->AppendItem(dbID, wxT("Tables"),0,0,NULL);
										//m_treeDatabases->Expand(dbID);

										// ----------------------------- load tables ----------------------------------
										SerializableList::compatibility_iterator tabNode = pDatabase->GetFirstChildNode();
										while(tabNode) {
											Table* pTable = wxDynamicCast(tabNode->GetData(), Table);
											if (pTable) {
												//wxTreeItemId tabID = m_treeDatabases->AppendItem(idFolder,pTable->getName(),1,-1,new DbItem(NULL,pTable)); //NULL);
												wxTreeItemId tabID = m_treeConnection->AppendItem(idFolder,pTable->GetName(),1,-1,new DbItem(pTable)); //NULL);
											}
											tabNode = tabNode->GetNext();
										}
										// ----------------------------------------------------------------------------


										idFolder = m_treeConnection->AppendItem(dbID, wxT("Views"),0,0,NULL);
										//m_treeDatabases->Expand(dbID);

										// ----------------------------- load views ----------------------------------
										tabNode = pDatabase->GetFirstChildNode();
										while(tabNode) {
											View* pView = wxDynamicCast(tabNode->GetData(),View);
											if (pView) {
												//wxTreeItemId tabID = m_treeDatabases->AppendItem(idFolder,pTable->getName(),1,-1,new DbItem(NULL,pTable)); //NULL);
												wxTreeItemId tabID = m_treeConnection->AppendItem(idFolder,pView->GetName(),2,-1,new DbItem(pView)); //NULL);
											}
											tabNode = tabNode->GetNext();
										}
										// ----------------------------------------------------------------------------
					*/
				}
				dbNode = dbNode->GetNext();
			}
			// -----------------------------------------------------------------------
		}
		connectionNode = connectionNode->GetNext();
	}
}

void ErdCommitDialog::OnBtnRestoreClick(wxCommandEvent& event) {
}

void ErdCommitDialog::OnBtnRestoreUI(wxUpdateUIEvent& event) {
	event.Enable(!m_fileRestore->GetPath().IsEmpty());
}
void ErdCommitDialog::OnShowSqlClick(wxCommandEvent& event) {
	wxMessageBox(m_createScript);
}
