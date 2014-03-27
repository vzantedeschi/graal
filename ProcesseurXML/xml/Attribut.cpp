#include "Attribut.h"

Attribut::Attribut(string nom,string valeur) : nom(nom), valeur(valeur) {}

ostream& operator << (ostream& os, const Attribut& A){
	os << A.nom << "=" << "\"" << A.valeur << "\"";
	return os;
}
