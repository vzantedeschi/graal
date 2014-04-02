#ifndef SCHEMA_H
#define SCHEMA_H

#include <string>
#include <list> 
#include "XSDElement.h"
#include "XSDAttribut.h"

using namespace std;

class Schema {
	public:
        Schema(list<XSDAttribut*>* atts,list<XSDElement*>* xSDElements);
		~Schema();
        string expr();
	protected:
		list<XSDAttribut*>* atts;
        list<XSDElement*>* xSDElements;
};

#endif
