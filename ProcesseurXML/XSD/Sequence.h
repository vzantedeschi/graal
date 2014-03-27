#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
#include "ComplexType.h"
#include "XSDElement.h"

using namespace std;

class Sequence : ComplexType {
	public:
		Sequence(list<XSDElement*>* XSDElements);
		~Sequence();
        string expr();
};

#endif
