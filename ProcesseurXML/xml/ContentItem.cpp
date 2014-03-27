#include "ContentItem.h"

ContentItem::ContentItem(){}
ContentItem::~ContentItem(){}

ostream& operator << (ostream& os, const ContentItem& CI){  
    CI.print(os);  
	return os;
} 
