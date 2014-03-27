#include "CDSect.h"

CDSect::CDSect(string cdata) : ContentItem(), cdata(cdata) {}

//ostream& operator << (ostream& os, const CDSect& CDS){
void CDSect::print(ostream& os) const{
	os << "<![CDATA[ " << this->cdata << " ]]>\n";
	//return os;
}
