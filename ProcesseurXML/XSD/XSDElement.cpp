#include "XSDElement.h"

//class XSDElement
XSDElement::XSDElement(string nom, list<XSDAttribut*>* atts) : nom(nom), atts(atts){}

string XSDElement::expr(){
    string res = "Erreur appel d'une méthode abstraite : XSDElement";
    return res;
}
