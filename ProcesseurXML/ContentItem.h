#ifndef CONTENTITEM_H
#define CONTENTITEM_H

#include <iostream>
using namespace std;

class ContentItem {
	public:
		ContentItem();
		~ContentItem();
		friend ostream& operator << (ostream& os, const ContentItem& CI);
		virtual void print(ostream& os) const = 0;
};

#endif
