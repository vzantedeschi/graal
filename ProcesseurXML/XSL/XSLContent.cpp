#include "XSLContent.h"


XSLContent::XSLContent(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : XSLElement(type, NULL, NULL) {}

XSLContent::~XSLContent()
{
}

void XSLContent::afficherElements(ContentItem* elementXML)
{
	cout << this->getType() << endl;
}

void XSLContent::afficherElements(Document ** xmlD)
{
	cout << this->getType() << endl;
}
