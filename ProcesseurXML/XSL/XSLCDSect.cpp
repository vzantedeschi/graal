#include "XSLCDSect.h"

XSLCDSect::XSLCDSect(string cdata) : XSLContentItem(), cdata(cdata) {}

//ostream& operator << (ostream& os, const XSLCDSect& CDS){
void XSLCDSect::print(ostream& os) const{
	os << "<![CDATA[ " << this->cdata << " ]]>\n";
	//return os;
}
