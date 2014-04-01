#include "ContentItem.h"

ContentItem::ContentItem(){}

ostream& operator << (ostream& os, const ContentItem& CI){  
    CI.print(os);  
	return os;
} 

ContentItem::~ContentItem(){
}
