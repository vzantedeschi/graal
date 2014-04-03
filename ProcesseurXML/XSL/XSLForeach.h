#ifndef XSLFOREACH_H
#define XSLFOREACH_H

#include <string>
#include <list> 
#include "XSLElement.h"
#include "XSLAttribut.h"
using namespace std;

class XSLForeach : public XSLElement {
	public:
		XSLForeach(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus);
		~XSLForeach();
		
		void afficherElements(ContentItem* elementXML);
        void afficherElements(Document ** xmlD);
};

#endif
