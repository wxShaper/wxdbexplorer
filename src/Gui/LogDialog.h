#ifndef LOGDIALOG_H
#define LOGDIALOG_H

#include <wx/utils.h> 

#include "GUI.h" // Base class: _LogDialog

class LogDialog : public _LogDialog {

public:
	LogDialog(wxWindow* parent);
	virtual ~LogDialog();

	virtual void OnCloseClick(wxCommandEvent& event);
	virtual void OnCloseUI(wxUpdateUIEvent& event);
	
	void EnableClose(bool enable){ m_canClose = enable; }
	void Clear();
	void AppendText(const wxString& txt);
	void AppendComment(const wxString& txt);
	void AppendSeparator();
	
protected:
	bool m_canClose;
	wxString m_text;
};

#endif // LOGDIALOG_H
