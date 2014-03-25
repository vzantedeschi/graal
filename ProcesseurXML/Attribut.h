#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include <string>
using namespace std;

class Attribut {
	public:
		Attribut(string nom,string valeur);
		~Attribut();
	protected:
		string nom;
		string valeur;
};

#endif
