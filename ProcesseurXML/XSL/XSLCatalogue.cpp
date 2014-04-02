#include "XSLCatalogue.h"

//class XSLCatalogue
XSLCatalogue::XSLCatalogue(list<XSLAttribut *>* atts,list<XSLTemplate *>* templates): atts(atts), templates(templates) {}

void XSLCatalogue::afficherHTML(Document ** docXML)
{
	for(list<XSLTemplate *>::iterator it = this->templates->begin(); it != this->templates->end(); it++){
		XSLTemplate templateCourant = **it;
		if (templateCourant.getPremierAttribut() == "/")
		{
			templateCourant.afficherHTML(docXML);
		}
	}
}
