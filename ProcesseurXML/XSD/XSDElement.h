#ifndef XSDELEMENT_H
#define XSDELEMENT_H

#include <string>
#include <list> 
#include "XSDAttribut.h"

using namespace std;

class XSDElement {
	public:
		XSDElement(string nom, list<XSDAttribut*>* atts);
        virtual ~XSDElement();
        virtual string expr(list<XSDElement*>* elems);
        string getNom();
        virtual XSDElement* reference(string nom) =0;
	protected:
        string nom;
		list<XSDAttribut*>* atts;
};

#endif
