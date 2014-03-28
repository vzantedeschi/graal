#include "XSDDeclaration.h"

//class XSDDeclaration
XSDDeclaration::XSDDeclaration(const XSDAttribut& att1, const XSDAttribut& att2){
	this->att1 = att1;
	this->att2 = att2;
}

string XSDDeclaration::expr(){
    //la declaration du XSD n impacte pas le XML    
    string res = "";
    return res;
}
