#include "NonEmptyElement.h"
#include <iterator>

NonEmptyElement::NonEmptyElement(string nom, list<Attribut *>* atts, list<ContentItem *>* content) : 
									Element(nom, atts), content(content) {}

//ostream& operator << (ostream& os, const NonEmptyElement& NE){
void NonEmptyElement::print(ostream& os) const {
	os << "\n<" << this->nom;
	for(list<Attribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	os << ">";
	for(list<ContentItem *>::iterator it = this->content->begin(); it != this->content->end(); it++){
		os << **it;
	}
	os << "</" << this->nom << ">";
}


