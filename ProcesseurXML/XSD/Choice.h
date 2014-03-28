#ifndef CHOICE_H
#define CHOICE_H

#include <string>
#include <list> 
#include "ComplexType.h"

using namespace std;

class Choice : ComplexType {
	public:
		Choice(list<XSDElement*>* XSDElements);
		~Choice();
        string expr();
};

#endif
