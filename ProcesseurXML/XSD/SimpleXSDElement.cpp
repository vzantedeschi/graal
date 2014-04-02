#include "SimpleXSDElement.h"

//class SimpleXSDElement
SimpleXSDElement::SimpleXSDElement(string nom, list<XSDAttribut*>* atts) : XSDElement(nom, atts) {}

SimpleXSDElement::~SimpleXSDElement() {}

string SimpleXSDElement::expr(list<XSDElement*>* elems){
    string res = "^?((<";
    res += nom + " ?";
    res += ">$?\n^?";
    for (XSDAttribut* att : *atts){
        res += att->expr() +" ";
    }
    res += "^?<";
    res += nom + " ?";
    res += "/>$?\n)|(<";
    res += nom + " ?";
    res += "/>))$?\n";
    return res;
}
