#include "XSLDocument.h"

XSLCatalogue* catalogue;

XSLDocument::XSLDocument(XSLDeclaration * xsldecl, XSLCatalogue * cat) : xsldecl(xsldecl)
{
	catalogue = cat;
}

XSLDocument::~XSLDocument()
{
}

void XSLDocument::afficherHTML(Document **docXML){
	Element* elementXML = (*docXML)->getElement();

	catalogue->afficherHTML(elementXML);
}

//string XSLDocument::afficherHTML(){
//	string res = "FONCTIONS AFFICHAGE HTML A FAIRE";
//	return res;
//}
