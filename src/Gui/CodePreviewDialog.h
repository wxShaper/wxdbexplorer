#ifndef CODEPREVIEWDIALOG_H
#define CODEPREVIEWDIALOG_H

#include <wx/wx.h>
#include "DatabaseExplorerFrame.h"
#include "GUI.h" // Base class: _CodePreviewDialog
/*! \brief Dialog for code preview. Dialog support syntax highlighting. */
class CodePreviewDialog : public _CodePreviewDialog {

public:
	CodePreviewDialog(wxWindow* parent, const wxString& sourceCode);
	virtual ~CodePreviewDialog();

public:
	virtual void OnOKClick(wxCommandEvent& event);
};

#endif // CODEPREVIEWDIALOG_H
