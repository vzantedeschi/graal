#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
using namespace std;

class XSDComment {
	public:
		XSDComment(string XSDComment);
		~XSDComment();
        string expr();
	protected:
		string XSDComment;
};

#endif
