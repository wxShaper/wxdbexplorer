#include "DbSettingDialog.h"
#include "Main/DatabaseExplorerApp.h"

#include <wx/dblayer/include/DatabaseLayer.h>

#ifdef DBL_USE_MYSQL
#include <wx/dblayer/include/MysqlDatabaseLayer.h>
#endif

#ifdef DBL_USE_SQLITE
#include <wx/dblayer/include/SqliteDatabaseLayer.h>
#endif

#include <wx/dblayer/include/DatabaseErrorCodes.h>
#include <wx/dblayer/include/DatabaseLayerException.h>

DbSettingDialog::DbSettingDialog(DbViewerPanel *parent):_DBSettingsDialog( wxGetApp().GetTopWindow() ) {

	m_pParent = parent;
	LoadHistory();
#ifndef DBL_USE_MYSQL
	m_MySqlPanel->Enable(false);
#endif
#ifndef DBL_USE_POSTGRES
	m_PostgrePanel->Enable(false);
#endif
}

DbSettingDialog::~DbSettingDialog() {

	m_pHistory = new MysqlConnectionHistory();
	if (m_pHistory) {
		for (unsigned int i = 0 ; i < m_listBox2->GetCount(); i++) {
			MysqlHistItem* item = wxDynamicCast(m_listBox2->GetClientData(i), MysqlHistItem);
			if (item) {
				m_pHistory->AddChild((MysqlHistItem* )item->Clone());
			}
		}
		MysqlConnectionHistory::SaveToFile(m_pHistory);
	}
	m_pPgHistory = new PostgresConnectionHistory();
	if (m_pPgHistory) {
		for (unsigned int i = 0 ; i < m_listBoxPg->GetCount(); i++) {
			PostgresHistItem* item = wxDynamicCast(m_listBoxPg->GetClientData(i), PostgresHistItem);
			if (item) {
				m_pPgHistory->AddChild((PostgresHistItem* )item->Clone());
			}
		}
		PostgresConnectionHistory::SaveToFile(m_pPgHistory);
	}
}

void DbSettingDialog::OnCancelClick(wxCommandEvent& event) {
	Destroy();
}
void DbSettingDialog::OnOkClick(wxCommandEvent& event) {
#ifdef DBL_USE_MYSQL
	try {
		//MysqlDatabaseLayer *DbLayer = new MysqlDatabaseLayer(m_txServer->GetValue(),wxT(""),m_txUserName->GetValue(),m_txPassword->GetValue());
		IDbAdapter* adapt = new MySqlDbAdapter(m_txServer->GetValue(),m_txUserName->GetValue(),m_txPassword->GetValue());

		wxString serverName = m_txServer->GetValue();
		m_pParent->AddDbConnection(new DbConnection(adapt, serverName));

		m_pParent->SetServer(serverName);
		Destroy();
	} catch (DatabaseLayerException& e) {
		wxString errorMessage = wxString::Format(_("Error (%d): %s"), e.GetErrorCode(), e.GetErrorMessage().c_str());
		wxMessageDialog dlg(this,errorMessage,wxT("DB Error"),wxOK | wxCENTER | wxICON_ERROR);
		dlg.ShowModal();
	} catch( ... ) {
		wxMessageDialog dlg(this,wxT("Unknown error."),wxT("DB Error"),wxOK | wxCENTER | wxICON_ERROR);
		dlg.ShowModal();
	}
#else
	wxMessageBox( wxT("MySQL connection is not supported."), wxT("DB Error"), wxOK | wxICON_WARNING );
#endif
}

void DbSettingDialog::OnSqliteOkClick(wxCommandEvent& event) {
#ifdef DBL_USE_SQLITE
	try {

		//SqliteDatabaseLayer *DbLayer = new SqliteDatabaseLayer(m_filePickerSqlite->GetPath());
		IDbAdapter* pAdapt = new SQLiteDbAdapter(m_filePickerSqlite->GetPath());


		//m_pParent->SetDbLayer(DbLayer);
		wxString serverName = m_filePickerSqlite->GetPath();
		m_pParent->AddDbConnection(new DbConnection(pAdapt, serverName));

		m_pParent->SetServer(serverName);
		Destroy();
	} catch (DatabaseLayerException& e) {
		wxString errorMessage = wxString::Format(_("Error (%d): %s"), e.GetErrorCode(), e.GetErrorMessage().c_str());
		wxMessageDialog dlg(this,errorMessage,wxT("DB Error"),wxOK | wxCENTER | wxICON_ERROR);
		dlg.ShowModal();
	} catch( ... ) {
		wxMessageDialog dlg(this,wxT("Unknown error."),wxT("DB Error"),wxOK | wxCENTER | wxICON_ERROR);
		dlg.ShowModal();
	}
#else
	wxMessageBox( wxT("SQLite connection is not supported."), wxT("DB Error"), wxOK | wxICON_WARNING );
#endif
}

void DbSettingDialog::OnHistoruUI(wxUpdateUIEvent& event) {
	event.Enable( m_listBox2->GetCount() > 0 );
}

void DbSettingDialog::OnHistoryClick(wxCommandEvent& event) {
	MysqlHistItem* item = wxDynamicCast(event.GetClientData(), MysqlHistItem);
	if (item) {
		m_txName->SetValue(item->GetName());
		m_txServer->SetValue(item->GetServer());
		m_txUserName->SetValue(item->GetUserName());
		m_txPassword->SetValue(item->GetPassword());
	}
}

void DbSettingDialog::OnHistoryDClick(wxCommandEvent& event) {
}

