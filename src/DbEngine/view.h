#ifndef VIEW_H
#define VIEW_H

#include <wx/wx.h>
#include <wx/dblayer/include/DatabaseResultSet.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "../Interfaces/IDbAdapter.h"
// ------------------------------------------------
// Trida View
// -------------------------------------------------

class View : public xsSerializable {

public:
	XS_DECLARE_CLONABLE_CLASS(View);
	View();
	View(const View& obj);
	View(IDbAdapter* dbAdapter,const wxString& name, const wxString& parentName, const wxString& select);
	virtual ~View();


	void SetName(const wxString & name) {
		this->m_name = name;
	}
	void SetParentName(const wxString & parentName) {
		this->m_parentName = parentName;
	}
	void SetSelect(const wxString & select) {
		this->m_select = select;
	}
	const wxString & GetName() const {
		return m_name;
	}
	const wxString & GetParentName() const {
		return m_parentName;
	}
	const wxString & GetSelect() const {
		return m_select;
	}

	IDbAdapter * GetDbAdapter() {
		return m_pDbAdapter;
	}

protected:
	wxString m_name;
	wxString m_parentName;
	wxString m_select;
	void initSerializable();
	IDbAdapter* m_pDbAdapter;
};

#endif // VIEW_H
