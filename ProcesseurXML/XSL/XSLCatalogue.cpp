#include "XSLCatalogue.h"

//class XSLCatalogue
XSLCatalogue::XSLCatalogue(list<XSLAttribut *>* atts,list<XSLTemplate *>* templates): atts(atts), templates(templates) {}

void XSLCatalogue::afficherHTML(Element* elementXML)
{
	for(list<XSLTemplate *>::iterator it = this->templates->begin(); it != this->templates->end(); it++){
		XSLTemplate templateCourant = **it;
		if (templateCourant.getPremierAttribut() == "/")
		{
			templateCourant.afficherHTML(elementXML);
		}
	}
}

list<XSLTemplate *>* XSLCatalogue::getTemplates()
{
	return templates;
}
