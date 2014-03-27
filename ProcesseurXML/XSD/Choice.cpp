#include <string>
#include <list> 
using namespace std;

//class Choice
Choice::Choice(list<XSDElement*>* XSDElements) : ComplexType( XSDElements) {}
string Choice::expr(){
    string res = "^(";
    bool debut = true;
    for ( elem in *XSDElements) {
        if (debut) {
            debut = false
        }
        else {
            res += "|";
        }
        res += "("
        res += elem.expr();
        res += ")"
    }
    res = ")$";
    return res;
}

