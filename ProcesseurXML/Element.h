#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <list>
//#include <iostream>
#include "Attribut.h"
#include "ContentItem.h" 
using namespace std;

class Element : public ContentItem {
	public:
		Element(string nom, list<Attribut *>* atts);
		~Element();

		//friend ostream& operator << (ostream& os, const Element& E);
	protected:
		string nom;
		list<Attribut *>* atts;
};

#endif
