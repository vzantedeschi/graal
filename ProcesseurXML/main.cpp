#include "commun.h"
#include "../src/structXSL.h"
#include "struct.h"
#include <iostream>
#include <cstring>

using namespace std;
extern FILE* xmlin;
extern FILE* xslin;

int xmlparse(Document **);
int xslparse(XSLDocument **);

int main(int argc, char *argv[])
{
	Document * d;
    if ((strcmp(argv[1],"-p") == 0) || (strcmp(argv[1],"-v") == 0) || (strcmp(argv[1],"-t") == 0))
    {/* ---- si option reconnue ---*/
        FILE * fid;
        const char* nomfichier = argv[2];
        int retour;
        printf("%s \n",nomfichier);

        fid = fopen(nomfichier,"r");

        if (!fid)
        {
            printf("ERREUR : NOM FICHIER ERRONE\n");
            /*gestion d'erreur*/

            return 1;
        }
        else
        {
            cout<<"Fichier Ouvert"<<endl;
        }

        if (strcmp(argv[1],"-p") == 0)
        {
            xmlin = fid;
            retour = xmlparse(&d);
            /* ------> continuer analyse et affichage ----*/
            if (!retour)
            {
               cout<<"Entrée standard reconnue"<<endl;
               cout << "\n" << *d;
            }
            else
            {
               cout<<"Entrée standard non reconnue"<<endl;
            }
        }
        else if(strcmp(argv[1],"-v") == 0)
        {
            //xsdin = fid;
            //retour = xsdparse(&d);
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
	else if(strcmp(argv[1],"-t") == 0)
        {
            xslin = fid;
            //retour = xslparse(&d);
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

        int retour = xmlparse(&d);

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
