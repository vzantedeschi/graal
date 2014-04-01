#include "struct.h"

//class ContentItem
ContentItem::ContentItem(){}
ContentItem::~ContentItem(){}

//class Element
Element::Element(string nom, list<Attribut *>* atts) : ContentItem(), nom(nom), atts(atts) {}

//class EmptyElement
EmptyElement::EmptyElement(string nom, list<Attribut *>* atts) : Element(nom, atts) {}


//class NonEmptyElement
NonEmptyElement::NonEmptyElement(string nom, list<Attribut *>* atts, list<ContentItem *>* content) : 
									Element(nom, atts), content(content) {}

//class Misc : public ContentItem {
Misc::Misc() : ContentItem() {}
Misc::~Misc(){}

//class Donnees
Donnees::Donnees(string donnees) : ContentItem(), donnees(donnees) {}

//class CDSect
CDSect::CDSect(string cdata) : ContentItem(), cdata(cdata) {}

//class Comment
Comment::Comment(string comment) : Misc(), comment(comment) {}

//class PI :
PI::PI(string nom, list<Attribut *>* atts) : Misc(), nom(nom), atts(atts) {}

//class Attribut
Attribut::Attribut(string nom,string valeur) : nom(nom), valeur(valeur) {}

//class Document
Document::Document(Prolog * prolog, Element  * element, list<Misc *>* misc) : prolog(prolog), element(element), misc(misc) {}

//class Prolog
Prolog::Prolog(PI * xmlDecl, DocTypeDecl * docTypeDecl, list<Misc *>* misc1, list<Misc *>* misc2) : 
									xmlDecl(xmlDecl), docTypeDecl(docTypeDecl), misc1(misc1), misc2(misc2) {}

//class DocTypeDecl
DocTypeDecl::DocTypeDecl(string nom, string idExterne) : nom(nom), idExterne(idExterne) {}


	
	
	
