#include "XSLAttribut.h"

XSLAttribut::XSLAttribut(string nom,string valeur) : nom(nom), valeur(valeur) {}

string XSLAttribut::getNom()
{
	return nom;
}

string XSLAttribut::getValeur()
{
	return valeur;
}
