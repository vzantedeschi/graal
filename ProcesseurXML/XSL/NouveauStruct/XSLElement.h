#ifndef XSLELEMENT_H
#define XSLELEMENT_H

#include "XSLAttribut.h"
#include <string>
#include <list>
using namespace std;

class XSLElement {
	public:
		XSLElement(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus);
		~XSLElement();

		virtual void print(ostream& os) const = 0;
	protected:
		string type;
		list<XSLElement *>* elementsInclus;
		list<XSLAttribut *>* atts;
};

#endif
