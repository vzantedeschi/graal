#include <string>
#include <list> 
using namespace std;

//class XSDDocument
XSDDocument::XSDDocument(XSDProlog* XSDProlog, Schema* schema, list<XSDComment*>* XSDComments): XSDProlog(XSDProlog), schema(schema), XSDComments(XSDComments){}
string XSDDocument::expr(){
    string res = "";
    res += XSDProlog.expr();
    res += schema.expr();
    return res;
}
