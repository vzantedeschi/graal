#include <string>
#include <list> 
using namespace std;

//class Element
Element::Element(string nom, list<Attribut*>* atts){}
string Element::expr(){
    string res = "";
    return res;
}

//class SimpleElement
SimpleElement::SimpleElement(string nom, list<Attribut*>* atts) : Element(nom, atts) {}
string SimpleElement::expr(){
    string res = "";
    return res;
}

//class ComplexElement
ComplexElement::ComplexElement(string nom, list<Attribut*>* atts, list<Element*>* elements) : Element(nom, atts) {}
string ComplexElement::expr(){
    string res = "";
    return res;
}

//class Schema
Schema::Schema(list<Attribut*>* atts,list<Element*>* elements){}
string Schema::expr(){
    string res = "";
    return res;
}

//class Choice
Choice::Choice(string nom, list<Attribut*>* atts, list<Element*>* elements) : ComplexElement(nom, atts, elements) {}
string Choice::expr(){
    string res = "";
    return res;
}

//class Sequence
Sequence::Sequence(string nom, list<Attribut*>* atts, list<Element*>* elements) : ComplexElement(nom, atts, elements) {}
string Sequence::expr(){
    string res = "";
    return res;
}

//class Comment
Comment::Comment(string comment){}
string Comment::expr(){
    return "";
}

//class Attribut
Attribut::Attribut(string nom,string valeur){}
string Attribut::expr(){
    string res = "";
    return res;
}

//class Document
Document::Document(Prolog* prolog, Element* element, list<Comment*>* comments){}
string Document::expr(){
    string res = "";
    return res;
}

//class Prolog
Prolog::Prolog(XSDDeclaration* xsdDecl, list<Comment*>* comments){}
string Prolog::expr(){
    string res = "";
    return res;
}

//class XSDDeclaration
DSXDeclaration::XSDDeclaration(Attribut* att1, Attribut* att2){}
string DSXDeclaration::expr(){
    string res = "";
    return res;
}

