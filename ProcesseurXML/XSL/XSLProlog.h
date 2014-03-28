#ifndef XSLPROLOG_H
#define XSLPROLOG_H

#include <string>
#include <list> 
#include <iostream>
#include "XSLPI.h"
#include "XSLDocTypeDecl.h"
#include "XSLMisc.h"
using namespace std;

class XSLProlog {
	public:
		XSLProlog(XSLPI * xslDecl, XSLDocTypeDecl * docTypeDecl, list<XSLMisc *>* misc1, list<XSLMisc *>* misc2);
		~XSLProlog();

		friend ostream& operator << (ostream& os, const XSLProlog& P);
	protected:
		XSLPI * xslDecl;
		XSLDocTypeDecl * docTypeDecl;
		list<XSLMisc *>* misc1;
		list<XSLMisc *>* misc2;
};

#endif
