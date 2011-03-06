#ifndef DBEXPLORERPANEL_H
#define DBEXPLORERPANEL_H

#include "GUI.h" // Base class: _DbExplorerPanel
// database
#include <wx/dblayer/include/DatabaseLayer.h>

#ifdef DBL_USE_MYSQL
#include <wx/dblayer/include/MysqlDatabaseLayer.h>
#endif

#include <wx/wxsf/Thumbnail.h>

// wx classes
#include <wx/wx.h>
#include <wx/hashmap.h>
#include <wx/aui/aui.h>
#include <wx/textdlg.h>
#include <wx/txtstrm.h>

// other
#include "../Interfaces/IDbItem.h"

#include "../ErdEngine/DnDTableShape.h"
#include "../DbEngine/dbconnection.h"
#include "../DbEngine/databasecol.h"
#include "../DbEngine/database.h"
#include "../DbEngine/tablecol.h"
#include "../DbEngine/table.h"
#include "../DbEngine/column.h"
#include "../DbEngine/view.h"
#include "../Interfaces/IDbAdapter.h"
#include "../Main/MySqlDbAdapter.h"
#include "../DbEngine/dbitem.h"
#include "../Gui/LogDialog.h"

#include "Ids.h"

WX_DECLARE_HASH_MAP( wxString, wxTreeItemId, wxStringHash, wxStringEqual, TableHashMap );

class DbViewerPanel : public _DbViewerPanel {

public:
	DbViewerPanel(wxWindow *parent, wxAuiNotebook* notebook);
	virtual ~DbViewerPanel();
	void SetDbAdapter(IDbAdapter *dbAdapter) {
		m_pDbAdapter = dbAdapter;
	}

	void AddDbConnection(DbConnection* pDbCon) {
		m_pConnections->AddChild(pDbCon);
	}

	void SetServer(wxString& server) {
		m_server = server;
	}

	virtual void OnConncectClick(wxCommandEvent& event);
	virtual void OnConncectUI(wxUpdateUIEvent& event);
	virtual void OnItemActivate(wxTreeEvent& event);
	virtual void OnRefreshClick(wxCommandEvent& event);
	virtual void OnItemSelectionChange(wxTreeEvent& event);
	virtual void OnERDClick(wxCommandEvent& event);
	virtual void OnDnDStart(wxTreeEvent& event);
	virtual void OnItemRightClick(wxTreeEvent& event);
	virtual void OnToolCloseClick(wxCommandEvent& event);
	virtual void OnToolCloseUI(wxUpdateUIEvent& event);

	void OnPageChange(wxAuiNotebookEvent& event);

	void OnPopupClick(wxCommandEvent &evt);


	void RefreshDbView();

protected:

	xsSerializable* m_pConnections;

	IDbAdapter* m_pDbAdapter;
	//DatabaseLayer *m_pDbLayer;
	wxString m_server;
	wxTreeItemId m_selectedID;
	wxAuiNotebook* m_pNotebook;

	TableHashMap m_hashTables;
	Database* m_pEditedDatabase;
	DbConnection* m_pEditedConnection;
	wxSFThumbnail* m_pThumbnail;
	
	bool ImportDb(const wxString& sqlFile, Database* pDb);
};

#endif // DBEXPLORERPANEL_H
