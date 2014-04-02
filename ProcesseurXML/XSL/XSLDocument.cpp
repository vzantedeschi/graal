#include "XSLDocument.h"

XSLDocument::XSLDocument(XSLDeclaration * xsldecl, XSLCatalogue * catalogue) : xsldecl(xsldecl), catalogue(catalogue) {}

XSLDocument::~XSLDocument()
{
	printf("Destructeurs XSL a faire pour éviter fuites mémoire");
}

void XSLDocument::afficherHTML(Document **docXML){
	printf("FONCTIONS AFFICHAGE HTML A FAIRE");

	catalogue->afficherHTML(docXML);
}

//string XSLDocument::afficherHTML(){
//	string res = "FONCTIONS AFFICHAGE HTML A FAIRE";
//	return res;
//}
