#include "NonEmptyElement.h"
#include <iterator>

NonEmptyElement::NonEmptyElement(string nom, list<Attribut *>* atts, list<ContentItem *>* content) : 
									Element(nom, atts), content(content) {}

//ostream& operator << (ostream& os, const NonEmptyElement& NE){
void NonEmptyElement::print(ostream& os) const {
	os << "<" << this->nom;
	for(list<Attribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	os << ">\n";
	for(list<ContentItem *>::iterator it = this->content->begin(); it != this->content->end(); it++){
		os << **it;
	}
	os << "</" << this->nom << ">\n";
}

NonEmptyElement::~NonEmptyElement()
{
    list<Attribut *>::iterator it1 = atts->begin();
    list<Attribut *>::iterator it2 = atts->end();
    atts->erase(it1, it2);
    
    list<ContentItem *>::iterator ita = content->begin();
    list<ContentItem *>::iterator itb = content->end();
    content->erase(ita, itb);
}
