#include "NonEmptyElement.h"

NonEmptyElement::NonEmptyElement(string nom, list<Attribut *>* atts, list<ContentItem *>* content) : 
									Element(nom, atts), content(content) {}
