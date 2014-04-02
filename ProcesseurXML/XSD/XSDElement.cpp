#include "XSDElement.h"

//class XSDElement
XSDElement::XSDElement(string nom, list<XSDAttribut*>* atts) : nom(nom), atts(atts){}

XSDElement::~XSDElement(){
    for ( XSDAttribut* att : *atts)
    {
        delete att;
    }
    delete atts;
}

string XSDElement::expr(list<XSDElement*>* elems){
    string res = "Erreur appel d'une méthode abstraite : XSDElement";
    return res;
}

string XSDElement::getNom(){
    return nom;
}
