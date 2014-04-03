#include "XSLCatalogue.h"

//class XSLCatalogue
XSLCatalogue::XSLCatalogue(list<XSLAttribut *>* atts,list<XSLTemplate *>* templates): atts(atts), templates(templates) {}

XSLCatalogue::~XSLCatalogue(){
	for(XSLAttribut * att : *atts){
		delete att;
	}
	delete atts;
	for(XSLTemplate * temp : *templates){
		delete temp;
	}
	delete templates;
}

void XSLCatalogue::afficherHTML(Document **docXML)
{
	for(list<XSLTemplate *>::iterator it = this->templates->begin(); it != this->templates->end(); it++){
		if ((**it).getPremierAttribut() == "/")
		{
			(**it).afficherHTML(docXML);
		}
	}
}

list<XSLTemplate *>* XSLCatalogue::getTemplates()
{
	return templates;
}
