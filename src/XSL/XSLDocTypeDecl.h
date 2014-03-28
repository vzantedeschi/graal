#ifndef XSLXSLDocTypeDecl_H
#define XSLXSLDocTypeDecl_H

#include <string>
#include <iostream>
using namespace std;

class XSLDocTypeDecl {
	public:
		XSLDocTypeDecl(string nom, string idExterne);
		~XSLDocTypeDecl();

	friend ostream& operator << (ostream& os, const XSLDocTypeDecl& DTD);
	protected:
		string nom;
		string idExterne;
};

#endif
