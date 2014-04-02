#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include <string>
#include <iostream>
using namespace std;

class Attribut {
	public:
		Attribut(string nom,string valeur);
		~Attribut();
		friend ostream& operator << (ostream& os, const Attribut& A);
	protected:
		string nom;
		string valeur;
};

#endif
