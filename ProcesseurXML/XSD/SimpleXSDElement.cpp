#include <string>
#include <list> 
using namespace std;

//class SimpleXSDElement
SimpleXSDElement::SimpleXSDElement(string nom, list<XSDAttribut*>* atts) : XSDElement(nom, atts) {}
string SimpleXSDElement::expr(){
    string res = "^<";
    res += nom + " ";
    for ( att in *atts){
        res += att.expr() +" ";
    }
    res += " />$";
    return res;
}
