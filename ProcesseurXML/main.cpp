#include "commun.h"
#include <iostream>
#include <cstring>

using namespace std;

int xmlparse(void);

int main(int argc, char *argv[])
{
    printf("hello!\n");
    printf(argv[1]);
    if (argv[1] == "-p")
    {
        FILE * fid;
        const char* nomfichier = argv[2];
        printf(nomfichier);

        fid = fopen(nomfichier,"r");

        if (!fid)
        {
            printf("ERREUR : NOM FICHIER ERRONE\n");
            /*gestion d'erreur*/
        }

        FILE * xmlin = fid;

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

   return 1;
}
