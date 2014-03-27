#include <string>
#include <list> 
using namespace std;


//class XSDAttribut
XSDAttribut::XSDAttribut(string nom,string valeur): nom(nom), valeur(valeur){}
string XSDAttribut::expr(){
    string res ="";
    if (nom.compare("type") == 0 ){
        if (valeur.compare("xsd:string") == 0 ){
            res += "[^<]*";
        }
        else if (valeur.compare("xsd:date") == 0 ){
            res += "[0-9]{4}\-[0-9]{2}\-[0-9]{2}";
        }
        else {
            res += "Erreur " + nom + " XSDAttribut non pris en charge";
        }      
    }
    else{
        res += "Erreur " + nom + " XSDAttribut non pris en charge";
    return res;
}
