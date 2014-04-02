#include "XSLTemplate.h"

XSLTemplate::XSLTemplate(list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : atts(atts), elementsInclus(elementsInclus) {}

void XSLTemplate::afficherHTML(ContentItem* elementXML)
{
	for(list<XSLElement *>::iterator it = this->elementsInclus->begin(); it != this->elementsInclus->end(); it++){
		XSLElement* elementCourant = *it;
		elementCourant->afficherElements(elementXML);
	}
}

string XSLTemplate::getPremierAttribut()
{
	auto l_front = (*atts).begin();

	advance(l_front, 0);

	return (*l_front)->getValeur();
}
