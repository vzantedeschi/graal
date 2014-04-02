#ifndef PI_H
#define PI_H

#include <string>
#include <list> 
#include <iostream>
#include "Misc.h"
#include "Attribut.h"
using namespace std;

class PI : public Misc {
	public:
		PI(string nom, list<Attribut *>* atts);
		~PI();

		//friend ostream& operator << (ostream& os, const PI& P);
		virtual void print(ostream& os) const;
        string printElem();
	protected:
		string nom;
		list<Attribut *>* atts;
};

#endif
