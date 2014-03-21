#include "struct.h"

//class Element
Element::Element(string nom, list<Attribut> atts) : ContentItem(), nom(nom), atts(atts) {}


//class EmptyElement
EmptyElement::EmptyElement() : Element() {}


//class NonEmptyElement
NonEmptyElement::NonEmptyElement(string nom, list<Attribut> atts, list<ContentItem > content) : 
									Element(), nom(nom), atts(atts), content(content) {}

//class Donnees
Donnees::Donnees(string donnees) : ContentItem(), donnees(donnees) {}

//class CDSect
CDSect::CDSect(string cdata) : ContentItem(), cdata(cdata) {}

//class Comment
Comment::Comment(string comment) : Misc(), comment(comment) {}

//class PI :
PI::PI(string nom, list<Attribut> atts) : Misc(), nom(nom), atts(atts) {}

//class Attribut
Attribut::Attribut(string nom,string valeur) : nom(nom), valeur(valeur) {}

//class Document
Document::Document(Prolog prolog, Element element, list<Misc> misc) : prolog(prolog), element(element), misc(misc) {]

//class Prolog
Prolog::Prolog(XMLDeclaration xmlDecl, DocTypeDecl docTypeDecl, list<Misc> misc1, list<Misc> misc2) : 
									xmlDecl(xmlDecl), docTypeDecl(docTypeDecl), mics1(misc1), misc2(misc2) {}

//class DocTypeDecl
DocTypeDecl::DocTypeDecl(string nom, string idExterne) : nom(nom), idExterne(idExterne) {}

//class XMLDeclaration
XMLDeclaration::XMLDeclaration(string versionInfo, Attribut att1, Attribut att2) : 
									versionInfo(versionInfo), att1(att1), att2(att2) {}
	
	
	
