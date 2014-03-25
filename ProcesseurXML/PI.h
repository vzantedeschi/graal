#ifndef PI_H
#define PI_H

#include <string>
#include <list> 
#include "Misc.h"
#include "Attribut.h"
using namespace std;

class PI : public Misc {
	public:
		PI(string nom, list<Attribut *>* atts);
		~PI();
	protected:
		string nom;
		list<Attribut *>* atts;
};

#endif
