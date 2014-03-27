#include <string>
#include <list> 
using namespace std;

//class Element
Element::Element(string nom, list<Attribut*>* atts) : nom(nom), atts(atts){}
string Element::expr(){
    string res = "Erreur appel d'une mÃ©thode abstraite : Element";
    return res;
}

//class SimpleElement
SimpleElement::SimpleElement(string nom, list<Attribut*>* atts) : Element(nom, atts) {}
string SimpleElement::expr(){
    string res = "^<";
    res += nom + " ";
    for ( att in *atts){
        res += att.expr() +" ";
    }
    res += " />$";
    return res;
}

//class ComplexElement
ComplexElement::ComplexElement(string nom, list<Attribut*>* atts, ComplexType* complexType) : Element(nom, atts), complexType(complexType) {}
string ComplexElement::expr(){
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
Schema::Schema(list<Attribut*>* atts,list<Element*>* elements): atts(atts), elements(elements){}
string Schema::expr(){
    string res = "";
    // on ne sait pas gerer les arguments du schema
    for ( elem in *elements) {
        res += elem.expr();
    }
    return res;
}

//class ComplexType
ComplexType::ComplexType(list<Element*>* elements): elements(elements){}
string Choice::expr(){
    string res = "Erreur appel d'une mÃ©thode abstraite : ComplexType";
    return res;
}

//class Choice
Choice::Choice(list<Element*>* elements) : ComplexType( elements) {}
string Choice::expr(){
    string res = "^(";
    bool debut = true;
    for ( elem in *elements) {
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
Sequence::Sequence(list<Element*>* elements) : ComplexType(elements) {}
string Sequence::expr(){
    string res = "";
    for ( elem in *elements) {
        res += "^";
        res += elem.expr();
        res += "$";
    }
    return res;
}

//class Comment
Comment::Comment(string comment): comment(comment){}
string Comment::expr(){
    return "Erreur appel d'un commentaire";
}

//class Attribut
Attribut::Attribut(string nom,string valeur): nom(nom), valeur(valeur){}
string Attribut::expr(){
    string res ="";
    if (nom.compare("type") == 0 ){
        if (valeur.compare("xsd:string") == 0 ){
            res += "[^<]*";
        }
        else if (valeur.compare("xsd:date") == 0 ){
            res += "[0-9]{4}\-[0-9]{2}\-[0-9]{2}";
        }
        else {
            res += "Erreur " + nom + " attribut non pris en charge";
        }      
    }
    else{
        res += "Erreur " + nom + " attribut non pris en charge";
    return res;
}

//class Document
Document::Document(Prolog* prolog, Schema* schema, list<Comment*>* comments): prolog(prolog), schema(schema), comments(comments){}
string Document::expr(){
    string res = "";
    res += prolog.expr();
    res += schema.expr();
    return res;
}

//class Prolog
Prolog::Prolog(XSDDeclaration* xsdDecl, list<Comment*>* comments): xsdDecl(xsdDecl), comments(comments){}
string Prolog::expr(){
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
DSXDeclaration::XSDDeclaration(Attribut* att1, Attribut* att2): att1(att1), att2(att2){}
string DSXDeclaration::expr(){
    //la declaration du XSD n impacte pas le XML    
    string res = "";
    return res;
}

