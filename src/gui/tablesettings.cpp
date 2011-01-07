#include "tablesettings.h"

TableSettings::TableSettings(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):_TableSettings(parent,id,title,pos,size, style ) {
}

TableSettings::~TableSettings() {
}

void TableSettings::OnCancelClick(wxCommandEvent& event) {
}
void TableSettings::OnListBoxClick(wxCommandEvent& event) {
	wxString name = m_listColumns->GetStringSelection();
	for (int i = 0; i< m_pTable->columns->GetColCount(); ++i) {
		Column* col = m_pTable->columns->GetByIndex(i);
		if ((col)&&(col->getName() == name)) {
			m_pEditedColumn = col;
			m_txColName->SetValue(col->getName());

			IDbType* type = col->getPType();
			if (type) {
				m_comboType->SetValue(type->GetTypeName());
			}
		}
	}
}
void TableSettings::OnNewColumnClick(wxCommandEvent& event) {
}
void TableSettings::OnOKClick(wxCommandEvent& event) {
}
void TableSettings::OnSaveColumnClick(wxCommandEvent& event) {
}
void TableSettings::OnTypeSelect(wxCommandEvent& event) {
}

void TableSettings::SetTable(Table* tab) {
	m_pTable = tab;
	UpdateView();
}

void TableSettings::UpdateView() {
	if (m_pTable->columns) {
		m_txTableName->SetValue(m_pTable->getName());
		for (int i = 0; i< m_pTable->columns->GetColCount(); ++i) {
			Column* col = m_pTable->columns->GetByIndex(i);
			if (col) {
				m_listColumns->AppendString(col->getName());
			}
		}
	}

}

void TableSettings::OnAutoIncrementUI(wxUpdateUIEvent& event) {
	event.Enable(false);
	if (m_pEditedColumn){
		if (m_pEditedColumn->getPType()) event.Enable(m_pEditedColumn->getPType()->HaveAutoIncrement());		
		}
}

void TableSettings::OnColNameUI(wxUpdateUIEvent& event) {
	if (m_pEditedColumn) event.Enable(true);
	else event.Enable(false);
}

void TableSettings::OnColSizeUI(wxUpdateUIEvent& event) {
	event.Enable(false);
	if (m_pEditedColumn){
		if (m_pEditedColumn->getPType()) event.Enable(m_pEditedColumn->getPType()->HaveSize());		
		}
}

void TableSettings::OnColTypeUI(wxUpdateUIEvent& event) {
	event.Enable(false);
	if (m_pEditedColumn){
		if (m_pEditedColumn->getPType()) event.Enable(true);		
		}
}

void TableSettings::OnNotNullUI(wxUpdateUIEvent& event) {
	event.Enable(false);
	if (m_pEditedColumn){
		if (m_pEditedColumn->getPType()) event.Enable(m_pEditedColumn->getPType()->HaveNotNull());		
		}
}

void TableSettings::OnPrimaryKeyUI(wxUpdateUIEvent& event) {
	event.Enable(false);
	if (m_pEditedColumn){
		if (m_pEditedColumn->getPType()) event.Enable(m_pEditedColumn->getPType()->HavePrimaryKey());		
		}
}

void TableSettings::OnUniqueUI(wxUpdateUIEvent& event) {
	event.Enable(false);
	if (m_pEditedColumn){
		if (m_pEditedColumn->getPType()) event.Enable(m_pEditedColumn->getPType()->HaveUnique());		
		}
}
