#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <list> 
#include "Prolog.h"
#include "Element.h"
#include "Misc.h"
using namespace std;

class Document {
	public:
		Document(Prolog * prolog, Element * element, list<Misc *>* misc);
		~Document();
	protected:
		Prolog * prolog;
		Element * element;
		list<Misc *>* misc;
};

#endif
