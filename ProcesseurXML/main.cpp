#include "commun.h"
#include "struct.h"
#include "structXSD.h"
#include <iostream>
#include <cstring>

using namespace std;

extern FILE* xmlin;
extern FILE* xsdin;

int xmlparse(Document **);
int xsdparse(XSDDocument **);

int main(int argc, char *argv[])
{
	Document * xmlD;
    XSDDocument * xsdD;
    if (((strcmp(argv[1],"-p") == 0) || (strcmp(argv[1],"-v") == 0)) && argc > 2)
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

		   return 0;
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

   return 1;
}
