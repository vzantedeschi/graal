%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#include "commun.h"
#include "../src/structXSD.h"

extern char xsdtext[];

int xsdlex(void);  

void xsderror(const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
   char * s;
   Document * doc;
   Prolog * p;
   Element * e;
   list<Element*> le;
   Attribut * a;
   list<Attribut> * la;
   DocTypeDecl * dtd;
   SimpleElement * se;
   ComplexElement * ce;
   Schema * sche;
   Choice * cho;
   Sequence * seq;
   list<Comment*> lcom;
}

%token EGAL SLASH SUP SUPSPECIAL COLON INFSPECIAL INF SCHEMA ELEMENT COMPLEXTYPE CHOICE SEQUENCE
%token <s> VALEUR COMMENT NOM

%type <doc> document
%type <p> prolog
%type <e> element
%type <le> elements
%type <a> attribute
%type <la> attributes
%type <dtd> doctypedecl
%type <se> simpleElement
%type <ce> complexElement
%type <sche> schema
%type <cho> choice
%type <seq> sequence
%type <lcom> comments

%parse-param{Document ** d}
%%

main 
 : document {*d = $1;}
 ;

document
 : prolog schema comments {
$$ = new Document($1, $2, $3);}
 ;

schema
 : INF SCHEMA attributes SUP
   elements
   INF SLASH SCHEMA SUP
 | INF SCHEMA attributes SLASH SUP {
         $$ = new Schema($3, new list<Element*>());}              
 ;

elements
 : elements element
 | element              
 ;

element
 : complexElement
 | simpleElement               
 ;

complexElement
 : INF ELEMENT attributes SUP
   INF COMPLEXTYPE SUP complexType INF SLASH COMPLEXTYPE SUP
   INF SLASH ELEMENT SUP
 ;

simpleElement
 : INF ELEMENT attributes SLASH SUP
 ;

complexType
 : choice
 | sequence             
 ;

choice
 : INF CHOICE SUP
   elements
   INF CHOICE SLASH SUP
 ;

sequence
 : INF SEQUENCE SUP
   elements
   INF SEQUENCE SLASH SUP
 ;

attributes
 : attributes attribute
 | /*vide*/
 ;

attribute
 : NOM EGAL VALEUR
 ;


prolog
 : xsddecl comments
 | comments
 ; 

xsddecl
 : INFSPECIAL NOM attributes SUPSPECIAL
 ;


 : comments COMMENT
 | /*vide*/
 ;