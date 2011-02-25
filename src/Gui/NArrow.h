#ifndef NARROW_H
#define NARROW_H

#include <wx/wx.h>
#include <wx/wxsf/SolidArrow.h> // Base class: wxSFArrowBase

class NArrow : public wxSFSolidArrow {

public:
	XS_DECLARE_CLONABLE_CLASS(NArrow);
	
	
	NArrow(void);
	NArrow(wxSFShapeBase* parent);
	NArrow(const NArrow& obj);
	virtual ~NArrow();

public:
	virtual void Draw(const wxRealPoint& from, const wxRealPoint& to, wxDC& dc);
};

#endif // NARROW_H
