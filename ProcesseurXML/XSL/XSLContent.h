#ifndef XSLCONTENT_H
#define XSLCONTENT_H

#include <string>
#include <list> 
#include "XSLElement.h"
#include "XSLAttribut.h"
using namespace std;

class XSLContent : public XSLElement {
	public:
		XSLContent(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus);
		~XSLContent() {}

		void afficherElements(ContentItem* elementXML);
};

#endif
