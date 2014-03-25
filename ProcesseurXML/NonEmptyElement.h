#ifndef NONEMPTYELEMENT_H
#define NONEMPTYELEMENT_H

#include <string>
#include <list> 
#include "Element.h"
#include "Attribut.h"
#include "ContentItem.h"
using namespace std;

class NonEmptyElement : public Element {
	public:
		NonEmptyElement(string nom, list<Attribut *>* atts, list<ContentItem *>* content);
		~NonEmptyElement();
	protected:
		list<ContentItem *>* content;
};

#endif