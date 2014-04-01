#include "XSLNonEmptyElement.h"
#include <iterator>

XSLNonEmptyElement::XSLNonEmptyElement(string nom, list<XSLAttribut *>* atts, list<XSLContentItem *>* content) : XSLElement(nom, atts), content(content) {}

//ostream& operator << (ostream& os, const XSLNonEmptyElement& NE){
void XSLNonEmptyElement::print(ostream& os) const {
	os << "\n<" << this->nom;
	for(list<XSLAttribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	os << ">";
	for(list<XSLContentItem *>::iterator it = this->content->begin(); it != this->content->end(); it++){
		os << **it;
	}
	os << "</" << this->nom << ">";
}


