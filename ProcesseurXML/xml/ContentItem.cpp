#include "ContentItem.h"

ContentItem::ContentItem(){}

ostream& operator << (ostream& os, const ContentItem& CI){  
    CI.print(os);  
	return os;
} 

ContentItem::~ContentItem(){
}

string ContentItem::getNom(){
	return "";
}

list<ContentItem *>* ContentItem::getContent()
{
	cout << "get content element" << endl;
	return NULL;
}
