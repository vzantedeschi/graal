#include "NonEmptyElement.h"
#include <iterator>

NonEmptyElement::NonEmptyElement(string nom, list<Attribut *>* atts, list<ContentItem *>* content) : 
    Element(nom, atts), content(content) {}

void NonEmptyElement::matchPath(list<ContentItem*>* liste,string path)
{
    string t = path.substr(0, path.find('/'));
    if (t != "")
    {
        for(list<ContentItem *>::iterator it = this->content->begin(); it != this->content->end(); it++){
            if((*it)->getNom() == t)
            {
                path = path.substr(path.find('/')+1);
                return (*it)->matchPath(liste,path);
            }
        }
    }
    liste->push_back(this);
}


//ostream& operator << (ostream& os, const NonEmptyElement& NE){
void NonEmptyElement::print(ostream& os) const {
    os << "<" << this->nom;
    for(list<Attribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++){
        os << " " << **it;
    }
    os << ">\n";
    for(list<ContentItem *>::iterator it = this->content->begin(); it != this->content->end(); it++){
        os << **it;
    }
    os << "</" << this->nom << ">\n";
}

string NonEmptyElement::printElem() {
    string res = "", tmp = "";
    bool aEviter = false;

    res += "<" + nom + ">";
//    for(list<Attribut *>::iterator it = atts->begin(); it != atts->end(); it++){
//        if (*it != NULL){ tmp += " " + (*it)->printElem();}
//        if ((*it)->isTheOne()){
//            aEviter = true;
//            break;
//        }
    //}
    //if(aEviter){
        // on ne traite pas la balise qui va chercher le xsd
//        tmp = "";
    //}
    //else
    //{
    //}
    for(list<ContentItem *>::iterator it = content->begin(); it != content->end(); it++){
        if (*it != NULL){ res += (*it)->printElem();}
    }
    if(!aEviter){
        res += "</" + nom + ">";
    }
    return res;
}

NonEmptyElement::~NonEmptyElement()
{	
    for(list<ContentItem *>::iterator it = content->begin(); it != content->end(); it++){
        delete *it;
    }
    delete content;
}

list<ContentItem *>* NonEmptyElement::getContent()
{
    return content;
}

string NonEmptyElement::getNom()
{
    return nom;
}

void NonEmptyElement::printDonnees()
{
	for(list<ContentItem *>::iterator it = this->content->begin(); it != this->content->end(); it++){
		(*it)->printDonnees();
	}
}
