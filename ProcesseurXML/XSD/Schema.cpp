#include "Schema.h"

//class Schema
Schema::Schema(list<XSDAttribut*>* atts,list<XSDElement*>* xSDElements): atts(atts), xSDElements(xSDElements){}

Schema::~Schema(){
    for ( XSDAttribut* att : *atts){
        delete att;
    }
    delete atts;
    for (XSDElement* elem : *xSDElements){
        delete elem;
    }
    delete xSDElements;
}


string Schema::expr(){
    string res = "(";
    bool debut = true;
    // on ne sait pas gerer les arguments du schema
    for (XSDElement* elem : *xSDElements)
    {
        if (debut){
            debut = false;
        }
        else
        {
            res += "|";
        }
        res += "^?(" + elem->expr(xSDElements) + ")$?\n" ;
    }
    res += ")*";
    return res;
}
