#include "DbSettingDialog.h"
#include <wx/dblayer/DatabaseLayer.h>
#include <wx/dblayer/MysqlDatabaseLayer.h>
#include <wx/dblayer/SqliteDatabaseLayer.h>
#include <wx/dblayer/DatabaseErrorCodes.h>
#include <wx/dblayer/DatabaseLayerException.h>

DbSettingDialog::DbSettingDialog(DbViewerPanel *parent):_DBSettingsDialog(parent) {

	m_pParent = parent;
	LoadHistory();
	
}

DbSettingDialog::~DbSettingDialog() {
	
	m_pHistory = new MysqlConnectionHistory();
	if (m_pHistory){
		for (unsigned int i = 0 ; i < m_listBox2->GetCount(); i++){
			MysqlHistItem* item = wxDynamicCast(m_listBox2->GetClientData(i), MysqlHistItem);
			if (item){
				m_pHistory->AddChild((MysqlHistItem* )item->Clone());		
				}
			}
		MysqlConnectionHistory::SaveToFile(m_pHistory);
	}
}

void DbSettingDialog::OnCancelClick(wxCommandEvent& event) {
	Destroy();
}
void DbSettingDialog::OnOkClick(wxCommandEvent& event) {
	try
		{
		MysqlDatabaseLayer *DbLayer = new MysqlDatabaseLayer(m_txServer->GetValue(),wxT(""),m_txUserName->GetValue(),m_txPassword->GetValue());
		m_pParent->SetDbAdapter(new MySqlDbAdapter(m_txServer->GetValue(),m_txUserName->GetValue(),m_txPassword->GetValue()));

		if (!DbLayer->IsOpen()) wxMessageBox(wxT("Cannot open DB!"));
	//	m_pParent->SetDbConnector(new MySqlDbConnector(DbLayer));

		//m_pParent->SetDbLayer(DbLayer);
		wxString serverName = m_txServer->GetValue();
		m_pParent->SetServer(serverName);
		Destroy();
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
void DbSettingDialog::OnSqliteOkClick(wxCommandEvent& event) {
	try
		{
		SqliteDatabaseLayer *DbLayer = new SqliteDatabaseLayer(m_filePickerSqlite->GetPath());
		m_pParent->SetDbAdapter(new SQLiteDbAdapter(m_filePickerSqlite->GetPath()));
		if (!DbLayer->IsOpen()) wxMessageBox(wxT("Cannot open DB!"));
		//m_pParent->SetDbLayer(DbLayer);
		wxString serverName = m_filePickerSqlite->GetPath();
		m_pParent->SetServer(serverName);
		Destroy();
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
void DbSettingDialog::OnHistoruUI(wxUpdateUIEvent& event) {
	event.Enable( m_listBox2->GetCount() > 0 );
}

void DbSettingDialog::OnHistoryClick(wxCommandEvent& event) {
	MysqlHistItem* item = wxDynamicCast(event.GetClientData(), MysqlHistItem);
	if (item){
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
void DbSettingDialog::LoadHistory()
{
	m_pHistory = MysqlConnectionHistory::LoadFromFile();
	if (m_pHistory){
		m_listBox2->Clear();
		SerializableList::compatibility_iterator node = m_pHistory->GetFirstChildNode();
		while( node )
			{			
			if( node->GetData()->IsKindOf( CLASSINFO(MysqlHistItem)) ){
				MysqlHistItem *item = (MysqlHistItem*) node->GetData();
				m_listBox2->Append(item->GetName(),item->Clone());				
				} 
			if (( node->GetData()->IsKindOf( CLASSINFO(MysqlConnectionHistory)) )){
				bool test;
				test = true;
				
				}
			node = node->GetNext();
			}			
	}	
	if (m_pHistory) delete m_pHistory;
	m_pHistory = NULL;
}

