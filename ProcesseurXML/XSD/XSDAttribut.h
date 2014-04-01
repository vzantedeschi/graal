#ifndef XSDATTRIBUT_H
#define XSDATTRIBUT_H

#include <string>
#include <list> 

using namespace std;

class XSDAttribut {
	public:
		XSDAttribut(string nom,string valeur);
		~XSDAttribut();
        string expr();
        string getNom();
		string getValeur();
	protected:
		string nom;
		string valeur;
};

#endif