void DbSettingDialog::OnRemoveClick(wxCommandEvent& event) {
	int i = m_listBox2->GetSelection();
	if (i > -1) m_listBox2->Delete(i);
}

void DbSettingDialog::OnRmoveUI(wxUpdateUIEvent& event) {
	event.Enable(m_listBox2->GetSelection() > -1);
}

void DbSettingDialog::OnSaveClick(wxCommandEvent& event) {
	m_listBox2->Append(m_txName->GetValue(), new MysqlHistItem(m_txName->GetValue(),m_txServer->GetValue(),m_txUserName->GetValue(),m_txPassword->GetValue()));
}

void DbSettingDialog::OnSaveUI(wxUpdateUIEvent& event) {
	event.Enable(!m_txName->IsEmpty());
}
void DbSettingDialog::OnOKUI(wxUpdateUIEvent& event) {
	event.Enable(!m_txServer->IsEmpty() && !m_txUserName->IsEmpty());
}
void DbSettingDialog::LoadHistory() {
	m_pHistory = MysqlConnectionHistory::LoadFromFile();
	if (m_pHistory) {
		m_listBox2->Clear();
		SerializableList::compatibility_iterator node = m_pHistory->GetFirstChildNode();
		while( node ) {
			if( node->GetData()->IsKindOf( CLASSINFO(MysqlHistItem)) ) {
				MysqlHistItem *item = (MysqlHistItem*) node->GetData();
				m_listBox2->Append(item->GetName(),item->Clone());
			}
			node = node->GetNext();
		}
	}
	if (m_pHistory) delete m_pHistory;
	m_pHistory = NULL;

	m_pPgHistory = PostgresConnectionHistory::LoadFromFile();
	if (m_pPgHistory) {
		m_listBoxPg->Clear();
		SerializableList::compatibility_iterator node = m_pPgHistory->GetFirstChildNode();
		while( node ) {
			if( node->GetData()->IsKindOf( CLASSINFO(PostgresHistItem)) ) {
				PostgresHistItem *item = (PostgresHistItem*) node->GetData();
				m_listBoxPg->Append(item->GetName(),item->Clone());
			}
			node = node->GetNext();
		}
	}
	if (m_pPgHistory) delete m_pPgHistory;
	m_pPgHistory = NULL;


}

void DbSettingDialog::OnPgCancelClick(wxCommandEvent& event) {
	Destroy();
}

void DbSettingDialog::OnPgOkClick(wxCommandEvent& event) {
#ifdef DBL_USE_POSTGRES
	try {
		//MysqlDatabaseLayer *DbLayer = new MysqlDatabaseLayer(m_txServer->GetValue(),wxT(""),m_txUserName->GetValue(),m_txPassword->GetValue());
		IDbAdapter* adapt = new PostgreSqlDbAdapter(m_txPgServer->GetValue(),m_txPgDatabase->GetValue(),m_txPgUserName->GetValue(),m_txPgPassword->GetValue());

		wxString serverName = m_txPgServer->GetValue();
		m_pParent->AddDbConnection(new DbConnection(adapt, serverName));

		m_pParent->SetServer(serverName);
		Destroy();
	} catch (DatabaseLayerException& e) {
		wxString errorMessage = wxString::Format(_("Error (%d): %s"), e.GetErrorCode(), e.GetErrorMessage().c_str());
		wxMessageDialog dlg(this,errorMessage,wxT("DB Error"),wxOK | wxCENTER | wxICON_ERROR);
		dlg.ShowModal();
	} catch( ... ) {
		wxMessageDialog dlg(this,wxT("Unknown error."),wxT("DB Error"),wxOK | wxCENTER | wxICON_ERROR);
		dlg.ShowModal();
	}
#else
	wxMessageBox( wxT("PostgreSQL connection is not supported."), wxT("DB Error"), wxOK | wxICON_WARNING );
#endif
}


void DbSettingDialog::OnPgRemoveClick(wxCommandEvent& event) {
	int i = m_listBoxPg->GetSelection();
	if (i > -1) m_listBoxPg->Delete(i);
}

void DbSettingDialog::OnPgSaveClick(wxCommandEvent& event) {
	m_listBoxPg->Append(m_txPgName->GetValue(), new PostgresHistItem(m_txPgName->GetValue(),m_txPgServer->GetValue(),m_txPgUserName->GetValue(),m_txPgPassword->GetValue(),m_txPgDatabase->GetValue()));
}
void DbSettingDialog::OnPgHistoryClick(wxCommandEvent& event) {
	PostgresHistItem* item = wxDynamicCast(event.GetClientData(), PostgresHistItem);
	if (item) {
		m_txPgName->SetValue(item->GetName());
		m_txPgServer->SetValue(item->GetServer());
		m_txPgUserName->SetValue(item->GetUserName());
		m_txPgPassword->SetValue(item->GetPassword());
		m_txPgDatabase->SetValue(item->GetDatabase());
	}
}

void DbSettingDialog::OnPgHistoryDClick(wxCommandEvent& event) {
}
void DbSettingDialog::OnPgOKUI(wxUpdateUIEvent& event) {
	event.Enable(!m_txPgServer->IsEmpty() && !m_txPgUserName->IsEmpty());
}

void DbSettingDialog::OnPgRmoveUI(wxUpdateUIEvent& event) {
	event.Enable(m_listBoxPg->GetSelection() > -1);
}

void DbSettingDialog::OnPgSaveUI(wxUpdateUIEvent& event) {
	event.Enable(!m_txPgName->IsEmpty());
}
