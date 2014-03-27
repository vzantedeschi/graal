#include <string>
#include <list> 
using namespace std;

//class ComplexType
ComplexType::ComplexType(list<Element*>* elements): elements(elements){}
string Choice::expr(){
    string res = "Erreur appel d'une méthode abstraite : ComplexType";
    return res;
}
