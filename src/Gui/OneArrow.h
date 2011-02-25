#ifndef ONEARROW_H
#define ONEARROW_H

#include <wx/wx.h>
#include <wx/wxsf/SolidArrow.h> // Base class: wxSFArrowBase

class OneArrow : public wxSFSolidArrow {

public:
	XS_DECLARE_CLONABLE_CLASS(OneArrow);
	OneArrow(void);
	OneArrow(wxSFShapeBase* parent);
	OneArrow(const OneArrow& obj);
	virtual ~OneArrow();

public:
	virtual void Draw(const wxRealPoint& from, const wxRealPoint& to, wxDC& dc);
};

#endif // ONEARROW_H
