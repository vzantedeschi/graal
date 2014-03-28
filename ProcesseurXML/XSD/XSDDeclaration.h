#ifndef XSDDECLARATION_H
#define XSDDECLARATION_H

#include <string>
#include <list> 
#include "XSDAttribut.h"
using namespace std;

class XSDDeclaration {
	public:
		XSDDeclaration(XSDAttribut* att1, XSDAttribut* att2);
		~XSDDeclaration();
        string expr();
	protected:
		XSDAttribut* att1, att2;
};

#endif
