#ifndef XSLATTRIBUT_H
#define XSLATTRIBUT_H

#include <string>
#include <iostream>
using namespace std;

class XSLAttribut {
	public:
		XSLAttribut(string nom,string valeur);
		~XSLAttribut() {}
		
		string getNom();
		string getValeur();
		string getAttribut();
	protected:
		string nom;
		string valeur;
};

#endif
