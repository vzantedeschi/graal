#include "XSLElementXSL.h"
#include <iterator>

XSLElementXSL::XSLElementXSL(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus, string matching) : XSLElement(type, atts, elementsInclus), matching(matching) {}


void XSLElementXSL::print(ostream& os) const {
	os << "\n<" << this->type;
	//manque elementsInclus matching
	for(list<XSLAttribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	os << ">";

	os << "</" << this->type << ">";
}


