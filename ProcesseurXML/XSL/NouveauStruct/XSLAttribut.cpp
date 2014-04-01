#include "XSLAttribut.h"

XSLAttribut::XSLAttribut(string nom,string valeur) : nom(nom), valeur(valeur) {}

ostream& operator << (ostream& os, const XSLAttribut& A){
	os << A.nom << "=" << "\"" << A.valeur << "\"";
	return os;
}
