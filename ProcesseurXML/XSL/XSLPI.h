#ifndef XSLPI_H
#define XSLPI_H

#include <string>
#include <list> 
#include <iostream>
#include "XSLMisc.h"
#include "XSLAttribut.h"
using namespace std;

class XSLPI : public XSLMisc {
	public:
		XSLPI(string nom, list<XSLAttribut *>* atts);
		~XSLPI();

		//friend ostream& operator << (ostream& os, const XSLPI& P);
		virtual void print(ostream& os) const;
	protected:
		string nom;
		list<XSLAttribut *>* atts;
};

#endif
