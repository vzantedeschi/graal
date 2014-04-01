#include "PI.h"
#include <iterator>

PI::PI(string nom, list<Attribut *>* atts) : Misc(), nom(nom), atts(atts) {}

//ostream& operator << (ostream& os, const PI& P){
void PI::print(ostream& os) const{
	os << "<?" << this->nom;
	for(list<Attribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	os << "?>\n";
	//return os;
}

PI::~PI()
{
    list<Attribut *>::iterator it1 = atts->begin();
    list<Attribut *>::iterator it2 = atts->end();
    atts->erase(it1, it2);
}
