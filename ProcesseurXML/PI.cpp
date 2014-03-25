#include "PI.h"
#include <iterator>

PI::PI(string nom, list<Attribut *>* atts) : Misc(), nom(nom), atts(atts) {}

ostream& operator << (ostream& os, const PI& P){
	os << "<?" << P.nom;
	for(list<Attribut *>::iterator it = P.atts->begin(); it != P.atts->end(); it++){
		os << " " << &it;
	}
	os << " ?>\n";
	return os;
}
