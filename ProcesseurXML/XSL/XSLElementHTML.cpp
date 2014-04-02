#include "XSLElementHTML.h"

XSLElementHTML::XSLElementHTML(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : XSLElement(type, atts, elementsInclus) {}

void XSLElementHTML::afficherElements()
{
	if (elementsInclus)
	{
		cout << "<" << this->getType() << ">" << endl;
		for(list<XSLElement *>::iterator it = this->elementsInclus->begin(); it != this->elementsInclus->end(); it++){
			XSLElement* elementCourant = *it;
			elementCourant->afficherElements();
		}
		cout << "</" << this->getType() << ">" << endl;
	}
	else
	{
		cout << "<" << this->getType() << "/>" << endl;
	}
}
