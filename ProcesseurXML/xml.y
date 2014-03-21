%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "commun.h"

extern char xmltext[];

int xmllex(void);

void xmlerror(const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
   char * s;
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND

%%
main : document	{*d = $1;}

document
 : prolog element miscs {
$$ = new Document($1, $2, $3);}
 ;

element
 : INF NOM attributes SUP
   content
   INF SLASH NOM SUP	{
			if($2 != $8){
				cout << $2 << "," << $8 <<" : le tag de debut ne correspond pas au tag de fin" << endl;}
			$$ = new NonEmptyElement($2, $3, $5);	
				}
 | INF NOM attributes SLASH SUP	{
			$$ = new EmptyElement($2, $3);}             
 ;

content
 : content element	{
			$$->push_back($2);}
 | content cdsect	{
			$$->push_back($2);}
 | content misc		{
			$$->push_back($2);}   
 | content DONNEES	{
			$$->push_back(new Donnees($2);}
 | /* vide */     	{
			$$ = new list<ContentItem*>();}         
 ;


attributes
 : attributes attribute {
			$$ = $1;
			$$->push_back($2);}
 | /*vide*/ {
			$$ = new list<Attribut*>();}
 ;

attribute
 : NOM EGAL VALEUR {
			$$ = new Attribut($1, $3);}
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
// | miscs doctypedecl miscs  /** Ces lignes sont commentées parce qu'elles créent un conflit décalage/réduction avec la règle 0 : ".document" à la lecture du symbole INSPECIAL (voir xml.output)
 | xmldecl miscs	{
				$$ = new Prolog($1, $2, NULL, NULL);}	
// | miscs
 ;

xmldecl
 : INFSPECIAL NOM attributes SUPSPECIAL	{
			$4->push_front($3);
			$$ = new PI($2, $4);}
 ;

miscs
 : miscs misc {
$$ = $1;
$$->push_back($2);}
 | /*vide*/ {
$$ = new list<Misc*>();}
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
