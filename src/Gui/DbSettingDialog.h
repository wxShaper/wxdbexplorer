#ifndef DBSETTINGDIALOG_H
#define DBSETTINGDIALOG_H

#include "GUI.h" // Base class: _DBSettingsDialog
#include <wx/wx.h>
#include "DbViewerPanel.h"

#ifdef DBL_USE_MYSQL
#include "../Main/MySqlDbAdapter.h"
#endif

#ifdef DBL_USE_SQLITE
#include "../Main/SqliteDbAdapter.h"
#endif

#include "MysqlConnectionHistory.h"

class DbSettingDialog : public _DBSettingsDialog {

public:
	DbSettingDialog(DbViewerPanel *parent);
	virtual ~DbSettingDialog();

protected:
	virtual void OnCancelClick(wxCommandEvent& event);
	virtual void OnOkClick(wxCommandEvent& event);
	virtual void OnSqliteOkClick(wxCommandEvent& event);
	virtual void OnHistoruUI(wxUpdateUIEvent& event);
	virtual void OnHistoryClick(wxCommandEvent& event);
	virtual void OnHistoryDClick(wxCommandEvent& event);
	virtual void OnRemoveClick(wxCommandEvent& event);
	virtual void OnRmoveUI(wxUpdateUIEvent& event);
	virtual void OnSaveClick(wxCommandEvent& event);
	virtual void OnSaveUI(wxUpdateUIEvent& event);
	virtual void OnOKUI(wxUpdateUIEvent& event);

	void LoadHistory();


	DbViewerPanel *m_pParent;
	MysqlConnectionHistory *m_pHistory;
};

#endif // DBSETTINGDIALOG_H
