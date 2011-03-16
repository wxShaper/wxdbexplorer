#include "ClassGenerateDialog.h"
#include "../Main/DatabaseExplorerApp.h"

ClassGenerateDialog::ClassGenerateDialog(wxWindow *parent, IDbAdapter* dbAdapter, xsSerializable* pItems):_ClassGenerateDialog(parent) {
	m_pDbAdapter = dbAdapter;
	m_pItems = pItems;	
	}

ClassGenerateDialog::~ClassGenerateDialog() {
}

bool ClassGenerateDialog::GenerateClass(Table* pTab, const wxString& path) {
	wxTextFile htmpFile(FindAppPath() + wxT("/dataClass.htmp"));
	wxTextFile ctmpFile(FindAppPath() + wxT("/dataClass.ctmp"));

	if (!htmpFile.Open()) return false;
	if (!ctmpFile.Open()) return false;
	wxString classTableName = pTab->GetName();
	wxString classItemName = pTab->GetName() + wxT("Base");
	wxString classItemDef = pTab->GetName().Upper() + wxT("_H");
	wxString classColName = pTab->GetName() + wxT("ColBase");

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
	bool suc = GenerateHFile(pTab,htmpFile,hFile, classItemName, classItemDef,classColName,classTableName );
	suc &= GenerateCFile(pTab,ctmpFile,cFile, classItemName, classItemDef,classColName,classTableName);
	
	
	hFile.Write();
	hFile.Close();
	cFile.Write();
	cFile.Close();
	htmpFile.Close();
	ctmpFile.Close();
	return suc;
}

void ClassGenerateDialog::OnCancelClick(wxCommandEvent& event) {
}

void ClassGenerateDialog::OnGenerateClick(wxCommandEvent& event) {
	SerializableList::compatibility_iterator node = m_pItems->GetFirstChildNode();
	while( node ) {
		Table* pTab = wxDynamicCast(node->GetData(),Table);
		if (pTab){
			if (GenerateClass(pTab, m_dirPicker1->GetPath())) m_textCtrl19->AppendText(pTab->GetName() + wxT("......... Generated successful!\n"));			
			else m_textCtrl19->AppendText(pTab->GetName() + wxT("......... Error!!!\n"));			 	
			}

		node = node->GetNext();
	}	
}


wxString ClassGenerateDialog::FindAppPath()
{
   wxString str;

    // Try appVariableName
    if (!wxGetApp().GetAppName().IsEmpty())
    {
        str = wxGetenv(wxGetApp().GetAppName());
        if (!str.IsEmpty())
            return str;
    }

#if defined(__WXMAC__) && !defined(__DARWIN__)
    // On Mac, the current directory is the relevant one when
    // the application starts.
    return wxGetCwd();
#endif

    if (wxIsAbsolutePath(wxGetApp().argv[0]))
        return wxPathOnly(wxGetApp().argv[0]);
    else
    {
        // Is it a relative path?
        wxString currentDir(wxGetCwd());
        if (currentDir.Last() != wxFILE_SEP_PATH)
            currentDir += wxFILE_SEP_PATH;

        str = currentDir + wxGetApp().argv[0];
        if (wxFileExists(str))
            return wxPathOnly(str);
    }

    // OK, it's neither an absolute path nor a relative path.
    // Search PATH.

    wxPathList pathList;
    pathList.AddEnvList(wxT("PATH"));
    str = pathList.FindAbsoluteValidPath(wxGetApp().argv[0]);
    if (!str.IsEmpty())
        return wxPathOnly(str);

    // Failed
    return wxEmptyString;
}
wxString ClassGenerateDialog::GetTypeName(IDbType::UNIVERSAL_TYPE type)
{
	if (type == IDbType::dbtTYPE_TEXT) return wxT("wxString&");
	if (type == IDbType::dbtTYPE_DATE_TIME) return wxT("DateTime");
	if (type == IDbType::dbtTYPE_INT) return wxT("int");
	if (type == IDbType::dbtTYPE_FLOAT) return wxT("float");
	if (type == IDbType::dbtTYPE_DECIMAL) return wxT("float");
	if (type == IDbType::dbtTYPE_BOOLEAN) return wxT("bool");
	if (type == IDbType::dbtTYPE_OTHER) return wxT("Object*");
}

