#ifndef XSLTEMPLATE_H
#define XSLTEMPLATE_H

#include <string>
#include <list> 
#include "XSLElement.h"
#include "XSLAttribut.h"
#include "../struct.h"

using namespace std;

class XSLTemplate 
{
	public:
		XSLTemplate(list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus);
		~XSLTemplate();

		void afficherHTML(ContentItem* elementXML);
        void afficherHTML(Document **docXML);
		string getPremierAttribut();
	protected:
		list<XSLAttribut *>* atts;
		list<XSLElement *>* elementsInclus;
};

#endif
