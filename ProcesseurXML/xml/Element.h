#ifndef ELEMENT_H
#define ELEMENT_H

#include "Attribut.h"
#include "ContentItem.h" 
#include <string>
#include <list>
using namespace std;

class Element : public ContentItem {
	public:
		Element(string nom, list<Attribut *>* atts);
		~Element();

		virtual void print(ostream& os) const = 0;
	protected:
		string nom;
		list<Attribut *>* atts;
};

#endif
