%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "commun.h"
#include "struct.h"

extern char xmltext[];

int xmllex(void);

void xmlerror(Document ** d,const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
	char * s;
	Document * doc;
	Prolog * p;
	Element * e;
	Misc * m;
	list<Misc *> * lm;
	Attribut * a;
	list<Attribut *> * la;
	list<ContentItem *> * lci;
	CDSect * cds;
	DocTypeDecl * dtd;
	PI * pi;
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND XSL
%type <doc> document
%type <e> element
%type <p> prolog
%type <m> misc
%type <lm> miscs
%type <a> attribute
%type <la> attributes
%type <lci> content
%type <cds> cdsect
%type <dtd> doctypedecl
%type <pi> pi xmldecl



%parse-param{Document ** d}
%%


main 
 : document	{*d = $1;}
 ;

document
 : prolog element miscs {
$$ = new Document($1, $2, $3);}
 ;

element
 : INF NOM attributes SUP
   content
   INF SLASH NOM SUP	{ cout << "Balise HTML" << endl;
			if(strcmp($2,$8)){
				cout << $2 << "," << $8 <<" : le tag de debut ne correspond pas au tag de fin" << endl;}
			$$ = new NonEmptyElement($2, $3, $5);	
				}
 | INF XSL COLON NOM attributes SUP
   content
   INF SLASH XSL COLON NOM SUP { cout << "Balise XSL bloc" << endl;
                        // Test des "xsl:" manquant
			if(strcmp($4,$11)){
				cout << $4 << "," << $12 <<" : le tag de debut ne correspond pas au tag de fin" << endl;}
			$$ = new NonEmptyElement($4, $5, $7);	
				}
 | INF XSL COLON NOM attributes SLASH SUP	{ cout << "Balise XSL auto-fermante" << endl;
			$$ = new EmptyElement($4, $5);}            
 ;

content
 : content element	{
			$$->push_back($2);}
 | content cdsect	{
			$$->push_back($2);}
 | content misc		{
			$$->push_back($2);}   
 | content DONNEES	{
			$$->push_back(new Donnees($2));}
 | /* vide */     	{
			$$ = new list<ContentItem *>();}         
 ;


attributes
 : attributes attribute {
			$$ = $1;
			$$->push_back($2);}
 | /*vide*/ {
			$$ = new list<Attribut *>();}
 ;

attribute
 : NOM EGAL VALEUR {
			$$ = new Attribut($1, $3);}
 | NOM COLON NOM EGAL VALEUR
 ;

doctypedecl
 : DOCTYPE NOM NOM SUP {
			$$ = new DocTypeDecl($2, $3);}
 | DOCTYPE NOM SUP {
			$$ = new DocTypeDecl($2, " ");}

 ;

prolog
 : xmldecl miscs doctypedecl miscs	{
				$$ = new Prolog($1, $3, $2, $4);}
// | miscs doctypedecl miscs  /** Ces lignes sont commentées parce qu'elles créent un conflit décalage/réduction avec la règle 0 : ".document" à la lecture du symbole INFSPECIAL (voir xml.output)
 | xmldecl miscs	{
				$$ = new Prolog($1, NULL, $2, NULL);}	
// | miscs
 ;

xmldecl
 : INFSPECIAL NOM attributes SUPSPECIAL	{
			$$ = new PI($2, $3);}
 ;

miscs
 : miscs misc {
$$ = $1;
$$->push_back($2);}
 | /*vide*/ {
$$ = new list<Misc *>();}
 ;

misc
 : COMMENT {
$$ = new Comment($1);}
 | pi {
$$ = $1;}
 ;

pi
 : INFSPECIAL NOM attributes SUPSPECIAL {
$$ = new PI($2, $3);}
 ;

cdsect
 : CDATABEGIN CDATAEND {
$$ = new CDSect($2);}
 ;