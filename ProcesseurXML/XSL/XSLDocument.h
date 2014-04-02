#ifndef XSLDOCUMENT_H
#define XSLDOCUMENT_H

#include <list> 
#include "XSLDeclaration.h"
#include "XSLCatalogue.h"
#include "../struct.h"

using namespace std;

class XSLDocument 
{
	public:
		XSLDocument(XSLDeclaration * xsldecl, XSLCatalogue * catalogue);
		~XSLDocument();

		void afficherHTML(Document** docXML);
		//void afficherHTML();
	protected:
		XSLDeclaration * xsldecl;
		XSLCatalogue * catalogue;
};

#endif
