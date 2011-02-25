#ifndef ERDFOREIGNKEY_H
#define ERDFOREIGNKEY_H
#include <wx/wx.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include <wx/wxsf/TextShape.h>
#include <wx/wxsf/CircleArrow.h>
#include <wx/wxsf/SolidArrow.h>

#include "wx/wxsf/OrthoShape.h" // Base class: wxSFOrthoLineShape

#include "../Gui/NArrow.h"
#include "../Gui/OneArrow.h"
#include "DbEngine/constraint.h"

class ErdForeignKey : public wxSFOrthoLineShape {
public:
	XS_DECLARE_CLONABLE_CLASS(ErdForeignKey);	
	ErdForeignKey();
	ErdForeignKey(const ErdForeignKey& obj);
	ErdForeignKey(Constraint* pConstraint);
	virtual ~ErdForeignKey();

protected:
	Constraint* m_pConstraint;
};

#endif // ERDFOREIGNKEY_H
