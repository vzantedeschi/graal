#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H

#include <string>
#include <list> 
#include "XSDElement.h"

using namespace std;

class ComplexType {
	public:
		ComplexType(list<XSDElement*>* XSDElements);
        virtual ~ComplexType();
		virtual string expr(list<XSDElement*>* elems);
        list<XSDElement*>* getxSDElements();
        virtual XSDElement* reference(string nom) =0;
	protected:
		list<XSDElement*>* xSDElements;
};

#endif
