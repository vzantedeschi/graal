#ifndef XSLCATALOGUE_H
#define XSLCATALOGUE_H

#include <string>
#include <list> 
#include <cstring>
#include "XSLAttribut.h"
#include "XSLTemplate.h"
#include "../struct.h"

using namespace std;

class XSLCatalogue {
	public:
		XSLCatalogue(list<XSLAttribut *>* atts,list<XSLTemplate *>* templates);
		~XSLCatalogue();

		void afficherHTML(Element* elementXML);
		list<XSLTemplate *>* getTemplates();
	protected:
		list<XSLAttribut*>* atts;
		list<XSLTemplate*>* templates;
};

#endif
