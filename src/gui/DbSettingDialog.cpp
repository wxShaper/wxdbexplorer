#include "DbSettingDialog.h"
#include <wx/dblayer/DatabaseLayer.h>
#include <wx/dblayer/MysqlDatabaseLayer.h>
#include <wx/dblayer/SqliteDatabaseLayer.h>

DbSettingDialog::DbSettingDialog(DbViewerPanel *parent):_DBSettingsDialog(parent) {

	m_pParent = parent;
}

DbSettingDialog::~DbSettingDialog() {
}

void DbSettingDialog::OnCancelClick(wxCommandEvent& event) {
	Destroy();
}
void DbSettingDialog::OnOkClick(wxCommandEvent& event) {
	
	MysqlDatabaseLayer *DbLayer = new MysqlDatabaseLayer(m_txServer->GetValue(),wxT(""),m_txUserName->GetValue(),m_txPassword->GetValue());
	m_pParent->SetDbAdapter(new MySqlDbAdapter(m_txServer->GetValue(),m_txUserName->GetValue(),m_txPassword->GetValue()));

	if (!DbLayer->IsOpen()) wxMessageBox(wxT("Cannot open DB!"));
	m_pParent->SetDbConnector(new MySqlDbConnector(DbLayer));
	
	//m_pParent->SetDbLayer(DbLayer);
	wxString serverName = m_txServer->GetValue();
	m_pParent->SetServer(serverName);
	Destroy();
}
void DbSettingDialog::OnSqliteOkClick(wxCommandEvent& event) {
	SqliteDatabaseLayer *DbLayer = new SqliteDatabaseLayer(m_filePickerSqlite->GetPath());
//	m_pParent->SetDbAdapter(new SQLiteDbAdapter(m_filePickerSqlite->GetPath()));
	
	
	if (!DbLayer->IsOpen()) wxMessageBox(wxT("Cannot open DB!"));
	//m_pParent->SetDbLayer(DbLayer);

	m_pParent->SetDbConnector(new SqliteDbConnector(DbLayer));
	wxString serverName = m_filePickerSqlite->GetPath();
	m_pParent->SetServer(serverName);
	Destroy();
}
