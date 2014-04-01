#include "Element.h"

Element::Element(string nom, list<Attribut *>* atts) : ContentItem(), nom(nom), atts(atts) {}

Element::~Element()
{
	for(list<Attribut *>::iterator it = atts->begin(); it != atts->end(); it++){
			delete *it;
	}
	delete atts;
}


