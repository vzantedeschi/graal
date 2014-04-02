#ifndef XSLATTRIBUT_H
#define XSLATTRIBUT_H

#include <string>
#include <iostream>
using namespace std;

class XSLAttribut {
	public:
		XSLAttribut(string nom,string valeur);
		~XSLAttribut();
	protected:
		string nom;
		string valeur;
};

#endif
