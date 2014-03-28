#include "SimpleXSDElement.h"

//class SimpleXSDElement
SimpleXSDElement::SimpleXSDElement(string nom, list<XSDAttribut*>* atts) : XSDElement(nom, atts) {}
string SimpleXSDElement::expr(){
    string res = "^<";
    res += nom + " ";
    for (XSDAttribut* att : *atts){
        res += att->expr() +" ";
    }
    res += " />$";
    return res;
}
