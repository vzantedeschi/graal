#include "ComplexType.h"

//class ComplexType
ComplexType::ComplexType(list<XSDElement*>* XSDElements): xSDElements(XSDElements){}

string ComplexType::expr(list<XSDElement*>* elems){
    string res = "Erreur appel d'une méthode abstraite : ComplexType";
    return res;
}

list<XSDElement*>* ComplexType::getxSDElements(){
    return xSDElements;
}
