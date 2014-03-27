#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list>
#include "XSDElement.h"
#include "XSDAttribut.h"
 
using namespace std;

class SimpleXSDElement : public XSDElement {
	public:
		SimpleXSDElement(string nom, list<XSDAttribut*>* atts);
		~SimpleXSDElement();
        string expr();
};

#endif
