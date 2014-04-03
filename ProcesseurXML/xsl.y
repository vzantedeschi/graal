%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "commun.h"
#include "structXSL.h"

extern char xmltext[];

int xsllex(void);

void xslerror(XSLDocument ** d,const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
	char * s;
	XSLDocument * doc;
	XSLElement * elemxsl;
	list<XSLElement *> * lelemxsl;

//	XSLProlog * pro;
//	XSLMisc * m;
//	list<XSLMisc *> * lm;

	XSLAttribut * a;
	list<XSLAttribut *> * la;

//	list<XSLContentItem *> * lci;
//	XSLCDSect * cds;
//	XSLDocTypeDecl * dtd;
//	XSLPI * pi;

	XSLDeclaration * xsld;
	XSLCatalogue * cat;
	XSLTemplate * t;
	list<XSLTemplate *> * lt;
}

%token EGAL COLON SLASH SUP SUPSPECIAL INFSPECIAL INF XSL STYLESHEET TEMPLATE VALUEOF FOREACH APPLY
%token <s> VALEUR COMMENT NOM DONNEES

%type <doc> document
%type <elemxsl> element
%type <lelemxsl> elements

//%type <pro> prolog
//%type <m> misc
//%type <lm> miscs

%type <a> attribute
%type <la> attributes

//%type <lci> content
//%type <cds> cdsect
//%type <dtd> doctypedecl
//%type <pi> pi xmldecl

%type <xsld> xsldecl
%type <cat> catalogue
%type <t> template
%type <lt> templates



%parse-param{XSLDocument ** d}
%%


main 
 : document	{*d = $1;}
 ;

document
 : xsldecl catalogue {
$$ = new XSLDocument($1, $2);}
 ;

catalogue
 : INF STYLESHEET attributes SUP
   templates
   INF SLASH STYLESHEET SUP { $$ = new XSLCatalogue($3,$5);} // Créer des templates
 ;

templates
 : templates template {
         $$ = $1;
         $$->push_back($2);}
 | template {
         $$ = new list<XSLTemplate*>(1,$1);}            
 ;

elements
 : elements element {
         $$ = $1;
         $$->push_back($2);}
 | element {
         $$ = new list<XSLElement*>(1,$1);}            
 ;

template
 : INF TEMPLATE attributes SUP
   elements
   INF SLASH TEMPLATE SUP	{ 
			$$ = new XSLTemplate($3, $5);	
				}           
 ;

element
 : INF APPLY attributes SLASH SUP { 
			$$ = new XSLApply("apply",$3,NULL);
				}
 | INF APPLY SLASH SUP { 
			$$ = new XSLApply("apply",NULL,NULL);
				}
 | INF VALUEOF attributes SLASH SUP { 
			$$ = new XSLValue("value",$3,NULL);
				}
 | INF FOREACH attributes SUP
   elements
   INF SLASH FOREACH SUP { 
			$$ = new XSLForeach("foreach",$3,$5);
				}
 | INF NOM attributes SUP
   elements
   INF SLASH NOM SUP	{ 
			if(strcmp($2,$8)){
				cout << $2 << "," << $8 <<" : le tag de debut ne correspond pas au tag de fin" << endl;}
			$$ = new XSLElementHTML($2, $3, $5);
			free($2);
			free($8);
				}
 | INF NOM attributes SLASH SUP		{ 
					$$ = new XSLElementHTML($2,$3,NULL);
					free($2);
					}
 | DONNEES         {
			$$ = new XSLContent($1,NULL,NULL);
			free($1);
			}
 ;

attributes
 : attributes attribute {
			$$ = $1;
			$$->push_back($2);}
 | /*vide*/ {
			$$ = new list<XSLAttribut *>();}
 ;

attribute
 : NOM EGAL VALEUR {
			$$ = new XSLAttribut($1, $3);
			free($1);
			free($3);}
 | NOM COLON NOM EGAL VALEUR {
			$$ = new XSLAttribut($3, $5);
			free($1);
			free($3);
			free($5);}
 ;

xsldecl
 : INFSPECIAL NOM attributes SUPSPECIAL	{
			$$ = new XSLDeclaration($3);
			free($2);}
 ;
