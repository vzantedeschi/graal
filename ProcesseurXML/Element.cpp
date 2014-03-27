#include "Element.h"

Element::Element(string nom, list<Attribut *>* atts) : ContentItem(), nom(nom), atts(atts) {}

/*
ostream& operator << (ostream& os, const Element& E){
	os << "<" << E.nom;
	os << &(D.element) << "\n";
	for(list<Misc *>::iterator it = D.misc->begin(); it != D.misc->end(); it++){
		os << &it << "\n";
	}
	return os;
}*/
