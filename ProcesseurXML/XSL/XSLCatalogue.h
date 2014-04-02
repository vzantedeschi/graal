#ifndef XSLCATALOGUE_H
#define XSLCATALOGUE_H

#include <string>
#include <list> 
#include "XSLAttribut.h"
#include "XSLTemplate.h"

using namespace std;

class XSLCatalogue {
	public:
		XSLCatalogue(list<XSLAttribut *>* atts,list<XSLTemplate *>* templates);
		~XSLCatalogue();
	protected:
		list<XSLAttribut*>* atts;
		list<XSLTemplate*>* templates;
};

#endif
