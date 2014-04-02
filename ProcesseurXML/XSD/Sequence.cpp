#include "Sequence.h"

//class Sequence
Sequence::Sequence(list<XSDElement*>* XSDElements) : ComplexType(XSDElements) {}

Sequence::~Sequence(){}

string Sequence::expr(list<XSDElement*>* elems){
    string res = "";
    for (XSDElement* elem : *xSDElements) {
        res += elem->expr(elems);
    }
    return res;
}
