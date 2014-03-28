#ifndef XSLCONTENTITEM_H
#define XSLCONTENTITEM_H

#include <iostream>
using namespace std;

class XSLContentItem {
	public:
		XSLContentItem();
		~XSLContentItem();
		friend ostream& operator << (ostream& os, const XSLContentItem& CI);
		virtual void print(ostream& os) const = 0;
};

#endif
