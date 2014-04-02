#ifndef REFERENCEXSDELEMENT_H
#define REFERENCESDELEMENT_H

#include <string>
#include <list>
#include "XSDElement.h"
 
using namespace std;

class ReferenceXSDElement : public XSDElement {
	public:
		ReferenceXSDElement(string nom, list<XSDAttribut*>* atts);
		~ReferenceXSDElement();
        string expr(list<XSDElement*>* elems);
};

#endif
