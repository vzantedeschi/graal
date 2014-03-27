#include <string>
#include <list> 
using namespace std;

//class XSDDeclaration
DSXDeclaration::XSDDeclaration(XSDAttribut* att1, XSDAttribut* att2): att1(att1), att2(att2){}
string DSXDeclaration::expr(){
    //la declaration du XSD n impacte pas le XML    
    string res = "";
    return res;
}
