#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include "Misc.h"
using namespace std;

class Comment : public Misc {
	public:
		Comment(string comment);
		~Comment();
	protected:
		string comment;
};

#endif
