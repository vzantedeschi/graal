#include "Sequence.h"

//class Sequence
Sequence::Sequence(list<XSDElement*>* XSDElements) : ComplexType(XSDElements) {}
string Sequence::expr(list<XSDElement*>* elems){
    string res = "";
    for (XSDElement* elem : *XSDElements) {
        res += "^?";
        res += elem->expr(elems);
        res += "$?";
    }
    return res;
}
