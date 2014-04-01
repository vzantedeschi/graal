%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#include "commun.h"
#include "structXSD.h"

extern char xsdtext[];

int xsdlex(void);  

void xsderror(XSDDocument ** d,const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
   char * s;
   XSDDocument * doc;
   XSDProlog * p;
   XSDElement * e;
   list<XSDElement*> * le;
   XSDAttribut * a;
   list<XSDAttribut*> * la;
   XSDDeclaration * dtd;
   SimpleXSDElement * se;
   ComplexXSDElement * ce;
   Schema * sche;
   Choice * cho;
   Sequence * seq;
   list<XSDComment*> * lcom;
   ComplexType * ctype;
}

%token EGAL SLASH SUP SUPSPECIAL INFSPECIAL INF SCHEMA ELEMENT COMPLEXTYPE CHOICE SEQUENCE NAME REF
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
%type <s> nom
%type <ctype> complexType


%parse-param{XSDDocument ** d}
%%

main 
 : document {*d = $1;}
 ;

document
 : prolog schema comments {
         $$ = new XSDDocument($1, $2, $3);}
 ;

schema
 : INF SCHEMA attributes SUP
   elements
   INF SLASH SCHEMA SUP {
         $$ = new Schema($3, $5);}
 | INF SCHEMA attributes SLASH SUP {
         $$ = new Schema($3, NULL);}              
 ;

elements
 : elements element {
         $$ = $1;
         $$->push_back($2);}
 | element {
         $$ = new list<XSDElement*>(1,$1);}            
 ;

element
 : complexElement {
         $$ = $1;}
 | simpleElement {
         $$ = $1;}           
 ;

complexElement
 : INF ELEMENT nom attributes SUP
   INF COMPLEXTYPE SUP complexType INF SLASH COMPLEXTYPE SUP
   INF SLASH ELEMENT SUP {
         $$ = new ComplexXSDElement($3,$4,$9);}
 ;

simpleElement
 : INF ELEMENT nom attributes SLASH SUP {
         $$ = new SimpleXSDElement($3,$4);}
 | INF ELEMENT ref attributes SLASH SUP {
         $$ = new ReferenceXSDElement($3,$4);}
 ;

complexType
 : choice {
         $$ = $1;}
 | sequence {
         $$ = $1;}             
 ;

choice
 : INF CHOICE SUP
   elements
   INF SLASH CHOICE SUP {
         $$ = new Choice($4);}
 ;

sequence
 : INF SEQUENCE SUP
   elements
   INF SLASH SEQUENCE SUP  {
         $$ = new Sequence($4);}
 ;

attributes
 : attributes attribute {
         $$ = $1;
         $$->push_back($2);}
 | /*vide*/ {
         $$ = new list<XSDAttribut *>();}
 ;

/* attribute : attribut quelconque */
attribute
 : NOM EGAL VALEUR {
         $$ = new XSDAttribut($1, $3);}
 ;

/* nom : attribut de nom 'name' */
nom
 : NAME EGAL VALEUR {
         $$ = $3;}
;

ref
 : REF EGAL VALEUR {
         $$ = $3;}
 ;

prolog
 : doctypedecl comments {
         $$ = new XSDProlog($1,$2);}
 | comments {
         $$ = new XSDProlog(NULL,$1);}
 ; 

doctypedecl
 : INFSPECIAL NOM attribute attribute SUPSPECIAL {
         $$ = new XSDDeclaration($3, $4);}
 ;

comments
 : comments COMMENT {
         $$ = $1;
         $$->push_back(new XSDComment($2));}
 | /*vide*/ {
         $$ = new list<XSDComment *>();}
 ;
