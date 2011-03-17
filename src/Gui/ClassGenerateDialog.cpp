#include "ClassGenerateDialog.h"
#include "../Main/DatabaseExplorerApp.h"

ClassGenerateDialog::ClassGenerateDialog(wxWindow *parent, IDbAdapter* dbAdapter, xsSerializable* pItems):_ClassGenerateDialog(parent) {
	m_pDbAdapter = dbAdapter;
	m_pItems = pItems;	
	}

ClassGenerateDialog::~ClassGenerateDialog() {
	Destroy();
}

bool ClassGenerateDialog::GenerateClass(Table* pTab, const wxString& path) {
	wxTextFile htmpFile(wxGetApp().GetAppPath() + wxT("/dataClass.htmp"));
	wxTextFile ctmpFile(wxGetApp().GetAppPath() + wxT("/dataClass.ctmp"));

	if (!htmpFile.Open()) return false;
	if (!ctmpFile.Open()) return false;
	wxString classTableName = pTab->GetName();
	wxString classItemName = m_txPrefix->GetValue() + pTab->GetName() + m_txPostfix->GetValue();
	wxString classItemDef = pTab->GetName().Upper() + wxT("_H");
	wxString classColName = m_txPrefix->GetValue() + pTab->GetName() + wxT("Collection")+ m_txPostfix->GetValue();

	wxTextFile hFile(path + wxT("/") + classItemName + wxT(".h"));
	wxTextFile cFile(path + wxT("/") + classItemName + wxT(".cpp"));
	if (hFile.Exists()){
		if (!hFile.Open()) return false;
		hFile.Clear();
		}else{
		if (!hFile.Create()) return false;		
		}		
	if (cFile.Exists()){
		if (!cFile.Open()) return false;
		cFile.Clear();
		}else{
		if (!cFile.Create()) return false;		
		}	
	bool suc = GenerateFile(pTab,htmpFile,hFile, classItemName, classItemDef,classColName,classTableName );
	suc &= GenerateFile(pTab,ctmpFile,cFile, classItemName, classItemDef,classColName,classTableName);
	
	
	hFile.Write();
	hFile.Close();
	cFile.Write();
	cFile.Close();
	htmpFile.Close();
	ctmpFile.Close();
	return suc;
}

void ClassGenerateDialog::OnCancelClick(wxCommandEvent& event) {
	Destroy();
	}

void ClassGenerateDialog::OnGenerateClick(wxCommandEvent& event) {
	m_textCtrl19->Clear();
	SerializableList::compatibility_iterator node = m_pItems->GetFirstChildNode();
	while( node ) {
		Table* pTab = wxDynamicCast(node->GetData(),Table);
		if (pTab){
			if (GenerateClass(pTab, m_dirPicker1->GetPath())) m_textCtrl19->AppendText(pTab->GetName() + wxT("......... Generated successfully!\n"));			
			else m_textCtrl19->AppendText(pTab->GetName() + wxT("......... Error!!!\n"));			 	
			}

		node = node->GetNext();
	}	
}

wxString ClassGenerateDialog::GetTypeName(IDbType::UNIVERSAL_TYPE type)
{
	if (type == IDbType::dbtTYPE_TEXT) return wxT("wxString");
	if (type == IDbType::dbtTYPE_DATE_TIME) return wxT("wxDateTime");
	if (type == IDbType::dbtTYPE_INT) return wxT("int");
	if (type == IDbType::dbtTYPE_FLOAT) return wxT("float");
	if (type == IDbType::dbtTYPE_DECIMAL) return wxT("float");
	if (type == IDbType::dbtTYPE_BOOLEAN) return wxT("bool");
	if (type == IDbType::dbtTYPE_OTHER) return wxT("Object*");
	return wxT("");
}

wxString ClassGenerateDialog::GetResultFunction(IDbType::UNIVERSAL_TYPE type)
{
	if (type == IDbType::dbtTYPE_TEXT) return wxT("GetResultString");
	if (type == IDbType::dbtTYPE_DATE_TIME) return wxT("GetResultDate");
	if (type == IDbType::dbtTYPE_INT) return wxT("GetResultInt");
	if (type == IDbType::dbtTYPE_FLOAT) return wxT("GetResultDouble");
	if (type == IDbType::dbtTYPE_DECIMAL) return wxT("GetResultDouble");
	if (type == IDbType::dbtTYPE_BOOLEAN) return wxT("GetResultBool");
	if (type == IDbType::dbtTYPE_OTHER) return wxT("GetResultBlob");
	return wxT("");
}

