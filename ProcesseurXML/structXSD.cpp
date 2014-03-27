#include <string>
#include <list> 
using namespace std;

//class XSDElement
XSDElement::XSDElement(string nom, list<XSDAttribut*>* atts) : nom(nom), atts(atts){}
string XSDElement::expr(){
    string res = "Erreur appel d'une méthode abstraite : XSDElement";
    return res;
}

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

//class Schema
Schema::Schema(list<XSDAttribut*>* atts,list<XSDElement*>* XSDElements): atts(atts), XSDElements(XSDElements){}
string Schema::expr(){
    string res = "";
    // on ne sait pas gerer les arguments du schema
    for ( elem in *XSDElements) {
        res += elem.expr();
    }
    return res;
}

//class ComplexType
ComplexType::ComplexType(list<XSDElement*>* XSDElements): XSDElements(XSDElements){}
string Choice::expr(){
    string res = "Erreur appel d'une mÃ©thode abstraite : ComplexType";
    return res;
}

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

//class XSDComment
XSDComment::XSDComment(string XSDComment): XSDComment(XSDComment){}
string XSDComment::expr(){
    return "Erreur appel d'un XSDCommentaire";
}

//class XSDAttribut
XSDAttribut::XSDAttribut(string nom,string valeur): nom(nom), valeur(valeur){}
string XSDAttribut::expr(){
    string res ="";
    if (nom.compare("type") == 0 ){
        if (valeur.compare("xsd:string") == 0 ){
            res += "[^<]*";
        }
        else if (valeur.compare("xsd:date") == 0 ){
            res += "[0-9]{4}\-[0-9]{2}\-[0-9]{2}";
        }
        else {
            res += "Erreur " + nom + " XSDAttribut non pris en charge";
        }      
    }
    else{
        res += "Erreur " + nom + " XSDAttribut non pris en charge";
    return res;
}

//class XSDDocument
XSDDocument::XSDDocument(XSDProlog* XSDProlog, Schema* schema, list<XSDComment*>* XSDComments): XSDProlog(XSDProlog), schema(schema), XSDComments(XSDComments){}
string XSDDocument::expr(){
    string res = "";
    res += XSDProlog.expr();
    res += schema.expr();
    return res;
}

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

//class XSDDeclaration
DSXDeclaration::XSDDeclaration(XSDAttribut* att1, XSDAttribut* att2): att1(att1), att2(att2){}
string DSXDeclaration::expr(){
    //la declaration du XSD n impacte pas le XML    
    string res = "";
    return res;
}

