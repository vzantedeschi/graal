#include "XSLElement.h"

XSLElement::XSLElement(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : type(type), atts(atts), elementsInclus(elementsInclus) {}
