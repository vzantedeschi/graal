#ifndef XSLELEMENT_H
#define XSLELEMENT_H

#include "XSLAttribut.h"
#include "XSLContentItem.h" 
#include <string>
#include <list>
using namespace std;

class XSLElement : public XSLContentItem {
	public:
		XSLElement(string nom, list<XSLAttribut *>* atts);
		~XSLElement();

		virtual void print(ostream& os) const = 0;
	protected:
		string nom;
		list<XSLAttribut *>* atts;
};

#endif
