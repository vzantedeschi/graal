#include "DocTypeDecl.h"

DocTypeDecl::DocTypeDecl(string nom, string idExterne) : nom(nom), idExterne(idExterne) {}

ostream& operator << (ostream& os, const DocTypeDecl& DTD){
	os << "<!DOCTYPE " << DTD.nom << " " << DTD.idExterne << " \"no.dtd\">" ;
	return os;
}

DocTypeDecl::~DocTypeDecl()
{
}
