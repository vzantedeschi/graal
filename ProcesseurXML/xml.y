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
%type <pi> pi

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
   INF SLASH NOM SUP	
   		{
			if(strcmp($2,$8)){
				cerr << "Non matching element names " << $2 << " and " << $8 << endl;
			}
			$$ = new NonEmptyElement($2, $3, $5);	
		}
 | INF NOM COLON NOM attributes SUP
   content
   INF SLASH NOM COLON NOM SUP 
   		{
			if(strcmp($2,$10)){
				cerr << "Non matching element namespaces " << $2 << " and "<< $10 <<endl;
			}
			if(strcmp($4,$12)){
				cerr << "Non matching element names " << $4 << " and "<< $12 <<endl;
			}
   			strcat($2,":");
   			strcat($2, $4);
   			$$ = new NonEmptyElement($2, $5, $7);
   		}

 | INF NOM attributes SLASH SUP	{
			$$ = new EmptyElement($2, $3);}   
 | INF NOM COLON NOM attributes SLASH SUP	{
 			strcat($2,":");
   			strcat($2, $4);
			$$ = new EmptyElement($2, $5);} 
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
 | NOM COLON NOM EGAL VALEUR {
			strcat($1,":");
			strcat($1, $3);
			$$ = new Attribut($1, $5);}
 ;

doctypedecl
 : DOCTYPE NOM NOM SUP {
			$$ = new DocTypeDecl($2, $3);}
 | DOCTYPE NOM NOM VALEUR SUP {
			$$ = new DocTypeDecl($2, $3);}
 | DOCTYPE NOM SUP {
			$$ = new DocTypeDecl($2, " ");}

 ;

prolog
 : //xmldecl miscs doctypedecl miscs	{
				//$$ = new Prolog($1, $3, $2, $4);}
 miscs doctypedecl miscs {
 	$$ = new Prolog($2, $1, $3);}
/** Ces lignes sont commentées parce qu'elles créent un conflit décalage/réduction avec la règle 0 : ".document" à la lecture du symbole INFSPECIAL (voir xml.output)**/
 //| xmldecl miscs	{
				//$$ = new Prolog($1, NULL, $2, NULL);}	
 | miscs {
 	$$ = new Prolog(NULL, $1, NULL);}
 ;

/*xmldecl
 : INFSPECIAL NOM attributes SUPSPECIAL	{
			$$ = new PI($2, $3);}
 ;*/

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
