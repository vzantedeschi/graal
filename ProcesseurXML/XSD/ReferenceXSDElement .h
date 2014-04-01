#ifndef REFERENCEXSDELEMENT_H
#define REFERENCESDELEMENT_H

#include <string>
#include <list>
#include "SimpleXSDElement.h"
 
using namespace std;

class ReferenceXSDElement : public SimpleXSDElement {
	public:
		ReferenceXSDElement(string nom, list<XSDAttribut*>* atts);
		~ReferenceXSDElement();
        string expr(list<XSDElement*>* elems);
};

#endif
