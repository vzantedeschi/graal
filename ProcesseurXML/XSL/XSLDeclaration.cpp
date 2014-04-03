#include "XSLDeclaration.h"

//class XSLDeclaration
XSLDeclaration::XSLDeclaration(list<XSLAttribut *> *atts): atts(atts) {}

XSLDeclaration::~XSLDeclaration()
{
	for(XSLAttribut * att: *atts)
	{
		delete att;
	}
	delete atts;
}