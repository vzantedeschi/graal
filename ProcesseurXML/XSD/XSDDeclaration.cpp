#include "XSDDeclaration.h"

//class XSDDeclaration
XSDDeclaration::XSDDeclaration(XSDAttribut* att1, XSDAttribut* att2): att1(att1), att2(att2){}

XSDDeclaration::~XSDDeclaration(){
    delete att1;
    delete att2;
}

string XSDDeclaration::expr(){
    //la declaration du XSD n impacte pas le XML    
    string res = "";
    return res;
}