wxString ClassGenerateDialog::GetResultFunction(IDbType::UNIVERSAL_TYPE type)
{
	if (type == IDbType::dbtTYPE_TEXT) return wxT("GetResultString&");
	if (type == IDbType::dbtTYPE_DATE_TIME) return wxT("GetResultDate");
	if (type == IDbType::dbtTYPE_INT) return wxT("GetResultInt");
	if (type == IDbType::dbtTYPE_FLOAT) return wxT("GetResultDouble");
	if (type == IDbType::dbtTYPE_DECIMAL) return wxT("GetResultDouble");
	if (type == IDbType::dbtTYPE_BOOLEAN) return wxT("GetResultBool");
	if (type == IDbType::dbtTYPE_OTHER) return wxT("GetResultBlob");
}

bool ClassGenerateDialog::GenerateHFile(Table* pTab, wxTextFile& htmpFile, wxTextFile& hFile, const wxString& classItemName, const wxString& classItemDef, const wxString& classColName, const wxString& classTableName )
{
	for ( wxString str = htmpFile.GetFirstLine(); !htmpFile.Eof(); str = htmpFile.GetNextLine() )
	{
		if (str.Contains(wxT("%%classItemGetters%%"))){
				SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
				while( node ) {
					Column* pCol = wxDynamicCast(node->GetData(),Column);
					if (pCol){
						hFile.AddLine(wxString::Format(wxT("\tconst %s Get%s() const {"), GetTypeName(pCol->GetPType()->GetUniversalType()).c_str(), pCol->GetName().c_str()));
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
						hFile.AddLine(wxString::Format(wxT("\tm_%s = %s(wxT(\"%s\"));"),pCol->GetName().c_str(), GetResultFunction(pCol->GetPType()->GetUniversalType()).c_str(), pCol->GetName().c_str()));
						}					
					node = node->GetNext();
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

bool ClassGenerateDialog::GenerateCFile(Table* pTab, wxTextFile& ctmpFile, wxTextFile& cFile, const wxString& classItemName, const wxString& classItemDef, const wxString& classColName, const wxString& classTableName )
{
	for ( wxString str = ctmpFile.GetFirstLine(); !ctmpFile.Eof(); str = ctmpFile.GetNextLine() )
	{
		if (str.Contains(wxT("%%classItemGetters%%"))){
				SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
				while( node ) {
					Column* pCol = wxDynamicCast(node->GetData(),Column);
					if (pCol){
						cFile.AddLine(wxString::Format(wxT("\tconst %s Get%s() const {"), GetTypeName(pCol->GetPType()->GetUniversalType()).c_str(), pCol->GetName().c_str()));
						cFile.AddLine(wxString::Format(wxT("\t\treturn m_%s;"), pCol->GetName().c_str()));
						cFile.AddLine(wxString::Format(wxT("\t\t}")));						
						}					
					node = node->GetNext();
					}
			
		}else if (str.Contains(wxT("%%classItemVariables%%"))){
				SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
				while( node ) {
					Column* pCol = wxDynamicCast(node->GetData(),Column);
					if (pCol){
						cFile.AddLine(wxString::Format(wxT("\t%s m_%s;"), GetTypeName(pCol->GetPType()->GetUniversalType()).c_str(), pCol->GetName().c_str()));
						}					
					node = node->GetNext();
					}		
		}else if (str.Contains(wxT("%%classItemLoading%%"))){
				SerializableList::compatibility_iterator node = pTab->GetFirstChildNode();
				while( node ) {
					Column* pCol = wxDynamicCast(node->GetData(),Column);
					if (pCol){
						cFile.AddLine(wxString::Format(wxT("\tm_%s = %s(wxT(\"%s\"));"),pCol->GetName().c_str(), GetResultFunction(pCol->GetPType()->GetUniversalType()).c_str(), pCol->GetName().c_str()));
						}					
					node = node->GetNext();
					}				
		}else{
			str.Replace(wxT("%%classItemName%%"),classItemName);
			str.Replace(wxT("%%classItemDef%%"),classItemDef);
			str.Replace(wxT("%%classColName%%"),classColName);
			str.Replace(wxT("%%classTableName%%"),classTableName);
			cFile.AddLine(str);			
		}	
	}
	return true;
}

