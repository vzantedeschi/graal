#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
#include "ComplexType.h"
#include "XSDElement.h"

using namespace std;

class Choice : ComplexType {
	public:
		Choice(list<XSDElement*>* XSDElements);
		~Choice();
        string expr();
};

#endif
