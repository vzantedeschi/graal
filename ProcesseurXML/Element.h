#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <list>
#include "Attribut.h"
#include "ContentItem.h" 
using namespace std;

class Element : public ContentItem {
	public:
		Element(string nom, list<Attribut *>* atts);
		~Element();
	protected:
		string nom;
		list<Attribut *>* atts;
};

#endif
