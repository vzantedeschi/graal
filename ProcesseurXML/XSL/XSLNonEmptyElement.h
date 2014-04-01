#ifndef XSLNONEMPTYELEMENT_H
#define XSLNONEMPTYELEMENT_H

#include <string>
#include <list> 
#include "XSLElement.h"
#include "XSLAttribut.h"
#include "XSLContentItem.h"
using namespace std;

class XSLNonEmptyElement : public XSLElement {
	public:
		XSLNonEmptyElement(string nom, list<XSLAttribut *>* atts, list<XSLContentItem *>* content);
		~XSLNonEmptyElement();

		virtual void print(ostream& os) const;
	protected:
		list<XSLContentItem *>* content;
};

#endif
