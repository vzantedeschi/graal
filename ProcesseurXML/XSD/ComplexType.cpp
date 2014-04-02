#include "ComplexType.h"

//class ComplexType
ComplexType::ComplexType(list<XSDElement*>* XSDElements): xSDElements(XSDElements){}

ComplexType::~ComplexType(){
    for (XSDElement* elem : *xSDElements)
    {
        delete elem;
    }
    delete xSDElements;
}

string ComplexType::expr(list<XSDElement*>* elems){
    string res = "Erreur appel d'une méthode abstraite : ComplexType";
    return res;
}

list<XSDElement*>* ComplexType::getxSDElements(){
    return xSDElements;
}
