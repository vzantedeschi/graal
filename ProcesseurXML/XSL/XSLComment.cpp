#include "XSLComment.h"

XSLComment::XSLComment(string comment) : XSLMisc(), comment(comment) {}

//ostream& operator << (ostream& os, const XSLComment& C){
void XSLComment::print(ostream& os) const{
	os << "<!-- " << this->comment << " -->\n";
	//return os;
}
