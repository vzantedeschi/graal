#ifndef XSLELEMENTXSL_H
#define XSLELEMENTXSL_H

#include <string>
#include <list> 
#include "XSLElementXSL.h"
#include "XSLAttribut.h"
using namespace std;

class XSLElementXSL : public XSLElement {
	public:
		XSLElementXSL(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus, string matching);
		~XSLElementXSL();

		virtual void print(ostream& os) const;
	protected:
		string matching;
};

#endif
