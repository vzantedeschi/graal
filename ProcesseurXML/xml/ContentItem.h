#ifndef CONTENTITEM_H
#define CONTENTITEM_H

#include <iostream>
#include <list> 
using namespace std;

class ContentItem {
	public:
		ContentItem();
		virtual ~ContentItem();
		friend ostream& operator << (ostream& os, const ContentItem& CI);
		virtual void print(ostream& os) const = 0;
        virtual string printElem()=0;
		virtual string getNom();
		virtual list<ContentItem *>* getContent();
		virtual void printDonnees();
        virtual void matchPath(list<ContentItem *>* liste, string path);
};

#endif
