%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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

document
 : prolog element miscs	{
			$$ = new Document($1, $2, $3);}
 ;

element
 : INF NOM attributes SUP
   content
   INF SLASH NOM SUP
 | INF NOM attributes SLASH SUP               
 ;

content
 : content element	{}
 | content cdsect	{}
 | content misc		{}   
 | content DONNEES	{}
 | /* vide */     	{}         
 ;


attributes
 : attributes attribute	{
				$$ = $1;
				$$->push_back($2);}
 | /*vide*/				{
				$$ = new list<Attribut*>();}
 ;

attribute
 : NOM EGAL VALEUR	{
				$$ = new Attribut($1, $3);}
 ;

doctypedecl 
 : DOCTYPE NOM NOM SUP	{
				$$ = new DocTypeDecl($2, $3);}
 | DOCTYPE NOM SUP		{
				$$ = new DocTypeDecl($2, " ");}

 ;

prolog
 : xmldecl miscs doctypedecl miscs
// | miscs doctypedecl miscs  /** Ces lignes sont commentées parce qu'elles créent un conflit décalage/réduction avec la règle 0 : ".document" à la lecture du symbole INSPECIAL (voir xml.output)
 | xmldecl miscs
// | miscs
 ; 

xmldecl
 : INFSPECIAL NOM attributes SUPSPECIAL	{
			$4->push_front($3);
			$$ = new PI($2, $4);
 ;

miscs
 : miscs misc	{
			$$ = $1;
			$$->push_back($2);}
 | /*vide*/		{
			$$ = new list<Misc*>();}
 ;

misc
 : COMMENT	{
				$$ = new Comment($1);}
 | pi		{
				$$ = $1;}
 ;

pi
 : INFSPECIAL NOM attributes SUPSPECIAL {
				$$ = new PI($2, $3);}
 ;

cdsect
 : CDATABEGIN CDATAEND	{
				$$ = new CDSect($2);}
 ;







