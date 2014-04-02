#include "XSLApply.h"
#include <typeinfo>

extern XSLCatalogue* catalogue;

XSLApply::XSLApply(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : XSLElement(type, atts, elementsInclus) {}

void XSLApply::afficherElements(ContentItem * elementXML)
{
	if(atts)
	{
		auto l_front = (*atts).begin();

		advance(l_front, 0);
	
		string value = (*l_front)->getValeur();
		list<ContentItem *>* contentList = elementXML->getContent();
		for(list<ContentItem *>::iterator it1 = contentList->begin(); it1 != contentList->end(); it1++){
			if ((*it1)->getNom() == value)  
			{
				//cout << (*it1)->getNom() << endl;
				for(list<XSLTemplate *>::iterator it2 = (catalogue->getTemplates())->begin(); it2 != (catalogue->getTemplates())->end(); it2++){
					XSLTemplate templateCourant = **it2;
					if(templateCourant.getPremierAttribut() == (*it1)->getNom())
					{
						templateCourant.afficherHTML(*it1);
						//cout << (*it1)->getNom() << endl;
					}
				}
			}
		}
	}
	else if (typeid(*elementXML) == typeid(NonEmptyElement))
	{
		list<ContentItem *>* contentList = elementXML->getContent();
		for(list<ContentItem *>::iterator it1 = contentList->begin(); it1 != contentList->end(); it1++){
			if (typeid(**it1) == typeid(NonEmptyElement) || typeid(**it1) == typeid(EmptyElement)) 
			{
				//cout << (*it1)->getNom() << endl;
				for(list<XSLTemplate *>::iterator it2 = (catalogue->getTemplates())->begin(); it2 != (catalogue->getTemplates())->end(); it2++){
					XSLTemplate templateCourant = **it2;
					if(templateCourant.getPremierAttribut() == (*it1)->getNom())
					{
						templateCourant.afficherHTML(*it1);
						//cout << (*it1)->getNom() << endl;
					}
				}
			}
		}
	}
	else
	{
		cout <<"EmptyElement"<< endl;
	}
}
