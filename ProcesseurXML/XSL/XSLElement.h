#ifndef XSLELEMENT_H
#define XSLELEMENT_H

#include "XSLAttribut.h"
#include "../struct.h"
#include <string>
#include <list>
using namespace std;

class XSLElement {
	public:
		XSLElement(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus);
		virtual ~XSLElement();

		string getType();
		virtual void afficherElements(ContentItem* elementXML);
	protected:
		string type;
		list<XSLElement *>* elementsInclus;
		list<XSLAttribut *>* atts;
};

#endif
