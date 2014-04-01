#ifndef XSLDOCUMENT_H
#define XSLDOCUMENT_H

#include <list> 
#include "XSLDeclaration.h"
#include "XSLCatalogue.h"
using namespace std;

class XSLDocument 
{
	public:
		XSLDocument(XSLDeclaration * xsldecl, XSLCatalogue * catalogue);
		~XSLDocument();

	protected:
		XSLDeclaration * xsldecl;
		XSLCatalogue * catalogue;
};

#endif
