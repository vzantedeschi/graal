#ifndef XSLDONNEES_H
#define XSLDONNEES_H

#include <string>
#include "XSLContentItem.h"
#include <iostream>
using namespace std;

class XSLDonnees : public XSLContentItem {
	public:
		XSLDonnees(string donnees);
		~XSLDonnees();
		//friend ostream& operator << (ostream& os, const XSLDonnees& D);
		virtual void print(ostream& os) const;
	protected:
		string donnees;
};

#endif
