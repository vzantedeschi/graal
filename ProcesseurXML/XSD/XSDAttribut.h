#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 

using namespace std;

class XSDAttribut {
	public:
		XSDAttribut(string nom,string valeur);
		~XSDAttribut();Doc
        string expr();
	protected:
		string nom;
		string valeur;
};

#endif
