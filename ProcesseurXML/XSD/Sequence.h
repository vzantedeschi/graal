#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
#include <list> 
#include "ComplexType.h"

using namespace std;

class Sequence : ComplexType {
	public:
		Sequence(list<XSDElement*>* XSDElements);
		~Sequence();
        string expr();
};

#endif
