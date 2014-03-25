#ifndef PROLOG_H
#define PROLOG_H

#include <string>
#include <list> 
#include "PI.h"
#include "DocTypeDecl.h"
#include "Misc.h"
using namespace std;

class Prolog {
	public:
		Prolog(PI * xmlDecl, DocTypeDecl * docTypeDecl, list<Misc *>* misc1, list<Misc *>* misc2);
		~Prolog();
	protected:
		PI * xmlDecl;
		DocTypeDecl * docTypeDecl;
		list<Misc *>* misc1;
		list<Misc *>* misc2;
};

#endif
