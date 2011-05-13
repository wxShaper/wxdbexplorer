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
		/*! \brief Defautl constructor.  */
		ClassGenerateDialog(wxWindow *parent, IDbAdapter* dbAdapter, xsSerializable* pItems);

		/*! \brief Return string with type name on UNIVERSAL TYPE base */
		wxString GetTypeName(IDbType::UNIVERSAL_TYPE type);
		/*! \brief Return string with type name in result format on UNIVERSAL TYPE base */
		wxString GetResTypeName(IDbType::UNIVERSAL_TYPE type);
		/*! \brief Return row for filling table row attribute. */
		wxString GetFillData(Column* pCol, int colIndex);
		/*! \brief Return string with type name on UNIVERSAL TYPE base */
		wxString GetResultFunction(IDbType::UNIVERSAL_TYPE type);
		/*! \brief Return string with type name in function parameter format on UNIVERSAL TYPE base */
		wxString GetParamTypeName(IDbType::UNIVERSAL_TYPE type);
		/*! \brief Return string with type name in add function format on UNIVERSAL TYPE base */
		wxString GetAddParamFunction(IDbType::UNIVERSAL_TYPE type);


		/*! \brief Function for generating classes for selected table. It call GenerateFile function two times. Fist time for generate .h, second time for generate .cpp file. */
		bool GenerateClass(Table* pTab, const wxString& path);	

		/*! \brief Function for generating file for selected table.  */
		bool GenerateFile(Table* pTab,wxTextFile& htmpFile, wxTextFile& hFile, const wxString& classItemName,const wxString& classItemDef, const wxString& classColName, const wxString& classTableName, const wxString& classUtilName );

		virtual void OnCancelClick(wxCommandEvent& event);
		
		/*! \brief Function for generating classes for all tables. It call GenerateClass() function for each table. */
		virtual void OnGenerateClick(wxCommandEvent& event);


		virtual ~ClassGenerateDialog();

protected:
		IDbAdapter* m_pDbAdapter;
		xsSerializable* m_pItems;

};

#endif // CLASSGENERATEDIALOG_H
