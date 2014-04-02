#ifndef CHOICE_H
#define CHOICE_H

#include <string>
#include <list> 
#include "ComplexType.h"


using namespace std;

class Choice : public ComplexType {
	public:
		Choice(list<XSDElement*>* XSDElements);
        ~Choice();
        string expr(list<XSDElement*>* elems);
};

#endif
