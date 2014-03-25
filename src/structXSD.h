#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
using namespace std;

class Element {
	public:
		Element(string nom, list<Attribut*>* atts);
		~Element();
        virtual string expr();
	protected:
        string nom;
		list<Attribut*>* atts;
};

class SimpleElement : public Element {
	public:
		SimpleElement(string nom, list<Attribut*>* atts);
		~SimpleElement();
        string expr();
};

class ComplexElement : public Element {
	public:
		ComplexElement(string nom, list<Attribut*>* atts, ComplexType* complexType);
		~ComplexElement();
        string expr();
	protected:
		ComplexType* complexType;
};

class Schema {
	public:
		Schema(list<Attribut*>* atts,list<Element*>* elements);
		~Schema();
        string expr();
	protected:
		list<Attribut*>* atts;
		list<Element*>* elements;
};

class ComplexType {
	public:
		ComplexType(list<Element*>* elements);
		~ComplexType();
		virtual string expr();
	protected:
		list<Element*>* elements;
};

class Choice : ComplexType {
	public:
		Choice(list<Element*>* elements);
		~Choice();
        string expr();
};

class Sequence : ComplexType {
	public:
		Sequence(list<Element*>* elements);
		~Sequence();
        string expr();
};

class Comment {
	public:
		Comment(string comment);
		~Comment();
        string expr();
	protected:
		string comment;
};

class Attribut {
	public:
		Attribut(string nom,string valeur);
		~Attribut();
        string expr();
	protected:
		string nom;
		string valeur;
};

class Document {
	public:
		Document(Prolog* prolog, Schema* schema, list<Comment*>* comments);
		~Document();
        string expr();
	protected:
		Prolog* prolog;
		Schema* schema;
		list<Comment*>* comments;
};

class Prolog {
	public:
		Prolog(XSDDeclaration* xsdDecl, list<Comment*>* comments);
		~Prolog();
        string expr();
	protected:
		XSDDeclaration* xsdDecl;
		list<Comment*>* comments;
};

class XSDDeclaration {
	public:
		XSDDeclaration(Attribut* att1, Attribut* att2);
		~XSDDeclaration();
        string expr();
	protected:
		Attribut* att1, att2;
};

#endif
