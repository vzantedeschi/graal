#include "XSLElementHTML.h"
#include <iterator>

XSLElementHTML::XSLElementHTML(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus), string contenu : XSLElement(type, atts, elementsInclus, contenu) {}

//ostream& operator << (ostream& os, const XSLEmptyElement& E){

void XSLEmptyElement::print(ostream& os) const  
{  
	os << "<" << this->type;
	//manque elementsInclus et contenu"
	for(list<XSLAttribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	//là il y a elementsInclus
	/*for(list<XSLAttribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}*/
	os << " />\n";
}
