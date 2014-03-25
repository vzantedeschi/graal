#ifndef EMPTYELEMENT_H
#define EMPTYELEMENT_H

#include <string>
#include <list> 
#include "Attribut.h"
#include "Element.h"
using namespace std;

class EmptyElement : public Element {
	public:
		EmptyElement(string nom, list<Attribut *>* atts);
		~EmptyElement();
};

#endif
