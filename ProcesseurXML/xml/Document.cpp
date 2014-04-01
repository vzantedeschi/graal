#include "Document.h"
#include <iterator>


Document::Document(Prolog * prolog, Element * element, list<Misc *>* misc) : prolog(prolog), element(element), misc(misc) {}

ostream& operator << (ostream& os, const Document& D){
	os << *(D.prolog);
	os << *(D.element);
	for(list<Misc *>::iterator it = D.misc->begin(); it != D.misc->end(); it++){
		os << **it;
	}
	return os;
}

Document::~Document()
{
    delete prolog;
    delete element;
    for(list<Misc *>::iterator it = misc->begin(); it != misc->end(); it++){
			delete *it;
	}
	delete misc;
}
