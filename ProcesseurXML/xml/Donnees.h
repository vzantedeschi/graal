#ifndef DONNEES_H
#define DONNEES_H

#include <string>
#include "ContentItem.h"
#include <iostream>
using namespace std;

class Donnees : public ContentItem {
	public:
		Donnees(string donnees);
		~Donnees();
		//friend ostream& operator << (ostream& os, const Donnees& D);
		virtual void print(ostream& os) const;
		void printDonnees();
	protected:
		string donnees;
};

#endif
