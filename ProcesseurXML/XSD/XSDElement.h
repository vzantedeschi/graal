#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
#include "XSDAttribut.h"

using namespace std;

class XSDElement {
	public:
		XSDElement(string nom, list<XSDAttribut*>* atts);
		~XSDElement();
        virtual string expr();
	protected:
        string nom;
		list<XSDAttribut*>* atts;
};

#endif
