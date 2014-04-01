#ifndef XSLDocument_H
#define XSLDocument_H

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
