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
    list<Misc *>::iterator it1 = misc->begin();
    list<Misc *>::iterator it2 = misc->end();
    misc->erase(it1, it2);
}
