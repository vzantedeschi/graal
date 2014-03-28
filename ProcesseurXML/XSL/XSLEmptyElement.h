#ifndef XSLEMPTYELEMENT_H
#define XSLEMPTYELEMENT_H

#include <string>
#include <list> 
#include "XSLAttribut.h"
#include "XSLElement.h"
using namespace std;

class XSLEmptyElement : public XSLElement {
	public:
		XSLEmptyElement(string nom, list<XSLAttribut *>* atts);
		~XSLEmptyElement();
		//friend ostream& operator << (ostream& os, const XSLEmptyElement& E);
		virtual void print(ostream& os) const;
};

#endif
