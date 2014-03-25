#ifndef CDSECT_H
#define CDSECT_H

#include <string>
#include "ContentItem.h"
using namespace std;

class CDSect : public ContentItem {
	public:
		CDSect(string cdata);
		~CDSect();
	protected:
		string cdata;
};

#endif
