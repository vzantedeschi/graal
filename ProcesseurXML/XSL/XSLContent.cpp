#include "XSLContent.h"


XSLContent::XSLContent(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : XSLElement(type, atts, elementsInclus) {}

void XSLContent::afficherElements(ContentItem* elementXML)
{
	cout << this->getType() << endl;
}
