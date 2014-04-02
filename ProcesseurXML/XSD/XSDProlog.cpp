#include "XSDProlog.h"

//class XSDProlog
XSDProlog::XSDProlog(XSDDeclaration* xsdDecl, list<XSDComment*>* XSDComments): xsdDecl(xsdDecl), xSDComments(XSDComments){}

XSDProlog::~XSDProlog(){
    delete xsdDecl;
    delete xSDComments;
}

string XSDProlog::expr(){
    string res ="";
    //la declaration du XSD n impacte pas le XML    
    /*
    string res = xsdDecl->expr();
    string res += "((^?$?)|(^?<!DOCTYPE [^>]$?))";
    */
    return res;
}
