#ifndef DNDTABLESHAPE_H
#define DNDTABLESHAPE_H

#include <wx/wxsf/ShapeBase.h> // Base class: wxSFShapeBase
#include "../DbEngine/table.h"

class dndTableShape : public wxSFShapeBase {

public:
	XS_DECLARE_CLONABLE_CLASS(dndTableShape);
	dndTableShape();
	dndTableShape(Table* tab);
	virtual ~dndTableShape();
};

#endif // DNDTABLESHAPE_H
