#ifndef DOCTYPEDECL_H
#define DOCTYPEDECL_H

#include <string>
using namespace std;

class DocTypeDecl {
	public:
		DocTypeDecl(string nom, string idExterne);
		~DocTypeDecl();
	protected:
		string nom;
		string idExterne;
};

#endif
