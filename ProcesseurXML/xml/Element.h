#ifndef ELEMENT_H
#define ELEMENT_H

#include "Attribut.h"
#include "ContentItem.h" 
#include <string>
#include <list>
using namespace std;

class Element : public ContentItem {
	public:
		Element(string nom, list<Attribut *>* atts);
		virtual ~Element();

		virtual void print(ostream& os) const = 0;
        virtual string printElem()= 0;
		
		string getNom();
		virtual list<ContentItem *>* getContent();
        virtual void matchPath(list<ContentItem *>* liste,string path);
		virtual void printDonnees();
	protected:
		string nom;
		list<Attribut *>* atts;
};

#endif
