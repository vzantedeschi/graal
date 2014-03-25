#include <string>
#include <list> 
using namespace std;

//class Element
Element::Element(string nom, list<Attribut*>* atts){}

//class SimpleElement
SimpleElement::SimpleElement(string nom, list<Attribut*>* atts) : Element(nom, atts) {}

//class ComplexElement
ComplexElement::ComplexElement(string nom, list<Attribut*>* atts, list<Element*>* elements) : Element(nom, atts) {}

//class Schema
Schema::Schema(list<Attribut*>* atts,list<Element*>* elements){}

//class Choice
Choice::Choice(string nom, list<Attribut*>* atts, list<Element*>* elements) : ComplexElement(nom, atts, elements) {}

//class Sequence
Sequence::Sequence(string nom, list<Attribut*>* atts, list<Element*>* elements) : ComplexElement(nom, atts, elements) {}

//class Comment
Comment::Comment(string comment){}

//class Attribut
Attribut::Attribut(string nom,string valeur){}

//class Document
Document::Document(Prolog* prolog, Element* element, list<Comment*>* comments){}

//class Prolog
Prolog::Prolog(XSDDeclaration* xsdDecl, list<Comment*>* comments){}

//class XSDDeclaration
DSXDeclaration::XSDDeclaration(Attribut* att1, Attribut* att2){}

