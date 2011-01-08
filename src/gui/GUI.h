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
#include <wx/frame.h>
#include <wx/wxScintilla/wxscintilla.h>
#ifdef __VISUALC__
#include <wx/link_additions.h>
#endif //__VISUALC__
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/toolbar.h>
#include <wx/treectrl.h>
#include <wx/statline.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/notebook.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/filepicker.h>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/combobox.h>
#include <wx/valtext.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_TOOL_REFRESH 1000
#define wxID_TOOL_ERD 1001
#define wxID_Sqlite_OK 1002
#define wxID_TX_NAME 1003
#define wxID_TX_SIZE 1004

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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		_MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("DatabaseExplorer "), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );
		
		~_MainFrame();
	
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
		wxStaticLine* m_staticline1;
		wxPropertyGrid* m_propertyGrid;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnConncectClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnConncectUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnRefreshClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnERDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnItemActivate( wxTreeEvent& event ) { event.Skip(); }
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
		wxStaticText* m_staticText1;
		wxTextCtrl* m_txServer;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_txUserName;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_txPassword;
		wxButton* m_btnOK;
		wxButton* m_btnCancel;
		wxPanel* m_Sqlite;
		wxStaticText* m_staticText11;
		wxFilePickerCtrl* m_filePickerSqlite;
		wxButton* m_btnOKSqlite;
		wxButton* m_btnCancel1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
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
		wxNotebook* m_notebook3;
		wxPanel* m_nbMainPanel;
		wxStaticText* m_staticText6;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTxNameChange( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxTextCtrl* m_txName;
		
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
		wxButton* m_button9;
		wxStaticLine* m_staticline2;
		wxPanel* m_panel11;
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
		wxStdDialogButtonSizer* m_sdbSizer2;
		wxButton* m_sdbSizer2OK;
		wxButton* m_sdbSizer2Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnListBoxClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNewColumnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveColumnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnColNameUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnTypeSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnColTypeUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnColSizeUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnPrimaryKeyUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnNotNullUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnUniqueUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnAutoIncrementUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		_TableSettings( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Table settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~_TableSettings();
	
};

#endif //__GUI__
