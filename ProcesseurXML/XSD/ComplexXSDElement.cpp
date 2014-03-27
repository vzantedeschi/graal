#include <string>
#include <list> 
using namespace std;

//class ComplexXSDElement
ComplexXSDElement::ComplexXSDElement(string nom, list<XSDAttribut*>* atts, ComplexType* complexType) : XSDElement(nom, atts), complexType(complexType) {}
string ComplexXSDElement::expr(){
    string res = "^<";
    res += nom;
    for ( att in *atts){
        res += " " + att.expr();
    }
    res += ">";
    res += *complexType.expr();
    res += "</";
    res += nom;
    res += ">$";
    return res;
}
