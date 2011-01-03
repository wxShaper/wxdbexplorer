
#include <wx/file.h>
#include <wx/textfile.h>
#include "SqlCommandPanel.h"
#include "DatabaseExplorerFrame.h"

SQLCommandPanel::SQLCommandPanel(wxWindow *parent, wxString& dbName, DatabaseLayer* pDbLayer, wxString& dbTable) : _SqlCommandPanel(parent)
{
	DatabaseExplorerFrame::InitStyledTextCtrl( m_scintillaSQL );
	m_pDbLayer = pDbLayer;
	m_dbName = dbName;
	m_dbTable = dbTable;

	//TODO:SQL:
	m_scintillaSQL->AddText(wxT("-- selected database ") + m_dbName);
	m_scintillaSQL->AddText(wxT("\nSELECT * FROM ") + m_dbTable + wxT(" LIMIT 100"));
	ExecuteSql();
}

SQLCommandPanel::~SQLCommandPanel()
{
}

void SQLCommandPanel::OnExecuteClick(wxCommandEvent& event)
{
	ExecuteSql();
}
void SQLCommandPanel::OnScintilaKeyDown(wxKeyEvent& event)
{
	if ((event.ControlDown())&&(event.GetKeyCode() == WXK_RETURN)) {
		ExecuteSql();
	}
	event.Skip();
}
void SQLCommandPanel::ExecuteSql()
{
	// test for empty string
	if (this->m_scintillaSQL->GetText() != wxT("")) {
		// selec working db
		//TODO:SQL:
		m_pDbLayer->RunQuery(wxT("USE ")+ m_dbName);
		try {
			// run query
			DatabaseResultSet* pResultSet = m_pDbLayer->RunQueryWithResults(this->m_scintillaSQL->GetText());
			// clear variables
			m_gridTable->DeleteCols(0,m_gridTable->GetNumberCols());
			m_gridTable->DeleteRows(0,m_gridTable->GetNumberRows());
			int rows = 0;
			int cols = pResultSet->GetMetaData()->GetColumnCount();

			// create table header
			m_gridTable->AppendCols(cols);
			for (int i = 1; i<= pResultSet->GetMetaData()->GetColumnCount();i++) {
				m_gridTable->SetColLabelValue(i-1,pResultSet->GetMetaData()->GetColumnName(i));
			}

			// fill table data
			while (pResultSet->Next()) {
				m_gridTable->AppendRows();
				for (int i = 1; i<= pResultSet->GetMetaData()->GetColumnCount();i++) {

					switch (	pResultSet->GetMetaData()->GetColumnType(i)) {
					case ResultSetMetaData::COLUMN_INTEGER:
						m_gridTable->SetCellValue(wxString::Format(wxT("%i"),pResultSet->GetResultInt(i)),rows,i-1);
						break;
					case ResultSetMetaData::COLUMN_STRING:
						m_gridTable->SetCellValue(pResultSet->GetResultString(i),rows,i-1);
						break;
					case ResultSetMetaData::COLUMN_UNKNOWN:
						m_gridTable->SetCellValue(pResultSet->GetResultString(i),rows,i-1);
						break;
					case ResultSetMetaData::COLUMN_BLOB:
						m_gridTable->SetCellValue(pResultSet->GetResultString(i),rows,i-1);
						break;
					case ResultSetMetaData::COLUMN_BOOL:
						m_gridTable->SetCellValue(wxString::Format(wxT("%b"),pResultSet->GetResultBool(i)),rows,i-1);
						break;
					case ResultSetMetaData::COLUMN_DATE:
						m_gridTable->SetCellValue(pResultSet->GetResultString(i),rows,i-1);
						break;
					case ResultSetMetaData::COLUMN_DOUBLE:
						m_gridTable->SetCellValue(wxString::Format(wxT("%d"),pResultSet->GetResultDouble(i)),rows,i-1);
						break;
					case ResultSetMetaData::COLUMN_NULL:
						//m_gridTable->SetCellValue(pResultSet->GetResultString(i),rows,i-1);
						break;
					default:
						m_gridTable->SetCellValue(pResultSet->GetResultString(i),rows,i-1);
						break;
					}
				}
				rows++;
			}
			m_pDbLayer->CloseResultSet(pResultSet);

			// show result status
			m_labelStatus->SetLabel(wxString::Format(wxT("Result: %i rows"),rows));

		} catch (DatabaseLayerException& e) {
			// error report
			if (e.GetErrorCode() != DATABASE_LAYER_QUERY_RESULT_ERROR ){
				wxMessageBox(e.GetErrorMessage());
				m_labelStatus->SetLabel(wxString::Format(wxT("Result: Error %i..."),e.GetErrorCode()));
			}
		}
	}
}

void SQLCommandPanel::OnLoadClick(wxCommandEvent& event)
{
	wxFileDialog dlg(this, wxT("Chose file"),wxT(""),wxT(""),wxT("Sql files(*.slq)|*.sql"),wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	m_scintillaSQL->ClearAll();
	if (dlg.ShowModal() == wxID_OK){
		wxTextFile file( dlg.GetPath());
		file.Open();
		if (file.IsOpened()){
			for ( wxString str = file.GetFirstLine(); !file.Eof(); str = file.GetNextLine() )
				{
					m_scintillaSQL->AddText(str);
					m_scintillaSQL->AddText(wxT("\n"));
				}			
			}		
		}
}

void SQLCommandPanel::OnSaveClick(wxCommandEvent& event)
{
	wxFileDialog dlg(this,wxT("Chose file"),wxT(""),wxT(""),wxT("Sql files(*.sql)|*.sql"),wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if (dlg.ShowModal() == wxID_OK){	
		
		wxFile file(dlg.GetPath(),wxFile::write);
		if (file.IsOpened()){
			file.Write(m_scintillaSQL->GetText());	
			file.Close();
			}
		}
}
