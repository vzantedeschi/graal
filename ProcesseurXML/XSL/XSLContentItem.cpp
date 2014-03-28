#include "XSLContentItem.h"

XSLContentItem::XSLContentItem(){}
XSLContentItem::~XSLContentItem(){}

ostream& operator << (ostream& os, const XSLContentItem& CI){  
    CI.print(os);  
	return os;
} 
