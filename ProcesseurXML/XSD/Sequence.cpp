#include "Sequence.h"

//class Sequence
Sequence::Sequence(list<XSDElement*>* XSDElements) : ComplexType(XSDElements) {}
string Sequence::expr(){
    string res = "";
    for (XSDElement* elem : *XSDElements) {
        res += "^";
        res += elem->expr();
        res += "$";
    }
    return res;
}
