#include "EmptyElement.h"
#include <iterator>

EmptyElement::EmptyElement(string nom, list<Attribut *>* atts) : Element(nom, atts) {}

//ostream& operator << (ostream& os, const EmptyElement& E){

void EmptyElement::print(ostream& os) const  
{  
	os << "<" << this->nom;
	for(list<Attribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	os << " />\n";
}

EmptyElement::~EmptyElement()
{
}

