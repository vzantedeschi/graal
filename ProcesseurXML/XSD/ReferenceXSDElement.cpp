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
        if ( nom.compare(elem->getNom()) == 0)
        {
            trouve = true;
            leBon = elem;
            break;
        }
        if (typeid(elem) == typeid(ComplexXSDElement))
        {
            /*  cast obligatoire pour pouvoir parcourir l interieur des types complexes */
            list<XSDElement*>* tmp =reinterpret_cast<ComplexXSDElement*>(elem)->getComplexType()->getxSDElements();
            /*
            for (XSDElement* elem : tmp)
            {
                 if ( nom.compare(elem->getNom()) == 0)
                {
                    trouve = true;
                    leBon = souselem;
                    break;
                }
            }
            */
        }
        if (trouve)
        {
            break;
        }
    }

    if (trouve)
    {
        int maxOccurs = -1;
        /* chercher le nombre d occurences max de la reference */
        for (XSDAttribut* att : *atts)
        {         
            if (att->getNom().compare("maxOccurs")==0)
            {
                std::string value = att ->getValeur();
                /* c'esstt deeggueulaasse */
                maxOccurs = atoi(value.c_str());
                break;   
            }
        }
        /* autant de regex que de maxoccurs */
        for (int i =0; i < maxOccurs; i++)
        {
            res += "^?(" + leBon->expr(elems) + ")?$?";
        }
    }
    else
    {
        res += " erreur : reference vers un element inconnu : " + nom + "\n" ;
    }

    return res;
}
