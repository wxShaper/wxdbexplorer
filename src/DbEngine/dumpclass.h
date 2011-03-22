#ifndef DUMPCLASS_H
#define DUMPCLASS_H

#include <wx/wx.h>
#include <wx/textfile.h>
#include "../Interfaces/IDbAdapter.h"
#include "../DbEngine/table.h"
#include <wx/wxxmlserializer/XmlSerializer.h>



class DumpClass {

public:
	DumpClass(IDbAdapter* pDbAdapter, xsSerializable* pItems, const wxString& fileName);
	virtual ~DumpClass();
	
	wxString DumpData();

	
protected:
	bool DumpTable(wxTextFile* pFile, Table* pTab);
	wxString m_fileName;
	xsSerializable* m_pItems;
	IDbAdapter* m_pDbAdapter;

};

#endif // DUMPCLASS_H
