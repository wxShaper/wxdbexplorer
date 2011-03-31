#ifndef ERDCOMMITWIZARD_H
#define ERDCOMMITWIZARD_H

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/wizard.h>
#include <wx/imaglist.h>
#include <wx/filepicker.h>
#include <wx/statline.h>
#include <wx/txtstrm.h>
#include <wx/wfstream.h>
#include <wx/dblayer/include/DatabaseLayer.h>
#include <wx/dblayer/include/DatabaseLayerException.h>
#include "wx/wxxmlserializer/XmlSerializer.h"

#include "../DbEngine/dbconnection.h"
#include "../DbEngine/database.h"
#include "../DbEngine/dbitem.h"
#include "../DbEngine/dumpclass.h"
#include "../DbEngine/view.h"
#include "CodePreviewDialog.h"

#include "Art.h"

class ErdCommitWizard : public wxWizard {

public:
	ErdCommitWizard(wxWindow* parent, xsSerializable* pConnections, const wxString& createScript);
	virtual ~ErdCommitWizard();

	wxWizardPageSimple* GetFirstPage();
	
	void SetSelectedDatabase(Database* db) { m_pSelectedDatabase = db; }
	Database* GetSelectedDatabase() { return m_pSelectedDatabase; }
	const wxString& GetCreateScript() { return m_createScript; }
	
protected:
	wxWizardPageSimple* m_pFirstPage;
	wxString m_createScript;
	xsSerializable* m_pConnections;
	
	Database* m_pSelectedDatabase;
	
};


class FirstPage : public wxWizardPageSimple {

public:
	FirstPage(wxWizard* parent);
	virtual ~FirstPage();	
	};

class DatabasePage : public wxWizardPageSimple{

public:

	DatabasePage(ErdCommitWizard* parent, xsSerializable* pConnections );
	virtual ~DatabasePage();	
protected:
	virtual bool TransferDataFromWindow();
    void LoadDatabases();
	
	ErdCommitWizard* m_pParentWizard;
	xsSerializable* m_pConnections;
	wxTreeCtrl* m_treeDatabases;
	wxFlexGridSizer* m_mainSizer;
	
	};

class BackupPage : public wxWizardPageSimple{
public:
	BackupPage(ErdCommitWizard* parent);
	virtual ~BackupPage();
	
protected:
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();
	
	void OnFileStructureUI(wxUpdateUIEvent& event);
	void OnBtnBackupUI(wxUpdateUIEvent& event);
	void OnBtnBackupClick(wxCommandEvent& event);
	
	ErdCommitWizard* m_pParentWizard;
	wxFlexGridSizer* m_mainSizer;
	
	wxFilePickerCtrl* m_pFileData;
	wxFilePickerCtrl* m_pFileStructure;
	wxCheckBox* m_pCheckStructure;
	
	wxButton* m_btnBackup;
	
	bool backuped;
	};


class WriteStructurePage : public wxWizardPageSimple{
public:
	WriteStructurePage(ErdCommitWizard* parent);
	virtual ~WriteStructurePage();
	
	
protected:
	virtual bool TransferDataToWindow();
	virtual bool TransferDataFromWindow();
	
	void OnBtnWriteClick(wxCommandEvent& event);
	void OnBtnShowSqlClick(wxCommandEvent& event);
	
	
	ErdCommitWizard* m_pParentWizard;	 
	 
	wxFlexGridSizer* m_mainSizer;
	
	wxTextCtrl* m_txLog;
	
	wxButton* m_btnWrite;
	wxButton* m_btnShowSql;
	
	bool commited;
	};
	
class LastPage : public wxWizardPageSimple{
public:
	LastPage(wxWizard* parent);
	virtual ~LastPage();	
	
	}; 

class RestorePage : public wxWizardPageSimple{
public:
	RestorePage(ErdCommitWizard* parent);
	virtual ~RestorePage();

protected:
	void OnBtnRestoreUI(wxUpdateUIEvent& event);
	void OnBtnRestoreClick(wxCommandEvent& event);
	void Clear();
	void AppendText(const wxString& txt);
	void AppendComment(const wxString& txt);
	void AppendSeparator();
	
	
	wxString m_text;
	ErdCommitWizard* m_pParentWizard;
	wxFlexGridSizer* m_mainSizer;
	wxFilePickerCtrl* m_restoreFile;
	wxTextCtrl* m_txLog;
	
	wxButton* m_btnRestore;
	};

#endif // ERDCOMMITWIZARD_H
