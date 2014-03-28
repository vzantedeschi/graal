#include "Schema.h"

//class Schema
Schema::Schema(list<XSDAttribut*>* atts,list<XSDElement*>* XSDElements): atts(atts), XSDElements(XSDElements){}
string Schema::expr(){
    string res = "";
    // on ne sait pas gerer les arguments du schema
    for (XSDElement* elem : *XSDElements) {
        res += elem->expr();
    }
    return res;
}
