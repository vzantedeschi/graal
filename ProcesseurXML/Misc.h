#ifndef MISC_H
#define MISC_H

#include "ContentItem.h"

class Misc : public ContentItem {
	public:
		Misc();
		~Misc();
		virtual void print(ostream& os) const = 0;
};

#endif
