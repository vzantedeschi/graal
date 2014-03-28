#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
#include "ComplexType.h"

using namespace std;

class ComplexXSDElement : public XSDElement {
	public:
		ComplexXSDElement(string nom, list<XSDAttribut*>* atts, ComplexType* complexType);
		~ComplexXSDElement();
        string expr();
	protected:
		ComplexType* complexType;
};

#endif
