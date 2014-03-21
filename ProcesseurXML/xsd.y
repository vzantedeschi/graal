%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#include "commun.h"

extern char xsdtext[];

int xsdlex(void);  

void xsderror(const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
   char * s;
}

%token EGAL SLASH SUP SUPSPECIAL COLON INFSPECIAL INF SCHEMA ELEMENT COMPLEXTYPE CHOICE SEQUENCE
%token <s> VALEUR COMMENT NOM

%%

document
 : prolog schema miscs
 ;

schema
 : INF SCHEMA attributes SUP
   elements
   INF SLASH SCHEMA SUP
 | INF SCHEMA attributes SLASH SUP               
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
 : xsddecl miscs
 | miscs
 ; 

xsddecl
 : INFSPECIAL NOM attributes SUPSPECIAL
 ;

miscs
 : miscs COMMENT
 | /*vide*/
 ;