#include "Comment.h"

Comment::Comment(string comment) : Misc(), comment(comment) {}

//ostream& operator << (ostream& os, const Comment& C){
void Comment::print(ostream& os) const{
	os << "<!-- " << this->comment << " -->\n";
	//return os;
}
