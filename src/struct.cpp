/* PAS FINI !!! NI TESTE !!! EN TRAVAUX !!!
#include "struct.h"


//class Element
Element::Element(string nom, list<Attribut> atts) : ContentItem(), nom(nom), atts(atts) {}


//class EmptyElement
EmptyElement::EmptyElement() : Element() {}


//class NonEmptyElement
NonEmptyElement::NonEmptyElement(string nom, list<Attribut> atts, list<ContentItem > content) : Element(), nom(nom), atts(atts), content(content)
		~NonEmptyElement();
	protected:
		list<ContentItem> content;
};

//class CDSect
CDSect::CDSect(string cdata) : ContentItem, cdata(cdata) {}

class Comment : public Misc {
	public:
		Comment(string comment);
		~Comment();
	protected:
		string comment;
};

class PI : public Misc {
	public:
		PI(list<Attribut> atts);
		~PI();
	protected:
		list<Attribut> atts;
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
		Document(Prolog prolog, Element element, list<Misc> misc);
		~Document();
	protected:
		Prolog prolog;
		Element element;
		list<Misc> misc;
};

class Prolog {
	public:
		Prolog(XMLDeclaration xmlDecl, DocTypeDecl docTypeDecl, list<Misc> misc1, list<Misc> misc2);
		~Prolog()
	protected:
		XMLDeclaration xmlDecl;
		DocTypeDecl docTypeDecl;
		list<Misc> misc1;
		list<Misc> misc2;
};

class DocTypeDecl {
	public:
		DocTypeDecl(string nom, string idExterne);
		~DocTypeDecl();
	protected:
		string nom;
		string idExterne;
};

class XMLDeclaration {
	public:
		XMLDeclaration(string versionInfo, Attribut att1, Attribut att2);
		~XMLDeclaration();
	protected:
		string versionInfo;
		Attribut att1, att2;
};

*/	
	
	