bool ClassGenerateDialog::GenerateFile(Table* pTab, wxTextFile& htmpFile, wxTextFile& hFile, const wxString& classItemName, const wxString& classItemDef, const wxString& classColName, const wxString& classTableName )
{
	Constraint* pPK = NULL;
	SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
	while( node ) {
		Constraint* pConstr = wxDynamicCast(node->GetData(),Constraint);
		if (pConstr){
			if (pConstr->GetType() == Constraint::primaryKey) pPK = pConstr;		
			}					
		node = node->GetNext();
		}
	Column* pPKCol = NULL;
	
	if (pPK){
		SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
		while( node ) {
			Column* pCol = wxDynamicCast(node->GetData(),Column);
			if (pCol){
				if (pCol->GetName() == pPK->GetLocalColumn()) pPKCol = pCol;		
				}					
			node = node->GetNext();
			}		
		}
	
	
	
	
	
	
	
	
	for ( wxString str = htmpFile.GetFirstLine(); !htmpFile.Eof(); str = htmpFile.GetNextLine() )
	{
		if (str.Contains(wxT("%%classItemGetters%%"))){
				SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
				while( node ) {
					Column* pCol = wxDynamicCast(node->GetData(),Column);
					if (pCol){
						hFile.AddLine(wxString::Format(wxT("\tconst %s Get%s() const {"), GetResTypeName(pCol->GetPType()->GetUniversalType()).c_str(), pCol->GetName().c_str()));
						hFile.AddLine(wxString::Format(wxT("\t\treturn m_%s;"), pCol->GetName().c_str()));
						hFile.AddLine(wxString::Format(wxT("\t\t}")));						
						}					
					node = node->GetNext();
					}
			
		}else if (str.Contains(wxT("%%classItemVariables%%"))){
				SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
				while( node ) {
					Column* pCol = wxDynamicCast(node->GetData(),Column);
					if (pCol){
						hFile.AddLine(wxString::Format(wxT("\t%s m_%s;"), GetTypeName(pCol->GetPType()->GetUniversalType()).c_str(), pCol->GetName().c_str()));
						}					
					node = node->GetNext();
					}		
		}else if (str.Contains(wxT("%%classItemLoading%%"))){
				SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
				while( node ) {
					Column* pCol = wxDynamicCast(node->GetData(),Column);
					if (pCol){
						hFile.AddLine(wxString::Format(wxT("\t\tm_%s = pResult->%s(wxT(\"%s\"));"),pCol->GetName().c_str(), GetResultFunction(pCol->GetPType()->GetUniversalType()).c_str(), pCol->GetName().c_str()));
						}					
					node = node->GetNext();
					}				
		}else if (str.Contains(wxT("%%classColLabelFillGrid%%"))){		
				int i = 0;
				SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
				while( node ) {
					Column* pCol = wxDynamicCast(node->GetData(),Column);
					if (pCol){
						hFile.AddLine(wxT("\tpGrid->AppendCols(1);"));
						hFile.AddLine(wxString::Format(wxT("\tpGrid->SetColLabelValue(%i,wxT(\"%s\"));"),i++,pCol->GetName().c_str()));					
						}					
					node = node->GetNext();
					}				
		}else if (str.Contains(wxT("%%classColDataFillGrid%%"))){			
				int i = 0;
				SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
				while( node ) {
					Column* pCol = wxDynamicCast(node->GetData(),Column);
					if (pCol){
						hFile.AddLine(GetFillData(pCol, i++));
						}					
					node = node->GetNext();
					}				
		}else if (str.Contains(wxT("%%primaryKeyHeader%%"))){			
				if (pPKCol){
						hFile.AddLine(wxString::Format(wxT("\t/*! \\brief Return %s from db on the %s base */"),pPKCol->GetParentName().c_str(),pPKCol->GetName().c_str()));
						hFile.AddLine(wxString::Format(wxT("\tstatic %s* GetBy%s(%s %s, DatabaseLayer* pDbLayer);"),classItemName.c_str(),pPKCol->GetName().c_str(), GetTypeName(pPKCol->GetPType()->GetUniversalType()).c_str(),pPKCol->GetName().c_str()));
					}				
		}else if (str.Contains(wxT("%%primaryKeyBody%%"))){			
				if (pPKCol){
						hFile.AddLine(wxString::Format(wxT("%s* %s::GetBy%s(%s %s, DatabaseLayer* pDbLayer)"),classItemName.c_str(),classItemName.c_str(),pPKCol->GetName().c_str(), GetTypeName(pPKCol->GetPType()->GetUniversalType()).c_str(),pPKCol->GetName().c_str()));
						hFile.AddLine(wxT("{"));
						hFile.AddLine(wxT("\tDatabaseResultSet* resSet = NULL;"));
						hFile.AddLine(wxT("\tPreparedStatement* pStatement = NULL;"));
						hFile.AddLine(wxT("\tif (pDbLayer){"));
						hFile.AddLine(wxT("\t\tif (pDbLayer->IsOpen()){"));
						
						hFile.AddLine(wxString::Format(wxT("\t\t\tpStatement = pDbLayer->PrepareStatement(wxT(\"SELECT * FROM %s WHERE %s = ?\"));"),classTableName.c_str(), pPKCol->GetName().c_str()));
						hFile.AddLine(wxString::Format(wxT("\t\t\tpStatement->SetParamInt(1, %s);"),pPKCol->GetName().c_str()));			
						hFile.AddLine(wxT("\t\t\tresSet = pStatement->RunQueryWithResults();"));
						hFile.AddLine(wxT("\t\t\t}"));
						hFile.AddLine(wxT("\t\t}"));			
	
						hFile.AddLine(wxT("\tif (resSet){"));
						hFile.AddLine(wxString::Format(wxT("\t\tif (resSet->Next()) return new %s(resSet);"),classItemName.c_str()));	
						hFile.AddLine(wxT("\t\tpStatement->Close();"));	
						hFile.AddLine(wxT("\t\t}"));	
						hFile.AddLine(wxT("\treturn NULL;"));
			
						
						hFile.AddLine(wxT("}"));
				}			
		}else{
			str.Replace(wxT("%%classItemName%%"),classItemName);
			str.Replace(wxT("%%classItemDef%%"),classItemDef);
			str.Replace(wxT("%%classColName%%"),classColName);
			str.Replace(wxT("%%classTableName%%"),classTableName);
			hFile.AddLine(str);			
		}	
	}
	return true;
}


