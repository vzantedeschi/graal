#include "XSLForeach.h"
#include <typeinfo>

XSLForeach::XSLForeach(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : XSLElement(type, atts, elementsInclus) {}


void XSLForeach::afficherElements(ContentItem * elementXML)
{
	if (typeid(*elementXML) == typeid(NonEmptyElement))
	{
		auto l_front = (*atts).begin();

		advance(l_front, 0);
	
		string value = (*l_front)->getValeur();
		list<ContentItem *>* contentList = elementXML->getContent();
		for(list<ContentItem *>::iterator it1 = contentList->begin(); it1 != contentList->end(); it1++){
			if ((*it1)->getNom() == value) 
			{
				for(list<XSLElement *>::iterator it = this->elementsInclus->begin(); it != this->elementsInclus->end(); it++){
				XSLElement* elementCourant = *it;
				elementCourant->afficherElements(*it1);
			}
			}
		}
	}
	else
	{
		cout <<"EmptyElement"<< endl;
	}
}
