#include "Prolog.h"
#include <iterator>

Prolog::Prolog(PI * xmlDecl, DocTypeDecl * docTypeDecl, list<Misc *>* misc1, list<Misc *>* misc2) : 
									xmlDecl(xmlDecl), docTypeDecl(docTypeDecl), misc1(misc1), misc2(misc2) {}

ostream& operator << (ostream& os, const Prolog& P){
	//<?xml version="1.0" encoding="UTF-8"?>
	os << &(P.xmlDecl) << "\n";
	os << &(P.docTypeDecl) << "\n";
	for(list<Misc *>::iterator it = P.misc1->begin(); it != P.misc1->end(); it++){
			os << &it << "\n";
		}
	for(list<Misc *>::iterator it = P.misc2->begin(); it != P.misc2->end(); it++){
			os << &it << "\n";
		}

	return os;
}
