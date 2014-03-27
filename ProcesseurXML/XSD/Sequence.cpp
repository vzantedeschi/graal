#include <string>
#include <list> 
using namespace std;

//class Sequence
Sequence::Sequence(list<XSDElement*>* XSDElements) : ComplexType(XSDElements) {}
string Sequence::expr(){
    string res = "";
    for ( elem in *XSDElements) {
        res += "^";
        res += elem.expr();
        res += "$";
    }
    return res;
}
