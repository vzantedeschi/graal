#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
using namespace std;

class XSDElement {
	public:
		XSDElement(string nom, list<XSDAttribut*>* atts);
		~XSDElement();
        virtual string expr();
	protected:
        string nom;
		list<XSDAttribut*>* atts;
};

class SimpleXSDElement : public XSDElement {
	public:
		SimpleXSDElement(string nom, list<XSDAttribut*>* atts);
		~SimpleXSDElement();
        string expr();
};

class ComplexXSDElement : public XSDElement {
	public:
		ComplexXSDElement(string nom, list<XSDAttribut*>* atts, ComplexType* complexType);
		~ComplexXSDElement();
        string expr();
	protected:
		ComplexType* complexType;
};

class Schema {
	public:
		Schema(list<XSDAttribut*>* atts,list<XSDElement*>* XSDElements);
		~Schema();
        string expr();
	protected:
		list<XSDAttribut*>* atts;
		list<XSDElement*>* XSDElements;
};

class ComplexType {
	public:
		ComplexType(list<XSDElement*>* XSDElements);
		~ComplexType();
		virtual string expr();
	protected:
		list<XSDElement*>* XSDElements;
};

class Choice : ComplexType {
	public:
		Choice(list<XSDElement*>* XSDElements);
		~Choice();
        string expr();
};

class Sequence : ComplexType {
	public:
		Sequence(list<XSDElement*>* XSDElements);
		~Sequence();
        string expr();
};

class XSDComment {
	public:
		XSDComment(string XSDComment);
		~XSDComment();
        string expr();
	protected:
		string XSDComment;
};

class XSDAttribut {
	public:
		XSDAttribut(string nom,string valeur);
		~XSDAttribut();Doc
        string expr();
	protected:
		string nom;
		string valeur;
};

class XSDDocument {
	public:
		XSDDocument(XSDProlog* XSDProlog, Schema* schema, list<XSDComment*>* XSDComments);
		~XSDDocument();
        string expr();
	protected:
		XSDProlog* XSDProlog;
		Schema* schema;
		list<XSDComment*>* XSDComments;
};

class XSDProlog {
	public:
		XSDProlog(XSDDeclaration* xsdDecl, list<XSDComment*>* XSDComments);
		~XSDProlog();
        string expr();
	protected:
		XSDDeclaration* xsdDecl;
		list<XSDComment*>* XSDComments;
};

class XSDDeclaration {
	public:
		XSDDeclaration(XSDAttribut* att1, XSDAttribut* att2);
		~XSDDeclaration();
        string expr();
	protected:
		XSDAttribut* att1, att2;
};

#endif
