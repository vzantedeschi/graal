#ifndef COMPLEXXSDELEMENT_H
#define COMPLEXXSDELEMENT_H

#include <string>
#include <list> 
#include "ComplexType.h"
#include "XSDAttribut.h"

using namespace std;

class ComplexXSDElement : public XSDElement {
	public:
		ComplexXSDElement(string nom, list<XSDAttribut*>* atts, ComplexType* complexType);
		~ComplexXSDElement();
        string expr(list<XSDElement*>* elems);
        ComplexType* getComplexType();
	protected:
		ComplexType* complexType;
};

#endif
