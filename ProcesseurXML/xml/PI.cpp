#include "PI.h"
#include <iterator>

PI::PI(string nom, list<Attribut *>* atts) : Misc(), nom(nom), atts(atts) {}

//ostream& operator << (ostream& os, const PI& P){
void PI::print(ostream& os) const{
	os << "<?" << this->nom;
	for(list<Attribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	os << "?>";
	//return os;
}

string PI::printElem(){
    return "";
}

PI::~PI()
{
	for(list<Attribut *>::iterator it = atts->begin(); it != atts->end(); it++){
			delete *it;
	}
	delete atts;
}
