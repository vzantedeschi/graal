#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H

#include <string>
#include <list> 
#include "XSDElement.h"

using namespace std;

class ComplexType {
	public:
		ComplexType(list<XSDElement*>* XSDElements);
		~ComplexType();
		virtual string expr(list<XSDElement*>* elems);
	protected:
		list<XSDElement*>* XSDElements;
};

#endif
