#include <string>
#include <list> 
using namespace std;

//class XSDProlog
XSDProlog::XSDProlog(XSDDeclaration* xsdDecl, list<XSDComment*>* XSDComments): xsdDecl(xsdDecl), XSDComments(XSDComments){}
string XSDProlog::expr(){
    //la declaration du XSD n impacte pas le XML    
    /*
    string res = "^";
    res += *xsdDecl.expr();
    res += "$";
    */
    String res = "";
    return res;
}
