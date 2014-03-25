#include "Attribut.h"
#include "CDSect.h"
#include "Comment.h"
#include "ContentItem.h"
#include "DocTypeDecl.h"
#include "Document.h"
#include "Donnees.h"
#include "Element.h"
#include "EmptyElement.h"
#include "Misc.h"
#include "NonEmptyElement.h"
#include "PI.h"
#include "Prolog.h"

/*
#include <string>
#include <list> 
using namespace std;

class Attribut {
	public:
		Attribut(string nom,string valeur);
		~Attribut();
	protected:
		string nom;
		string valeur;
};

class ContentItem {
	public:
		ContentItem();
		~ContentItem();
};

class Element : public ContentItem {
	public:
		Element(string nom, list<Attribut *>* atts);
		~Element();
	protected:
		string nom;
		list<Attribut *>* atts;
};

class Misc : public ContentItem {
	public:
		Misc();
		~Misc();
};

class EmptyElement : public Element {
	public:
		EmptyElement(string nom, list<Attribut *>* atts);
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
		NonEmptyElement(string nom, list<Attribut *>* atts, list<ContentItem *>* content);
		~NonEmptyElement();
	protected:
		list<ContentItem *>* content;
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
		PI(string nom, list<Attribut *>* atts);
		~PI();
	protected:
		string nom;
		list<Attribut *>* atts;
};

class DocTypeDecl {
	public:
		DocTypeDecl(string nom, string idExterne);
		~DocTypeDecl();
	protected:
		string nom;
		string idExterne;
};

class Prolog {
	public:
		Prolog(PI * xmlDecl, DocTypeDecl * docTypeDecl, list<Misc *>* misc1, list<Misc *>* misc2);
		~Prolog();
	protected:
		PI * xmlDecl;
		DocTypeDecl * docTypeDecl;
		list<Misc *>* misc1;
		list<Misc *>* misc2;
};

class Document {
	public:
		Document(Prolog * prolog, Element * element, list<Misc *>* misc);
		~Document();
	protected:
		Prolog * prolog;
		Element * element;
		list<Misc *>* misc;
};

*/



	
	
