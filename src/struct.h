#include <string>
#include <list> 
using namespace std;

class ContentItem {
	public:
		ContentItem();
		~ContentItem();
};

class Element : public ContentItem {
	public:
		Element(string nom, list<Attribut> atts);
		~Element();
	protected:
		string nom;
		list<Attribut> atts;
};

class Misc : public ContentItem {
	public:
		Misc();
		~Misc();
};

class EmptyElement : public Element {
	public:
		EmptyElement();
		~EmptyElement();
};

class Donnees : public ContentItem {
	public:
		Donnees(string donnees);
		~Donnees();
	protected:
		string donnees;
};

class CDSect : public ContentItem {
	public:
		CDSect(string cdata);
		~CDSect();
	protected:
		string cdata;
};

class NonEmptyElement : public Element {
	public:
		NonEmptyElement(string nom, list<Attribut> atts, list<ContentItem > content);
		~NonEmptyElement();
	protected:
		list<ContentItem> content;
};

class Comment : public Misc {
	public:
		Comment(string comment);
		~Comment();
	protected:
		string comment;
};

class PI : public Misc {
	public:
		PI(string nom, list<Attribut> atts);
		~PI();
	protected:
		string nom;
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
		~Prolog();
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

/* Traité comme PI
class XMLDeclaration {
	public:
		XMLDeclaration(string versionInfo, Attribut att1, Attribut att2);
		~XMLDeclaration();
	protected:
		string versionInfo;
		Attribut att1, att2;
};*/

	
	
	
