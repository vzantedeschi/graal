#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
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
