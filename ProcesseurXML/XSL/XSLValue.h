#ifndef XSLVALUE_H
#define XSLVALUE_H

#include <string>
#include <list> 
#include "XSLElement.h"
#include "XSLAttribut.h"
using namespace std;

class XSLValue : public XSLElement {
	public:
		XSLValue(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus);
		~XSLValue() {}

		void afficherElements(ContentItem* elementXML);
};

#endif
