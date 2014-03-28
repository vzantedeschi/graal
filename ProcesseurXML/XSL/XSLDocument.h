#ifndef XSLDocument_H
#define XSLDocument_H

#include <list> 
#include <iostream>
#include "XSLProlog.h"
#include "XSLElement.h"
#include "XSLMisc.h"
using namespace std;

class XSLDocument {
	public:
		XSLDocument(XSLProlog * prolog, XSLElement * element, list<XSLMisc *>* misc);
		~XSLDocument();

		friend ostream& operator << (ostream& os, const XSLDocument& D);
	protected:
		XSLProlog * prolog;
		XSLElement * element;
		list<XSLMisc *>* misc;
};

#endif
