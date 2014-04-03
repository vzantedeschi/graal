#include "ReferenceXSDElement.h"
#include "ComplexXSDElement.h"
#include "XSDElement.h"
#include "XSDAttribut.h"
#include <typeinfo>

//class SimpleXSDElement
ReferenceXSDElement::ReferenceXSDElement(string nom, list<XSDAttribut*>* atts) : XSDElement(nom, atts) {}

ReferenceXSDElement::~ReferenceXSDElement() {}

string ReferenceXSDElement::expr(list<XSDElement*>* elems){
    string res = "";
    bool trouve = false;
    XSDElement* leBon;
    for (XSDElement* elem : *elems)
    {
        // pour le moment ne regarde que les elements au premier niveau du schema
        if ( nom.compare(elem->getNom()) == 0)
        {
            trouve = true;
            leBon = elem;
            break;
        }
        if (typeid(elem) == typeid(ComplexXSDElement))
        {
            //TODO rechercher dans les sous elements de manière recursive pour trouver la reference
            //TODO creer une methode recursive de recherche de l element
        }
        if (trouve)
        {
            break;
        }
    }

    if (trouve)
    {
        string maxOccurs = "0";
        string minOccurs = "0";
        bool maxTrouve = false;
        bool minTrouve = false;
        // chercher le nombre d occurences max de la reference
        for (XSDAttribut* att : *atts)
        {
            if (att->getNom().compare("maxOccurs")==0)
            {
                maxOccurs = att ->getValeur();
                maxTrouve = true;
            }

            if (att->getNom().compare("minOccurs")==0)
            {
                minOccurs = att ->getValeur();
                minTrouve = true;
            }

            if(maxTrouve && minTrouve)
            {
                break;
            }
        }

        if (minOccurs.compare("unbounded") == 0)
        {
            res += "(" + leBon->expr(elems) + ")*";
        }
        else
        {
            res += "(" + leBon->expr(elems) + "){" + minOccurs + "," + maxOccurs + "}";
        }
    }
    else
    {
        res += " erreur : reference vers un element inconnu : " + nom ;
    }

    return res;
}
