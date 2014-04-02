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
	for(list<ContentItem *>::iterator it = content->begin(); it != content->end(); it++){
			delete *it;
	}
	delete content;
}

list<ContentItem *>* NonEmptyElement::getContent()
{
	return content;
}

void NonEmptyElement::printDonnees()
{
	for(list<ContentItem *>::iterator it = this->content->begin(); it != this->content->end(); it++){
		(*it)->printDonnees();
	}
}
