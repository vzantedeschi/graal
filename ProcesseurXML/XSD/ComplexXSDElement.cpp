#include "ComplexXSDElement.h"

//class ComplexXSDElement
ComplexXSDElement::ComplexXSDElement(string nom, list<XSDAttribut*>* atts, ComplexType* complexType) : XSDElement(nom, atts), complexType(complexType) {}
string ComplexXSDElement::expr(list<XSDElement*>* elems){
    string res = "^?<";
    res += nom;
    res += ">$?";
    for (XSDAttribut* att : *atts){
        res += " " + att->expr();
    }    
    res += complexType->expr(elems);
    res += "^?</";
    res += nom;
    res += ">$?";
    return res;
}
