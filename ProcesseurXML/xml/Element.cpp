#include "Element.h"

Element::Element(string nom, list<Attribut *>* atts) : ContentItem(), nom(nom), atts(atts) {}

Element::~Element()
{
	for(list<Attribut *>::iterator it = atts->begin(); it != atts->end(); it++){
			delete *it;
	}
	delete atts;
}

string Element::getNom()
{
	return nom;
}

list<ContentItem *>* Element::getContent()
{
	cout << "get content element" << endl;
	return NULL;
}

void Element::matchPath(list<ContentItem *>* liste,string path)
{
	cout << "get content element" << endl;
}

void Element::printDonnees()
{
}
