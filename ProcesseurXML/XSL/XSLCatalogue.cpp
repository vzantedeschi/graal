#include "XSLCatalogue.h"

//class XSLCatalogue
XSLCatalogue::XSLCatalogue(list<XSLAttribut *>* atts,list<XSLTemplate *>* templates): atts(atts), templates(templates) {}

void XSLCatalogue::afficherHTML(Document ** docXML)
{
	printf("Afficher Catalogue");
}
