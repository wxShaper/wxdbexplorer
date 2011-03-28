#ifndef ERDCOMMITDIALOG_H
#define ERDCOMMITDIALOG_H

#include "GUI.h" // Base class: _ErdCommitDialog
#include <wx/wx.h>
#include <wx/imaglist.h>
#include <wx/dblayer/include/DatabaseLayer.h>
#include <wx/dblayer/include/DatabaseLayerException.h>
#include "wx/wxxmlserializer/XmlSerializer.h"

#include "../DbEngine/dbconnection.h"
#include "../DbEngine/dbitem.h"
#include "../DbEngine/view.h"
#include "../DbEngine/dumpclass.h"
#include "Art.h"

class ErdCommitDialog : public _ErdCommitDialog {

	public:
		ErdCommitDialog(wxWindow* pParent, xsSerializable* pConnections, const wxString& createScript);
		virtual ~ErdCommitDialog();

		virtual void OnBackupUI(wxUpdateUIEvent& event);
		virtual void OnBtnBack(wxCommandEvent& event);
		virtual void OnBtnBackUI(wxUpdateUIEvent& event);
		virtual void OnBtnBackup(wxCommandEvent& event);
		virtual void OnBtnWrite(wxCommandEvent& event);
		virtual void OnNextUI(wxUpdateUIEvent& event);
		virtual void OnNtbPageChanging(wxNotebookEvent& event);
		virtual void OnStructureFileUI(wxUpdateUIEvent& event);
		virtual void OnWriteUI(wxUpdateUIEvent& event);
		virtual void OnBtnNext(wxCommandEvent& event);
		virtual void OnBtnRestoreClick(wxCommandEvent& event);
		virtual void OnBtnRestoreUI(wxUpdateUIEvent& event);
		virtual void OnShowSqlClick(wxCommandEvent& event);


	protected:
		xsSerializable* m_pConnections;
		wxString m_createScript;

		bool canTabChange;
		bool backuped;

		Database* m_pSelectedDatabase;


		void Load();
};

#endif // ERDCOMMITDIALOG_H
