#ifndef DONNEES_H
#define DONNEES_H

#include <string>
#include "ContentItem.h"
using namespace std;

class Donnees : public ContentItem {
	public:
		Donnees(string donnees);
		~Donnees();
	protected:
		string donnees;
};

#endif
