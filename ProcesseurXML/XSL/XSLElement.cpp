#include "XSLElement.h"

XSLElement::XSLElement(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : type(type), atts(atts), elementsInclus(elementsInclus) {}

XSLElement::~XSLElement()
{
	if(atts)
	{
		for(list<XSLAttribut *>::iterator it = atts->begin(); it != atts->end(); it++)
		{
			delete *it;
		}
		delete atts;
	}
	if(elementsInclus)
	{
		for(list<XSLElement *>::iterator it = elementsInclus->begin(); it != elementsInclus->end(); it++)
		{
			delete *it;
		}
		delete elementsInclus;
	}
	
}

string XSLElement::getType()
{
	return type;
}

void XSLElement::afficherElements(ContentItem * elementXML) 
{
}
