#ifndef DBSETTINGDIALOG_H
#define DBSETTINGDIALOG_H

#include "GUI.h" // Base class: _DBSettingsDialog
#include <wx/wx.h>
#include "DbViewerPanel.h"
#include "IDbConnector.h"
#include "MySqlDbConnector.h"
#include "SqliteDbConnector.h"
#include "../mysqldbadapter.h"
#include "../sqlitedbadapter.h"

class DbSettingDialog : public _DBSettingsDialog {

public:
	DbSettingDialog(DbViewerPanel *parent);
	virtual ~DbSettingDialog();

protected:
	virtual void OnCancelClick(wxCommandEvent& event);
	virtual void OnOkClick(wxCommandEvent& event);
	virtual void OnSqliteOkClick(wxCommandEvent& event);

	DbViewerPanel *m_pParent;
};

#endif // DBSETTINGDIALOG_H
