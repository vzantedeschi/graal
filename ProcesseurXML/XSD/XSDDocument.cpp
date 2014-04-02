#include "XSDDocument.h"

//class XSDDocument
XSDDocument::XSDDocument(XSDProlog* prolog, Schema* schema, list<XSDComment*>* comments): prolog(prolog), schema(schema), comments(comments){}

XSDDocument::~XSDDocument(){
    delete prolog;
    delete schema;
    delete comments;
}

string XSDDocument::expr(){
    string res = "";
    res += prolog->expr();
    res += schema->expr();
    return res;
}
