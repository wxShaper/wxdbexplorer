///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov 18 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI__
#define __GUI__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/wxScintilla/wxscintilla.h>
#ifdef __VISUALC__
#include <wx/link_additions.h>
#endif //__VISUALC__
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/toolbar.h>
#include <wx/treectrl.h>
#include <wx/notebook.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/listbox.h>
#include <wx/filepicker.h>
#include <wx/statline.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/radiobox.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_CONNECT 1000
#define wxID_CLOSE_CONNECTION 1001
#define wxID_TOOL_REFRESH 1002
#define wxID_TOOL_ERD 1003
#define wxID_Sqlite_OK 1004
#define wxID_NEW_COL 1005
#define wxID_NEW_CONSTRAIN 1006
#define wxID_DEL 1007
#define wxID_PAGE_TYPE 1008
#define wxID_TX_SIZE 1009
#define wxID_PAGE_CONSTRAINT 1010

///////////////////////////////////////////////////////////////////////////////
/// Class _MainFrame
///////////////////////////////////////////////////////////////////////////////
class _MainFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar3;
		wxMenu* menuFile;
		wxMenu* menuHelp;
		wxStatusBar* m_statusBar1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		_MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("DatabaseExplorer "), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );
		
		~_MainFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _ThumbPane
///////////////////////////////////////////////////////////////////////////////
class _ThumbPane : public wxPanel 
{
	private:
	
	protected:
		wxBoxSizer* mainSizer;
	
	public:
		
		_ThumbPane( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~_ThumbPane();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _SqlCommandPanel
///////////////////////////////////////////////////////////////////////////////
class _SqlCommandPanel : public wxPanel 
{
	private:
	
	protected:
		wxScintilla* m_scintillaSQL;
		wxPanel* m_panel3;
		wxButton* m_btnExecute;
		wxStaticText* m_labelStatus;
		wxButton* m_btnSave;
		wxButton* m_btnLoad;
		wxGrid* m_gridTable;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnScintilaKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnExecuteClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		_SqlCommandPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,480 ), long style = wxTAB_TRAVERSAL ); 
		~_SqlCommandPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _AdapterSelectDlg
///////////////////////////////////////////////////////////////////////////////
class _AdapterSelectDlg : public wxDialog 
{
	private:
	
	protected:
		wxButton* m_btnMySql;
		wxButton* m_btnSqlite;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnMysqlClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSqliteClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		_AdapterSelectDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Select dbAdapter"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 200,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~_AdapterSelectDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _DbViewerPanel
///////////////////////////////////////////////////////////////////////////////
class _DbViewerPanel : public wxPanel 
{
	private:
	
	protected:
		wxNotebook* m_notebook2;
		wxPanel* m_panel2;
		wxToolBar* m_toolBar1;
		wxTreeCtrl* m_treeDatabases;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnConncectClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnConncectUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnToolCloseClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolCloseUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnRefreshClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnERDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDnDStart( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnItemActivate( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnItemRightClick( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnItemSelectionChange( wxTreeEvent& event ) { event.Skip(); }
		
	
	public:
		
		_DbViewerPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,500 ), long style = wxTAB_TRAVERSAL ); 
		~_DbViewerPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _DBSettingsDialog
///////////////////////////////////////////////////////////////////////////////
class _DBSettingsDialog : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_notebook2;
		wxPanel* m_MySqlPanel;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_txName;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_txServer;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_txUserName;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_txPassword;
		wxButton* m_btnOK;
		wxButton* m_btnCancel;
		wxButton* m_btnSave;
		wxButton* m_btnRemove;
		wxListBox* m_listBox2;
		wxPanel* m_Sqlite;
		wxStaticText* m_staticText11;
		wxFilePickerCtrl* m_filePickerSqlite;
		wxButton* m_btnOKSqlite;
		wxButton* m_btnCancel1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnRemoveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRmoveUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnHistoryClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHistoryDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHistoruUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnSqliteOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		_DBSettingsDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Conncetion settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~_DBSettingsDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _ErdPanel
///////////////////////////////////////////////////////////////////////////////
class _ErdPanel : public wxPanel 
{
	private:
	
	protected:
		wxToolBar* m_toolBarErd;
		wxPanel* m_wxsfPanel;
		wxBoxSizer* m_wxsfSizer;
	
	public:
		
		_ErdPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,480 ), long style = wxTAB_TRAVERSAL ); 
		~_ErdPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _TableSettings
///////////////////////////////////////////////////////////////////////////////
class _TableSettings : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel7;
		wxPanel* m_panel8;
		wxStaticText* m_staticText7;
		wxTextCtrl* m_txTableName;
		wxPanel* m_panel9;
		wxPanel* m_panel13;
		wxListBox* m_listColumns;
		wxPanel* m_panel14;
		wxButton* m_button8;
		wxButton* m_button15;
		wxButton* m_button10;
		wxButton* m_button9;
		wxStaticLine* m_staticline2;
		wxNotebook* m_notebook3;
		wxPanel* m_pageType;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_txColName;
		wxStaticText* m_staticText9;
		wxComboBox* m_comboType;
		wxStaticText* m_stSize;
		wxTextCtrl* m_txSize;
		wxCheckBox* m_chPrimary;
		wxCheckBox* m_chNotNull;
		wxCheckBox* m_checkBox3;
		wxCheckBox* m_chAutoIncrement;
		wxPanel* m_pageConstraint;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_txConstraintName;
		wxStaticText* m_staticText12;
		wxComboBox* m_comboLocalColumn;
		wxRadioBox* m_radioBox1;
		wxStaticText* m_staticText13;
		wxComboBox* m_comboRefTable;
		wxStaticText* m_staticText14;
		wxComboBox* m_comboRefColumn;
		wxStdDialogButtonSizer* m_sdbSizer2;
		wxButton* m_sdbSizer2OK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnListBoxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNewColumnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNewConstrainClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteColumn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveColumnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNotebookUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnPageTypeUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnColNameUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnTypeSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnColTypeUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnColSizeUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnPrimaryKeyUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnNotNullUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnUniqueUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnAutoIncrementUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnPageConstraintUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnRefTabChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRefTabUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnRefColUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		_TableSettings( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Table settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~_TableSettings();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class _CreateForeignKey
///////////////////////////////////////////////////////////////////////////////
class _CreateForeignKey : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText15;
		wxTextCtrl* m_txSrcTable;
		wxStaticText* m_staticText17;
		wxComboBox* m_cmbSrcCol;
		wxRadioBox* m_radioBox3;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_txDstTable;
		wxStaticText* m_staticText18;
		wxComboBox* m_cmbDstCol;
		
		
		wxButton* m_btnCancel;
		wxButton* m_btnOK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKUI( wxUpdateUIEvent& event ) { event.Skip(); }
		
	
	public:
		
		_CreateForeignKey( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create foreign key"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~_CreateForeignKey();
	
};

#endif //__GUI__
