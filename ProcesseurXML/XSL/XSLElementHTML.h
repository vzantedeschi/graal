#ifndef XSLELEMENTHTML_H
#define XSLELEMENTHTML_H

#include <string>
#include <list> 
#include "XSLElement.h"
using namespace std;

class XSLElementHTML : public XSLElement {
	public:
		XSLElementHTML(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus);
		~XSLElementHTML() {}
		
		void afficherElements();
};

#endif
