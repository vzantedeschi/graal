#include "EmptyElement.h"
#include <iterator>
#include <sstream>

EmptyElement::EmptyElement(string nom, list<Attribut *>* atts) : Element(nom, atts) {}

void EmptyElement::print(ostream& os) const  
{  
	os << "<" << this->nom;
	for(list<Attribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	os << " />\n";
}

string EmptyElement::printElem()
{
    string res = "";
    res += "<" + nom;
    for(list<Attribut *>::iterator it = atts->begin(); it != atts->end(); it++){
        res += (*it)->printElem();
    }
    res += " />";
    return res;
}

EmptyElement::~EmptyElement()
{
}

void EmptyElement::printDonnees(){
}

void EmptyElement::matchPath(list<ContentItem*>* liste,string path){
}

