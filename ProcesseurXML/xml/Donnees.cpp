#include "Donnees.h"

Donnees::Donnees(string donnees) : ContentItem(), donnees(donnees) {}


void Donnees::print(ostream& os) const {
	os << this->donnees << endl;
	//return os;
}

Donnees::~Donnees(){
}


string Donnees::printElem(){
    return this->donnees;
}

void Donnees::printDonnees()
{
	cout << donnees << endl;
}
