#ifndef CDSECT_H
#define CDSECT_H

#include <string>
#include "ContentItem.h"
#include <iostream>
using namespace std;

class CDSect : public ContentItem {
	public:
		CDSect(string cdata);
		~CDSect();
		//friend ostream& operator << (ostream& os, const CDSect& CDS);
		virtual void print(ostream& os) const;
        string printElem();
	protected:
		string cdata;
};

#endif
