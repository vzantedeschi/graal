#include "XSLPI.h"
#include <iterator>

XSLPI::XSLPI(string nom, list<XSLAttribut *>* atts) : XSLMisc(), nom(nom), atts(atts) {}

//ostream& operator << (ostream& os, const XSLPI& P){
void XSLPI::print(ostream& os) const{
	os << "<?" << this->nom;
	for(list<XSLAttribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
		os << " " << **it;
	}
	os << " ?>\n";
	//return os;
}
