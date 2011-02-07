#include "AdapterSelectDlg.h"
#include "ErdPanel.h"

AdapterSelectDlg::AdapterSelectDlg(wxWindow* parent,wxAuiNotebook* pNotebook ) : _AdapterSelectDlg(parent) {
	m_pNotebook = pNotebook;
}

AdapterSelectDlg::~AdapterSelectDlg() {
}

void AdapterSelectDlg::OnMysqlClick(wxCommandEvent& event) {
	m_pNotebook->AddPage(new ErdPanel(m_pNotebook, new MySqlDbAdapter()),wxT("MySQL ERD diagram"));
}
void AdapterSelectDlg::OnSqliteClick(wxCommandEvent& event) {
	m_pNotebook->AddPage(new ErdPanel(m_pNotebook, new SQLiteDbAdapter()),wxT("SQLite ERD diagram"));
}
