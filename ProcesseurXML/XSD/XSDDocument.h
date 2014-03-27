#ifndef STRUCTXSD_H
#define STRUCTXSD_H

#include <string>
#include <list> 
#include "XSDProlog.h"
#include "Schema.h"
#include "XSDComment.h"

using namespace std;

class XSDDocument {
	public:
		XSDDocument(XSDProlog* XSDProlog, Schema* schema, list<XSDComment*>* XSDComments);
		~XSDDocument();
        string expr();
	protected:
		XSDProlog* XSDProlog;
		Schema* schema;
		list<XSDComment*>* XSDComments;
};

#endif
