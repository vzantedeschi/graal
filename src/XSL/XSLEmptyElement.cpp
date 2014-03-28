#include "XSLEmptyElement.h"
#include <iterator>

XSLEmptyElement::XSLEmptyElement(string nom, list<XSLAttribut *>* atts) : XSLElement(nom, atts) {}

//ostream& operator << (ostream& os, const XSLEmptyElement& E){

void XSLEmptyElement::print(ostream& os) const  
{  
	os << "<" << this->nom;
	for(list<XSLAttribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	os << " />\n";
}
