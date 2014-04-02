#include "Prolog.h"
#include <iterator>

Prolog::Prolog(DocTypeDecl * docTypeDecl, list<Misc *>* misc1, list<Misc *>* misc2) : 
									docTypeDecl(docTypeDecl), misc1(misc1), misc2(misc2) {}

ostream& operator << (ostream& os, const Prolog& P){

	if(P.misc1 != NULL){
		for(list<Misc *>::iterator it = P.misc1->begin(); it != P.misc1->end(); it++){
				cout << **it << "\n";
		}
	}

	if(P.docTypeDecl != NULL){
		cout << *(P.docTypeDecl) << "\n";
	}

	if(P.misc2 != NULL){
		for(list<Misc *>::iterator it = P.misc2->begin(); it != P.misc2->end(); it++){
				cout << **it << "\n";
		}
	}
	return os;
}

Prolog::~Prolog()
{
	if(docTypeDecl != NULL){
		delete docTypeDecl;
	}
	if(misc1 != NULL){
    	for(list<Misc *>::iterator it = misc1->begin(); it != misc1->end(); it++){
			delete *it;
		}
		delete misc1;
    }
    
    if(misc2 != NULL){
    	for(list<Misc *>::iterator it = misc2->begin(); it != misc2->end(); it++){
			delete *it;
		}
		delete misc2;
    }
}
