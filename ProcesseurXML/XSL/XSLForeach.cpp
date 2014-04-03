#include "XSLForeach.h"
#include <typeinfo>
#include <boost/tokenizer.hpp>

using namespace boost;

XSLForeach::XSLForeach(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : XSLElement(type, atts, elementsInclus) {}

XSLForeach::~XSLForeach()
{
}

void XSLForeach::afficherElements(ContentItem * elementXML)
{
	if (typeid(*elementXML) == typeid(NonEmptyElement))
	{
		auto l_front = (*atts).begin();

		advance(l_front, 0);
	
		string value = (*l_front)->getValeur();
        string t(value.substr(value.rfind("/") + 1));
        list<ContentItem *>* contentList = elementXML->getContent();
        for(list<ContentItem *>::iterator it1 = contentList->begin(); it1 != contentList->end(); it1++){
	        if ((*it1)->getNom() == t) 
	        {
		        for(list<XSLElement *>::iterator it = this->elementsInclus->begin(); it != this->elementsInclus->end(); it++){
		            XSLElement* elementCourant = *it;
		            elementCourant->afficherElements(*it1);
	            }
	        }
        }
	}
}

void XSLForeach::afficherElements(Document ** xmlD)
{
	Element* elementXML = (*xmlD)->getElement();
	list<ContentItem *>* contentList = elementXML->getContent();
    auto l_front = (*atts).begin();
	advance(l_front, 0);
	string value = (*l_front)->getValeur();
    string t = value.substr(0, value.find('/'));;
    if (elementXML->getNom() == t) 
    {
        this->afficherElements(elementXML);
    }
}
