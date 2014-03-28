#include "ComplexType.h"

//class ComplexType
ComplexType::ComplexType(list<XSDElement*>* XSDElements): XSDElements(XSDElements){}

string ComplexType::expr(){
    string res = "Erreur appel d'une méthode abstraite : ComplexType";
    return res;
}
