#include "XSLProlog.h"
#include <iterator>

XSLProlog::XSLProlog(XSLPI * xslDecl, XSLDocTypeDecl * docTypeDecl, list<XSLMisc *>* misc1, list<XSLMisc *>* misc2) : xslDecl(xslDecl), docTypeDecl(docTypeDecl), misc1(misc1), misc2(misc2) {}

ostream& operator << (ostream& os, const XSLProlog& P){
	//<?xsl version="1.0" encoding="UTF-8"?>
	os << *(P.xslDecl) << "\n";
	if(P.docTypeDecl != NULL){
		os << *(P.docTypeDecl) << "\n";
	}

	for(list<XSLMisc *>::iterator it = P.misc1->begin(); it != P.misc1->end(); it++){
			os << **it << "\n";
	}
	if(P.misc2 != NULL){
		for(list<XSLMisc *>::iterator it = P.misc2->begin(); it != P.misc2->end(); it++){
				os << **it << "\n";
		}
	}
	return os;
}
