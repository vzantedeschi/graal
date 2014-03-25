#include "structXSD.h"

//class Element
Element::Element(list<Attribut*> atts) : atts(atts) {}

//class SimpleElement
SimpleElement::SimpleElement(list<Attribut*> atts) : Element(atts) {}


//class ComplexElement
ComplexElement::ComplexElement(list<Attribut*> atts, list<Element*> elements) : 
									Element(atts), elements(elements) {}

//class Choice
Choice::Choice(list<Attribut*> atts,list<Element*> elements) : ComplexElement(atts,elements) {}

//class Sequence
Sequence::Sequence(list<Attribut*> atts,list<Element*> elements) : ComplexElement(atts,elements) {}

//class Schema
Schema::Schema(list<Attribut*> atts,list<Element*> elements) : atts(atts), elements(elements) {}

//class Comment
Comment::Comment(string comment) : comment(comment) {}

//class Attribut
Attribut::Attribut(string nom,string valeur) : nom(nom), valeur(valeur) {}

//class Document
Document::Document(Prolog* prolog, Schema* schema, list<Comment*> comments) : prolog(prolog), schema(schema), comments(comments) {}

//class Prolog
Prolog::Prolog(XSDDeclaration* xsdDecl, list<Comment*> comments) : xsdDecl(xsdDecl), comments(comments) {}

//class XSDDeclaration
XSDDeclaration::XSDDeclaration(Attribut* att1, Attribut* att2) : att1(att1), att2(att2) {}