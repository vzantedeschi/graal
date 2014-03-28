#ifndef XSLMISC_H
#define XSLMISC_H

#include "XSLContentItem.h"

class XSLMisc : public XSLContentItem {
	public:
		XSLMisc();
		~XSLMisc();
		virtual void print(ostream& os) const = 0;
};

#endif
