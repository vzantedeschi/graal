#ifndef PROLOG_H
#define PROLOG_H

#include <string>
#include <list> 
#include <iostream>
#include "PI.h"
#include "DocTypeDecl.h"
#include "Misc.h"
using namespace std;

class Prolog {
	public:
		Prolog(/*PI * xmlDecl, */DocTypeDecl * docTypeDecl, list<Misc *>* misc1, list<Misc *>* misc2);
		~Prolog();

		friend ostream& operator << (ostream& os, const Prolog& P);        
	protected:
		//PI * xmlDecl;
		DocTypeDecl * docTypeDecl;
		list<Misc *>* misc1;
		list<Misc *>* misc2;
};

#endif
