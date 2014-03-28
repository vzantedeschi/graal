#ifndef XSLCOMMENT_H
#define XSLCOMMENT_H

#include "XSLMisc.h"
#include <string>
#include <iostream>
using namespace std;

class XSLComment : public XSLMisc {
	public:
		XSLComment(string comment);
		~XSLComment();
		//friend ostream& operator << (ostream& os, const XSLComment& C);
		virtual void print(ostream& os) const;
	protected:
		string comment;
};

#endif
