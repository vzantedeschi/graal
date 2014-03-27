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
   list<Element*> * le;
   Attribut * a;
   list<Attribut*> * la;
   DocTypeDecl * dtd;
   SimpleElement * se;
   ComplexElement * ce;
   Schema * sche;
   Choice * cho;
   Sequence * seq;
   list<Comment*> * lcom;
}

%token EGAL SLASH SUP SUPSPECIAL INFSPECIAL INF SCHEMA ELEMENT COMPLEXTYPE CHOICE SEQUENCE NAME
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
         $$ = new list<Element*>(1,$1);}            
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
         $$ = new ComplexElement($3,$4,$8);}
 ;

simpleElement
 : INF ELEMENT nom attributes SLASH SUP {
         $$ = new SimpleElement($3,$4);}
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
   INF CHOICE SLASH SUP {
         $$ = new Choice($4);}
 ;

sequence
 : INF SEQUENCE SUP
   elements
   INF SEQUENCE SLASH SUP  {
         $$ = new Sequence($4);}
 ;

attributes
 : attributes attribute {
         $$ = $1;
         $$->push_back($2);}
 | /*vide*/ {
         $$ = new list<Attribut *>();}
 ;

/* attribute : attribut quelconque */
attribute
 : NOM EGAL VALEUR {
         $$ = new Attribut($1, $3);}
 ;

/* nom : attribut de nom 'name' */
nom
 : NAME EGAL VALEUR {
         $$ = $3;}
 ;

prolog
 : xsddecl comments {
         $$ = new Prolog($1,$2);}
 | comments {
         $$ = new Prolog(NULL,$2);}
 ; 

xsddecl
 : INFSPECIAL NOM attribute attribute SUPSPECIAL {
         $$ = new XSDDeclaration($3, $4);}
 ;

comments
 : comments COMMENT {
         $$ = $1;
         $$->push_back(new Comment($2));}
 | /*vide*/ {
         $$ = new list<Comment *>();}
 ;