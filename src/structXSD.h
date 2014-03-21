#include <string>
#include <list> 
using namespace std;

class Element {
	public:
		Element(list<Attribut> atts);
		~Element();
	protected:
		string nom;
		list<Attribut> atts;
};

class SimpleElement : public Element {
	public:
		SimpleElement(list<Attribut> atts);
		~SimpleElement();
	protected:
		list<Attribut> atts;
};

class ComplexElement : public Element {
	public:
		ComplexElement(list<Attribut> atts, list<Element> elements);
		~ComplexElement();
	protected:
		list<Element> elements;
};

class Schema {
	public:
		Schema(list<Attribut> atts,list<Element> elements);
		~Schema();
	protected:
		list<Attribut> atts;
		list<Element> elements;
};

class Choice {
	public:
		Schema(list<Element> elements);
		~Schema();
	protected:
		list<Element> elements;
};

class Sequence {
	public:
		Sequence(list<Element> elements);
		~Sequence();
	protected:
		list<Element> elements;
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
		Document(Prolog prolog, Element element, list<Comment> comments);
		~Document();
	protected:
		Prolog prolog;
		Element element;
		list<Comment> comments;
};

class Prolog {
	public:
		Prolog(XSDDeclaration xsdDecl, list<Comment> comments);
		~Prolog();
	protected:
		XSDDeclaration xsdDecl;
		list<Comment> comments;
};

class XSDDeclaration {
	public:
		XSDDeclaration(Attribut att1, Attribut att2);
		~XSDDeclaration();
	protected:
		Attribut att1, att2;
};