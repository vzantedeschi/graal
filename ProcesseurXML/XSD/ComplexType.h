#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
#include "XSDElements.h"

using namespace std;

class ComplexType {
	public:
		ComplexType(list<XSDElement*>* XSDElements);
		~ComplexType();
		virtual string expr();
	protected:
		list<XSDElement*>* XSDElements;
};

#endif
