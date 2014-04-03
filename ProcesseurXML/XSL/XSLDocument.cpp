#include "XSLDocument.h"

XSLCatalogue* catalogue;

XSLDocument::XSLDocument(XSLDeclaration * xsldecl, XSLCatalogue * cat) : xsldecl(xsldecl)
{
	catalogue = cat;
}

XSLDocument::~XSLDocument()
{
	delete xsldecl;
	delete catalogue;
}

void XSLDocument::afficherHTML(Document **docXML)
{
	catalogue->afficherHTML(docXML);
}

//string XSLDocument::afficherHTML(){
//	string res = "FONCTIONS AFFICHAGE HTML A FAIRE";
//	return res;
//}
