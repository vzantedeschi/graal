#ifndef XSDDOCUMENT_H
#define STRUCTXSD_H

#include <string>
#include <list> 
#include "XSDProlog.h"
#include "Schema.h"
#include "XSDComment.h"

using namespace std;

class XSDDocument {
	public:
		XSDDocument(XSDProlog* prolog, Schema* schema, list<XSDComment*>* comments);
		~XSDDocument();
        string expr();
	protected:
		XSDProlog* prolog;
		Schema* schema;
		list<XSDComment*>* comments;
};

#endif
