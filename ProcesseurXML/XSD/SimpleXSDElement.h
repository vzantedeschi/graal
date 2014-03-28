#ifndef SIMPLEXSDELEMENT_H
#define SIMPLEXSDELEMENT_H

#include <string>
#include <list>
#include "XSDElement.h"
 
using namespace std;

class SimpleXSDElement : public XSDElement {
	public:
		SimpleXSDElement(string nom, list<XSDAttribut*>* atts);
		~SimpleXSDElement();
        string expr();
};

#endif
