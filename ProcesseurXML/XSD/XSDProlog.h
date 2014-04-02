#ifndef XSDPROLOG_H
#define XSDPROLOG_H

#include <string>
#include <list> 
#include "XSDDeclaration.h"
#include "XSDComment.h"

using namespace std;

class XSDProlog {
	public:
		XSDProlog(XSDDeclaration* xsdDecl, list<XSDComment*>* XSDComments);
		~XSDProlog();
        string expr();
	protected:
		XSDDeclaration* xsdDecl;
        list<XSDComment*>* xSDComments;
};

#endif


