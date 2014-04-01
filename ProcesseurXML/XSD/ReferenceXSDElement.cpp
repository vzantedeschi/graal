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
        /* chercher le nombre d occurences max de la reference */
        
        res += leBon->expr(elems);
    }
    else
    {
        res += " erreur : reference vers un element inconnu : " + nom + "\n" ;
    }

    return res;
}
