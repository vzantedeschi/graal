#include "Choice.h"

//class Choice
Choice::Choice(list<XSDElement*>* XSDElements) : ComplexType( XSDElements) {}

string Choice::expr(){
    string res = "^(";
    bool debut = true;
    for (XSDElement* elem : *XSDElements) {
        if (debut) {
            debut = false;
        }
        else {
            res += "|";
        }
        res += "(";
        res += elem->expr();
        res += ")";
    }
    res = ")$";
    return res;
}

