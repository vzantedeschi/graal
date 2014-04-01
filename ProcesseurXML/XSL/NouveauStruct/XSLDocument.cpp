#include "XSLDocument.h"
#include <iterator>


XSLDocument::XSLDocument(XSLProlog * prolog, XSLElement * element) : prolog(prolog), element(element) {}

ostream& operator << (ostream& os, const XSLDocument& D){
	os << *(D.prolog) << "\n";
	os << *(D.element) << "\n";
	
	return os;
}