wxString ClassGenerateDialog::GetResTypeName(IDbType::UNIVERSAL_TYPE type)
{
	if (type == IDbType::dbtTYPE_TEXT) return wxT("wxString&");
	if (type == IDbType::dbtTYPE_DATE_TIME) return wxT("wxDateTime");
	if (type == IDbType::dbtTYPE_INT) return wxT("int");
	if (type == IDbType::dbtTYPE_FLOAT) return wxT("float");
	if (type == IDbType::dbtTYPE_DECIMAL) return wxT("float");
	if (type == IDbType::dbtTYPE_BOOLEAN) return wxT("bool");
	if (type == IDbType::dbtTYPE_OTHER) return wxT("Object*");
	return wxT("");
}

wxString ClassGenerateDialog::GetFillData(Column* pCol, int colIndex)
{
	if (pCol->GetPType()->GetUniversalType() == IDbType::dbtTYPE_TEXT) return wxT("\t\tpGrid->SetCellValue(wxString::Format(wxT(\"%s\"),current->Get")+ pCol->GetName() + wxString::Format(wxT("().c_str()),i,%i);"),colIndex);
	if (pCol->GetPType()->GetUniversalType() == IDbType::dbtTYPE_DATE_TIME) return wxT("\t\tpGrid->SetCellValue(current->Get")+ pCol->GetName() + wxString::Format(wxT("().Format(),i,%i);"),colIndex);
	if (pCol->GetPType()->GetUniversalType() == IDbType::dbtTYPE_INT) return wxT("\t\tpGrid->SetCellValue(wxString::Format(wxT(\"%i\"),current->Get")+ pCol->GetName() + wxString::Format(wxT("()),i,%i);"),colIndex);
	if (pCol->GetPType()->GetUniversalType() == IDbType::dbtTYPE_FLOAT) return wxT("\t\tpGrid->SetCellValue(wxString::Format(wxT(\"%f\"),current->Get")+ pCol->GetName() + wxString::Format(wxT("()),i,%i);"),colIndex);
	if (pCol->GetPType()->GetUniversalType() == IDbType::dbtTYPE_DECIMAL) return wxT("\t\tpGrid->SetCellValue(wxString::Format(wxT(\"%d\"),current->Get")+ pCol->GetName() + wxString::Format(wxT("()),i,%i);"),colIndex);
	if (pCol->GetPType()->GetUniversalType() == IDbType::dbtTYPE_BOOLEAN) return wxT("\t\tpGrid->SetCellValue(wxString::Format(wxT(\"%i\"),current->Get")+ pCol->GetName() + wxString::Format(wxT("()),i,%i);"),colIndex);
	if (pCol->GetPType()->GetUniversalType() == IDbType::dbtTYPE_OTHER) return wxT("\t\tpGrid->SetCellValue(wxT(\"some data\")") + wxString::Format(wxT(",i,%i);"),colIndex);
	return wxT("");
}

