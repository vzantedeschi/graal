#include "Donnees.h"

Donnees::Donnees(string donnees) : ContentItem(), donnees(donnees) {}


void Donnees::print(ostream& os) const {
	os << this->donnees;
	//return os;
}
