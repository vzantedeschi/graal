#ifndef DOCTYPEDECL_H
#define DOCTYPEDECL_H

#include <string>
#include <iostream>
using namespace std;

class DocTypeDecl {
	public:
		DocTypeDecl(string nom, string idExterne);
		~DocTypeDecl();

	friend ostream& operator << (ostream& os, const DocTypeDecl& DTD);
	protected:
		string nom;
		string idExterne;
};

#endif
