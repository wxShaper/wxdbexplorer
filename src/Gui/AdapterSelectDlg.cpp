#include "AdapterSelectDlg.h"
#include "ErdPanel.h"

AdapterSelectDlg::AdapterSelectDlg(wxWindow* parent,wxAuiNotebook* pNotebook ) : _AdapterSelectDlg(parent) {
	m_pNotebook = pNotebook;
}

AdapterSelectDlg::~AdapterSelectDlg() {
}

void AdapterSelectDlg::OnMysqlClick(wxCommandEvent& event) {
#ifdef DBL_USE_MYSQL
	m_pNotebook->AddPage(new ErdPanel(m_pNotebook, new MySqlDbAdapter()),wxT("MySQL ERD diagram"));
#else
	wxMessageBox( wxT("MySQL ERD is not supported."), wxT("DB Error"), wxOK | wxICON_WARNING );
#endif
}
void AdapterSelectDlg::OnSqliteClick(wxCommandEvent& event) {
#ifdef DBL_USE_SQLITE
	m_pNotebook->AddPage(new ErdPanel(m_pNotebook, new SQLiteDbAdapter()),wxT("SQLite ERD diagram"));
#else
	wxMessageBox( wxT("SQLite ERD is not supported."), wxT("DB Error"), wxOK | wxICON_WARNING );
#endif
}
