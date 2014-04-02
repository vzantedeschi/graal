#ifndef XSLDECLARATION_H
#define XSLDECLARATION_H

#include <string>
#include <list> 
#include "XSLAttribut.h"
using namespace std;

class XSLDeclaration {
	public:
		XSLDeclaration(list<XSLAttribut *> *atts);
		~XSLDeclaration();
	protected:
		list<XSLAttribut*> *atts;
};

#endif
