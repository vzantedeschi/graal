#include "XSLDocument.h"
#include <iterator>


XSLDocument::XSLDocument(XSLProlog * prolog, XSLElement * element, list<XSLMisc *>* misc) : prolog(prolog), element(element), misc(misc) {}

ostream& operator << (ostream& os, const XSLDocument& D){
	os << *(D.prolog) << "\n";
	os << *(D.element) << "\n";
	for(list<XSLMisc *>::iterator it = D.misc->begin(); it != D.misc->end(); it++){
		os << **it << "\n";
	}
	return os;
}
