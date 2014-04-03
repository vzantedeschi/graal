#ifndef XSLAPPLY_H
#define XSLAPPLY_H

#include <string>
#include <list> 
#include "XSLElement.h"
#include "XSLApply.h"
#include "XSLTemplate.h"
#include "XSLCatalogue.h"
#include "../struct.h"
using namespace std;

class XSLApply : public XSLElement {
	public:
		XSLApply(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus);
		~XSLApply();

		void afficherElements(ContentItem * elementXML);

};

#endif
