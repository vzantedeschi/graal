#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
using namespace std;

class Element {
	public:
		Element(list<Attribut*> atts);
		~Element();
	protected:
		list<Attribut*> atts;
};

class SimpleElement : public Element {
	public:
		SimpleElement(list<Attribut*> atts);
		~SimpleElement();
};

class ComplexElement : public Element {
	public:
		ComplexElement(list<Attribut*> atts, list<Element*> elements);
		~ComplexElement();
	protected:
		list<Element*> elements;
};

class Schema {
	public:
		Schema(list<Attribut*> atts,list<Element*> elements);
		~Schema();
	protected:
		list<Attribut*> atts;
		list<Element*> elements;
};

class Choice : public ComplexElement{
	public:
		Choice(list<Attribut*> atts,list<Element*> elements);
		~Choice();
};

class Sequence : public ComplexElement{
	public:
		Sequence(list<Attribut*> atts,list<Element*> elements);
		~Sequence();
};

class Comment {
	public:
		Comment(string comment);
		~Comment();
	protected:
		string comment;
};

class Attribut {
	public:
		Attribut(string nom,string valeur);
		~Attribut();
	protected:
		string nom;
		string valeur;
};

class Document {
	public:
		Document(Prolog* prolog, Schema* schema, list<Comment*> comments);
		~Document();
	protected:
		Prolog* prolog;
		Schema* schema;
		list<Comment*> comments;
};

class Prolog {
	public:
		Prolog(XSDDeclaration* xsdDecl, list<Comment*> comments);
		~Prolog();
	protected:
		XSDDeclaration* xsdDecl;
		list<Comment*> comments;
};

class XSDDeclaration {
	public:
		XSDDeclaration(Attribut* att1, Attribut* att2);
		~XSDDeclaration();
	protected:
		Attribut* att1, att2;
};

#endif