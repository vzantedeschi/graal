#include "XSLDocTypeDecl.h"

XSLDocTypeDecl::XSLDocTypeDecl(string nom, string idExterne) : nom(nom), idExterne(idExterne) {}

ostream& operator << (ostream& os, const XSLDocTypeDecl& DTD){
	os << "<!DOCTYPE " << DTD.nom << " " << DTD.idExterne << " >\n" ;
	return os;
}
