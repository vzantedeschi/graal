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
	protected:
		string nom;
		string valeur;
};

#endif
