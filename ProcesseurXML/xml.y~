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
 : prolog element miscs {printf("Lecture de fichier");}
 ;

element
 : INF NOM attributes SUP content INF SLASH NOM SUP
 | INF NOM attributes SLASH SUP               
 ;

content
 : content element
 | content cdsect
 | content pi
 | content COMMENT 
 | content DONNEES         
 | /* vide */              
 ;


attributes
 : attributes attribute
 | /*vide*/
 ;

attribute
 : NOM EGAL VALEUR
 ;

doctypedecl 
 : DOCTYPE NOM NOM SUP
 | DOCTYPE NOM SUP
 ;

prolog
 : xmldecl miscs doctypedecl miscs
// | miscs doctypedecl miscs  /** Ces lignes sont commentées parce qu'elles créent un conflit décalage/réduction avec la règle 0 : ".document" à la lecture du symbole INSPECIAL (voir xml.output)
 | xmldecl miscs
// | miscs
 ; 

xmldecl
 : INFSPECIAL NOM attributes SUPSPECIAL
 ;

miscs
 : miscs misc
 | /*vide*/
 ;

misc
 : COMMENT
 | pi
 ;

pi
 : INFSPECIAL NOM attributes SUPSPECIAL
 ;

//versioninfo
// : DONNEES EGAL DONNEES
// ;

cdsect
 : CDATABEGIN DONNEES CDATAEND
 ;
