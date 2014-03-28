#include "commun.h"
#include "structXSL.h"
#include "struct.h"
#include "structXSD.h"
#include <iostream>
#include <cstring>

using namespace std;

extern FILE* xmlin;
extern FILE* xsdin;
extern FILE* xslin;

int xmlparse(Document **);
int xslparse(XSLDocument **);
int xsdparse(XSDDocument **);

int main(int argc, char *argv[])
{
	Document * xmlD;
	XSDDocument * xsdD;
	XSLDocument * xslD;
    if ((strcmp(argv[1],"-p") == 0) || (strcmp(argv[1],"-v") == 0) || (strcmp(argv[1],"-t") == 0)&& argc > 2)

    {/* ---- si option reconnue ---*/
        FILE * fid;
        const char* nomfichier = argv[2];
        int retour;
        //printf("%s \n",nomfichier);

        fid = fopen(nomfichier,"r");

        if (!fid)
        {
            printf("ERREUR : NOM FICHIER ERRONE\n");
            /*gestion d'erreur*/

            return 1;
        }
        else
        {
            //cout<<"Fichier Ouvert"<<endl;
        }

        // option -p
        xmlin = fid;
        retour = xmlparse(&xmlD);
        /* ------> continuer analyse et affichage ----*/
        if (!retour)
        {
           //cout<<"Entrée standard reconnue"<<endl;
           cout << "\n" << *xmlD;
        }
        else
        {
           cout<<"Entrée standard non reconnue"<<endl;
        }
        fclose(fid);
        //option -v
        if(strcmp(argv[1],"-v") == 0 && argc == 4)
        {
            //récupération fichier xsd
            const char* nomfichier = argv[2];
            int retour;
            printf("%s \n",nomfichier);

            fid = fopen(nomfichier,"r");

            if (!fid)
            {
                printf("ERREUR : NOM FICHIER XSD ERRONE\n");
                /*gestion d'erreur*/

                return 1;
            }
            else
            {
                cout<<"Fichier Xsd Ouvert"<<endl;
            }

            xsdin = fid;
            retour = xsdparse(&xsdD);

            /* ------> continuer analyse et affichage ----*/

            if (!retour)
            {
               cout<<"Entrée standard reconnue"<<endl;
            }
            else
            {
               cout<<"Entrée standard non reconnue"<<endl;
            }
            fclose(fid);
        }
	else if(strcmp(argv[1],"-t") == 0 && argc == 4)
        {
            //xsdin = fid;
            //retour = xsdparse(&d);
            const char* nomfichier = argv[3];
            int retour;
            printf("%s \n",nomfichier);

            fid = fopen(nomfichier,"r");

	    if (!fid)
            {
                printf("ERREUR : NOM FICHIER XSL ERRONE\n");
                /*gestion d'erreur*/

                return 1;
            }
            else
            {
                cout<<"Fichier xsl Ouvert"<<endl;
            }

	    xslin = fid;
            retour = xslparse(&xslD);
	    printf("BIG SOUCYYYY");

            /* ------> continuer analyse et affichage ----*/

            if (!retour)
            {
               cout<<"Entrée standard reconnue"<<endl;
            }
            else
            {
               cout<<"Entrée standard non reconnue"<<endl;
            }
        }

        fclose(fid);
    }/* --- fin si option reconnue ---*/
    else
    {
        cout<<"Option non reconnue"<<endl;

        int retour = xmlparse(&xmlD);

        if (!retour)
        {
           cout<<"Entrée standard reconnue"<<endl;
        }
        else
        {
           cout<<"Entrée standard non reconnue"<<endl;
        }
    }

   return 0;
}
