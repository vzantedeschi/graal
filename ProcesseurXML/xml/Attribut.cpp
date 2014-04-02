#include "Attribut.h"
#include "../re2/re2/re2.h"

Attribut::Attribut(string nom,string valeur) : nom(nom), valeur(valeur) {}

ostream& operator << (ostream& os, const Attribut& A){
    os << A.nom << "=" << "\"" << A.valeur << "\"";
    return os;
}

string Attribut::printElem(){
    string res = "";
    res += nom + "=" + "\"" + valeur + "\"";
    return res;
}

bool Attribut::isTheOne(){
    // retourne true si c est la balise qui appelle le xsd (attribut commencant par xmlns
    return RE2::FullMatch(nom, "xmlns.*");
}

Attribut::~Attribut(){
}
