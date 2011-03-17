#ifndef CLASSGENERATEDIALOG_H
#define CLASSGENERATEDIALOG_H

#include "GUI.h" // Base class: _ClassGenerateDialog
#include "../ErdEngine/ErdTable.h"
#include "../ErdEngine/ErdView.h"
#include "../DbEngine/table.h"
#include "../Interfaces/IDbAdapter.h"
#include "wx/wxxmlserializer/XmlSerializer.h"
#include <wx/textfile.h>
#include <wx/stdpaths.h>
#include <wx/init.h>

class ClassGenerateDialog : public _ClassGenerateDialog {

	public:
		ClassGenerateDialog(wxWindow *parent, IDbAdapter* dbAdapter, xsSerializable* pItems);

		bool GenerateClass(Table* pTab, const wxString& path);
		wxString GetTypeName(IDbType::UNIVERSAL_TYPE type);
		wxString GetResTypeName(IDbType::UNIVERSAL_TYPE type);
		wxString GetFillData(Column* pCol, int colIndex);
		wxString GetResultFunction(IDbType::UNIVERSAL_TYPE type);
		wxString GetParamTypeName(IDbType::UNIVERSAL_TYPE type);
		wxString GetAddParamFunction(IDbType::UNIVERSAL_TYPE type);
		
		bool GenerateFile(Table* pTab,wxTextFile& htmpFile, wxTextFile& hFile, const wxString& classItemName,const wxString& classItemDef, const wxString& classColName, const wxString& classTableName, const wxString& classUtilName );

		virtual void OnCancelClick(wxCommandEvent& event);
		virtual void OnGenerateClick(wxCommandEvent& event);


		virtual ~ClassGenerateDialog();

protected:
		IDbAdapter* m_pDbAdapter;
		xsSerializable* m_pItems;

};

#endif // CLASSGENERATEDIALOG_H
