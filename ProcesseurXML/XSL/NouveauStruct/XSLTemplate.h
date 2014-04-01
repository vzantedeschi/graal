#ifndef XSLTEMPLATE_H
#define XSLTEMPLATE_H

#include <string>
#include <list> 
#include "XSLElementXSL.h"
#include "XSLAttribut.h"
using namespace std;

class XSLTemplate 
{
	public:
		XSLTemplate(list<XSLAttribut *>* atts, list<XSLElement *>* elementsInclus);
		~XSLTemplate();
};

#endif
