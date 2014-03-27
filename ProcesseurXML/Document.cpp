#include "Document.h"
#include <iterator>


Document::Document(Prolog * prolog, Element  * element, list<Misc *>* misc) : prolog(prolog), element(element), misc(misc) {}

ostream& operator << (ostream& os, const Document& D){
	os << &(D.prolog) << "\n";
	os << &(D.element) << "\n";
	for(list<Misc *>::iterator it = D.misc->begin(); it != D.misc->end(); it++){
		os << &it << "\n";
	}
	return os;
}
