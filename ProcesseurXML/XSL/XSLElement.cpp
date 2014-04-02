#include "XSLElement.h"

XSLElement::XSLElement(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : type(type), atts(atts), elementsInclus(elementsInclus) {}

string XSLElement::getType()
{
	return type;
}

void XSLElement::afficherElements(ContentItem * elementXML) 
{
	cout << "coucou XSL element" << endl;
}
