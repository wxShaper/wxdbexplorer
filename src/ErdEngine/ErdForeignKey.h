#ifndef ERDFOREIGNKEY_H
#define ERDFOREIGNKEY_H
#include <wx/wx.h>
#include <wx/wxxmlserializer/XmlSerializer.h>
#include "wx/wxsf/OrthoShape.h" // Base class: wxSFOrthoLineShape
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
