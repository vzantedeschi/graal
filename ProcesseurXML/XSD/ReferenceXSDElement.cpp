#include "ReferenceXSDElement.h"
#include "ComplexXSDElement.h"

//class SimpleXSDElement
ReferenceXSDElement::ReferenceXSDElement(string nom, list<XSDAttribut*>* atts) : XSDElement(nom, atts) {}
string ReferenceXSDElement::expr(list<XSDElement*>* elems){
    string res = "";
    bool trouve = false;
    XSDElement* leBon;
    for (XSDElement* elem :*elems)
    {
        if ( strcmp(nom, elem->nom) == 0)
        {
            trouve = true;
            leBon = elem;
            break;
        }
        if (typeid(elem) == typeid(ComplexXSDElement))
        {
            for (XSDElement* souselem : elem->complexType->XSDElements)
            {
                 if ( strcmp(nom, elem->nom) == 0)
                {
                    trouve = true;
                    leBon = souselem;
                    break;
                }
            }
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
            if (strcmp(att->getNom(), "maxOccurs")==0)
            {
                std::string value = att ->getValue();
                maxOccurs = atoi(value);
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
