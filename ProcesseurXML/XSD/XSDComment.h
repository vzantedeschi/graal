#ifndef XSDCOMMENT_H
#define XSDCOMMENT_H

#include <string>
#include <list> 
using namespace std;

class XSDComment {
	public:
		XSDComment(string comment);
		~XSDComment();
        string expr();
	protected:
		string comment;
};

#endif
