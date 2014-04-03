#include "SimpleXSDElement.h"

//class SimpleXSDElement
SimpleXSDElement::SimpleXSDElement(string nom, list<XSDAttribut*>* atts) : XSDElement(nom, atts) {}

SimpleXSDElement::~SimpleXSDElement() {}

string SimpleXSDElement::expr(list<XSDElement*>* elems){
    string res = "((<";
    res += nom;
    res += ">";
    for (XSDAttribut* att : *atts){
        res += att->expr();
    }
    res += "</";
    res += nom;
    res += ">)|(<";
    res += nom;
    res += "/>))";
    return res;
}


XSDElement* SimpleXSDElement::reference(string n){

    if (this->nom.compare(n) ==0){
        return this;
    }
    return nullptr;
}
