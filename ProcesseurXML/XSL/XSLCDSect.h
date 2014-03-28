#ifndef XSLCDSECT_H
#define XSLCDSECT_H

#include <string>
#include "XSLContentItem.h"
#include <iostream>
using namespace std;

class XSLCDSect : public XSLContentItem {
	public:
		XSLCDSect(string cdata);
		~XSLCDSect();
		//friend ostream& operator << (ostream& os, const XSLCDSect& CDS);
		virtual void print(ostream& os) const;
	protected:
		string cdata;
};

#endif
