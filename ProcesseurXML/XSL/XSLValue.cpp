#include "XSLValue.h"


XSLValue::XSLValue(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : XSLElement(type, atts, elementsInclus) {}

void XSLValue::afficherElements(ContentItem* elementXML)
{
	auto l_front = (*atts).begin();

	advance(l_front, 0);
	
	string value = (*l_front)->getValeur();
	if (value == ".")
	{
		for(list<ContentItem *>::iterator it = (elementXML->getContent())->begin(); it != (elementXML->getContent())->end(); it++){
			cout << **it;
		}
		
	}
	else
	{
		for(list<ContentItem *>::iterator it = (elementXML->getContent())->begin(); it != (elementXML->getContent())->end(); it++){
			if(value == (*it)->getNom())
			{
				(**it).printDonnees();
			}

		}
	}
}
