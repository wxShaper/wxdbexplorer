#ifndef DBEXPLORERPANEL_H
#define DBEXPLORERPANEL_H

#include "GUI.h" // Base class: _DbExplorerPanel
// database
#include <wx/dblayer/DatabaseLayer.h>
#include <wx/dblayer/MysqlDatabaseLayer.h>
// wx classes
#include <wx/wx.h>
#include <wx/hashmap.h>
#include <wx/aui/aui.h>
// xpm icons
#include "../res/gui/folder.xpm"
#include "../res/gui/form_blue.xpm"
// other
#include "../IDbItem.h"

#include "../DnDTableShape.h"

#include "../databasecol.h"
#include "../database.h"
#include "../tablecol.h"
#include "../table.h"
#include "../column.h"
#include "IDbAdapter.h"

#include "../MySqlDbAdapter.h"

#include "../dbitem.h"

WX_DECLARE_HASH_MAP( wxString, wxTreeItemId, wxStringHash, wxStringEqual, TableHashMap );

class DbViewerPanel : public _DbViewerPanel {

public:
	DbViewerPanel(wxWindow *parent, wxAuiNotebook* notebook);
	virtual ~DbViewerPanel();
	void SetDbAdapter(IDbAdapter *dbAdapter) {
		m_pDbAdapter = dbAdapter;
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

	void RefreshDbView();

protected:
	IDbAdapter* m_pDbAdapter;
	//DatabaseLayer *m_pDbLayer;
	wxString m_server;
	wxTreeItemId m_selectedID;
	wxAuiNotebook* m_pNotebook;

	TableHashMap m_hashTables;
};

#endif // DBEXPLORERPANEL_H
