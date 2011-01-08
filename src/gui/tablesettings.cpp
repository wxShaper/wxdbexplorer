#include "tablesettings.h"

TableSettings::TableSettings(wxWindow* parent,IDbAdapter* pDbAdapter, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):_TableSettings(parent,id,title,pos,size, style ) {
	m_pTable = NULL;
	m_pEditedColumn = NULL;
	m_pDbAdapter = pDbAdapter;
	wxArrayString* pDbTypes = m_pDbAdapter->GetDbTypes();
	for (unsigned int i = 0; i < pDbTypes->Count(); ++i){
		m_comboType->AppendString(pDbTypes->Item(i));		
		}
	if (pDbTypes){
		pDbTypes->clear();
		delete pDbTypes;		
		}
}

TableSettings::~TableSettings() {
}

void TableSettings::OnCancelClick(wxCommandEvent& event) {
	Close();
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
				m_txSize->SetValue(wxString::Format(wxT("%i"),type->GetSize()));
				m_chAutoIncrement->SetValue(type->GetAutoIncrement());
				m_chNotNull->SetValue(type->GetNotNull());
				m_chPrimary->SetValue(type->GetPrimaryKey());
				m_checkBox3->SetValue(type->GetUnique());
			}
		}
	}
}
void TableSettings::OnNewColumnClick(wxCommandEvent& event) {
	Column* pCol = new Column(wxT("New col"),m_pTable->getName(),m_pDbAdapter->GetDbTypeByName(m_pDbAdapter->GetDbTypes()->Last()), false, false);
	if (pCol) m_pTable->columns->AddColumn(pCol);
	UpdateView();
}
void TableSettings::OnOKClick(wxCommandEvent& event) {
}
void TableSettings::OnSaveColumnClick(wxCommandEvent& event) {
	if (m_pEditedColumn){
		m_pEditedColumn->setName(m_txColName->GetValue());
		IDbType* pType = m_pEditedColumn->getPType();
		if (pType){
			pType->SetNotNull(m_chNotNull->GetValue());
			pType->SetAutoIncrement(m_chAutoIncrement->GetValue());
			pType->SetPrimaryKey(m_chPrimary->GetValue());
			pType->SetUnique(m_checkBox3->GetValue());			
			}	
		}
	UpdateView();
}
void TableSettings::OnTypeSelect(wxCommandEvent& event) {
	IDbType* pType = m_pDbAdapter->GetDbTypeByName(m_comboType->GetValue());
	if (pType){
		m_pEditedColumn->setPType(pType);
		}
}

void TableSettings::SetTable(Table* tab) {
	m_pTable = tab;
	UpdateView();
}

void TableSettings::UpdateView() {
	m_listColumns->Clear();
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
