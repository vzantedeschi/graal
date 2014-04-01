#include "XSLDonnees.h"

XSLDonnees::XSLDonnees(string donnees) : XSLContentItem(), donnees(donnees) {}


void XSLDonnees::print(ostream& os) const {
	os << this->donnees;
	//return os;
}
