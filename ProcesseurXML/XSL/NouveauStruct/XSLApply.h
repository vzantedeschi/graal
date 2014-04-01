#ifndef XSLAPPLY_H
#define XSLAPPLY_H

#include <string>
#include <list> 
#include "XSLElement.h"
#include "XSLApply.h"
using namespace std;

class XSLApply : public XSLElement {
	public:
		XSLElementXSL(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus);
		~XSLElementXSL();

};

#endif
