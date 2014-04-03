#include "ComplexXSDElement.h"

//class ComplexXSDElement
ComplexXSDElement::ComplexXSDElement(string nom, list<XSDAttribut*>* atts, ComplexType* complexType) : XSDElement(nom, atts), complexType(complexType) {}

ComplexXSDElement::~ComplexXSDElement() {
    delete complexType;
}
string ComplexXSDElement::expr(list<XSDElement*>* elems){
    string res = "<";
    res += nom;
    res += ">";
    for (XSDAttribut* att : *atts){
        res += " " + att->expr();
    }    
    res += complexType->expr(elems);
    res += "</";
    res += nom;
    res += ">";
    return res;
}


ComplexType* ComplexXSDElement::getComplexType(){
    return complexType;
}

XSDElement* ComplexXSDElement::reference(string n){

    if (this->nom.compare(n) == 0){
        return this;
    }
    return complexType->reference(n);
}
