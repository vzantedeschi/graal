#ifndef COMMENT_H
#define COMMENT_H

#include "Misc.h"
#include <string>
#include <iostream>
using namespace std;

class Comment : public Misc {
	public:
		Comment(string comment);
		~Comment();
		//friend ostream& operator << (ostream& os, const Comment& C);
		virtual void print(ostream& os) const;
	protected:
		string comment;
};

#endif
