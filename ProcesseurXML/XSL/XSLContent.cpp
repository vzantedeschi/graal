#include "XSLContent.h"


XSLContent::XSLContent(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : XSLElement(type, atts, elementsInclus) {}

void XSLContent::afficherElements()
{
	cout << this->getType() << endl;
}
