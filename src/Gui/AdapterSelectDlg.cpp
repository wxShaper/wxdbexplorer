#include "AdapterSelectDlg.h"
#include "ErdPanel.h"

AdapterSelectDlg::AdapterSelectDlg(wxWindow* parent,wxAuiNotebook* pNotebook ) : _AdapterSelectDlg(parent) {
	m_pNotebook = pNotebook;
}

AdapterSelectDlg::~AdapterSelectDlg() {
}

void AdapterSelectDlg::OnMysqlClick(wxCommandEvent& event) {
#ifdef DBL_USE_MYSQL
	m_pNotebook->AddPage(new ErdPanel(m_pNotebook, new MySqlDbAdapter(), NULL),wxT("MySQL ERD diagram"));
	Destroy();
#else
	wxMessageBox( wxT("MySQL ERD is not supported."), wxT("DB Error"), wxOK | wxICON_WARNING );
#endif
}
void AdapterSelectDlg::OnSqliteClick(wxCommandEvent& event) {
#ifdef DBL_USE_SQLITE
	m_pNotebook->AddPage(new ErdPanel(m_pNotebook, new SQLiteDbAdapter(), NULL),wxT("SQLite ERD diagram"));
	Destroy();
#else
	wxMessageBox( wxT("SQLite ERD is not supported."), wxT("DB Error"), wxOK | wxICON_WARNING );
#endif
}
void AdapterSelectDlg::OnPostgresClick(wxCommandEvent& event) {
#ifdef DBL_USE_POSTGRES
	m_pNotebook->AddPage(new ErdPanel(m_pNotebook, new PostgreSqlDbAdapter(), NULL),wxT("PostgreSQL ERD diagram"));
	Destroy();
#else
	wxMessageBox( wxT("PostgreSQL ERD is not supported."), wxT("DB Error"), wxOK | wxICON_WARNING );
#endif
}
