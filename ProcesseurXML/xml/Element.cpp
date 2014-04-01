#include "Element.h"

Element::Element(string nom, list<Attribut *>* atts) : ContentItem(), nom(nom), atts(atts) {}

Element::~Element()
{
    list<Attribut *>::iterator it1 = atts->begin();
    list<Attribut *>::iterator it2 = atts->end();
    atts->erase(it1, it2);
}



