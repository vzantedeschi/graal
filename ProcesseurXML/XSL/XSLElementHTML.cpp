#include "XSLElementHTML.h"

XSLElementHTML::XSLElementHTML(string type, list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus) : XSLElement(type, atts, elementsInclus) {}

XSLElementHTML::~XSLElementHTML()
{
}

void XSLElementHTML::afficherElements(ContentItem* elementXML)
{
	if (elementsInclus)
	{
		string listeAtt = "";

		for(list<XSLAttribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
			listeAtt += " "+(**it).getAttribut();
		}

		cout << "<" << this->getType() << listeAtt << ">" << endl;
		for(list<XSLElement *>::iterator it = this->elementsInclus->begin(); it != this->elementsInclus->end(); it++){
			XSLElement* elementCourant = *it;
			elementCourant->afficherElements(elementXML);
		}
		cout << "</" << this->getType() << ">" << endl;
	}
	else
	{
		cout << "<" << this->getType() << "/>" << endl;
	}
}

void XSLElementHTML::afficherElements(Document ** xmlD)
{
	if (elementsInclus)
	{
		string listeAtt = "";

		for(list<XSLAttribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
			listeAtt += " "+(**it).getAttribut();
		}

		cout << "<" << this->getType() << listeAtt << ">" << endl;
		for(list<XSLElement *>::iterator it = this->elementsInclus->begin(); it != this->elementsInclus->end(); it++){
			XSLElement* elementCourant = *it;
			elementCourant->afficherElements(xmlD);
		}
		cout << "</" << this->getType() << ">" << endl;
	}
	else
	{
		cout << "<" << this->getType() << "/>" << endl;
	}
}
