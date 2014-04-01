#ifndef XSLEMPTYELEMENT_H
#define XSLEMPTYELEMENT_H

#include <string>
#include <list> 
#include "XSLElement.h"
#include "XSLAttribut.h"
using namespace std;

class XSLEmptyElement : public XSLElement {
	public:
		XSLEmptyElement(string type, list<XSLAttribut *>* atts, elementsInclus, list<XSLElement *>* elementsInclus, string contenu);
		~XSLEmptyElement();
		//friend ostream& operator << (ostream& os, const XSLEmptyElement& E);
		virtual void print(ostream& os) const;
	protected: 
		string contenu;
};

#endif
