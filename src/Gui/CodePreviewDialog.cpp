#include "CodePreviewDialog.h"

CodePreviewDialog::CodePreviewDialog(wxWindow* parent, const wxString& sourceCode):_CodePreviewDialog(parent)
{	
	m_scintilla3->SetText(sourceCode);
	m_scintilla3->SetReadOnly(true);
	DatabaseExplorerFrame::InitStyledTextCtrl( m_scintilla3 );
}

CodePreviewDialog::~CodePreviewDialog()
{
}

void CodePreviewDialog::OnOKClick(wxCommandEvent& event)
{
	Destroy();
}
