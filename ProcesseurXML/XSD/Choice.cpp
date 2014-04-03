#include "Choice.h"

//class Choice
Choice::Choice(list<XSDElement*>* XSDElements) : ComplexType( XSDElements) {}

Choice::~Choice() {}

string Choice::expr(list<XSDElement*>* elems){
    string res = "(";
    bool debut = true;
    for (XSDElement* elem : *xSDElements) {
        if (debut) {
            debut = false;
        }
        else {
            res += "|";
        }
        res += "(";
        res += elem->expr(elems);
        res += ")";
    }
    res += ")";
    return res;
}

XSDElement* Choice::reference(string n){
    for (XSDElement* elem : *xSDElements) {
        XSDElement* e = elem->reference(n);
        if(e != nullptr){
            return e;
        }
    }
    return nullptr;
}

