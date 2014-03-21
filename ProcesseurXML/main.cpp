#include "commun.h"
#include <iostream>
#include <cstring>

using namespace std;
extern FILE* xmlin;

int xmlparse(void);

int main(int argc, char *argv[])
{
    if (strcmp(argv[1],"-p") == 0)
    {
        FILE * fid;
        const char* nomfichier = argv[2];
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

        xmlin = fid;

        int retour = xmlparse();

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
    else
    {
	    cout<<"Option non reconnue"<<endl;

        int retour = xmlparse();

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
