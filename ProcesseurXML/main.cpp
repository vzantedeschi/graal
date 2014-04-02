#define DEBUG

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
    //if(argc <= 1)
    // {/* ---- si pas d'argument ---*/
    //     cerr << "No argument given" << endl;
    //     cerr << "Available commands are:" << endl;
    //     cerr << "../xmltool -p file.xml : parse and display the xml file" << endl;
    //     cerr << "../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result" << endl;
    //     cerr << "../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl" << endl;
    //     cerr << "../xmltool -h : displays this help" << endl;

    //     return 1;
    // }/* --- fin si pas d'argument ---*/
    if (argc >= 2)
    {
        if ((strcmp(argv[1],"-p") == 0 && argc > 2) 
             || ((strcmp(argv[1],"-v") == 0 || strcmp(argv[1],"-t") == 0) && argc == 4))
        {/* ---- si option reconnue ---*/
            FILE * fid;
            const char* nomfichier = argv[2];
            int retour;
            #ifdef DEBUG
            printf("%s \n",nomfichier);
            #endif

            fid = fopen(nomfichier,"r");

            if (!fid)
            {
                cerr << "Unable to open " << nomfichier << endl;
                /*gestion d'erreur*/

                return 1;
            }
            else
            {
                #ifdef DEBUG
                cout<<"Fichier XML Ouvert"<<endl;
                #endif
            }

            // option -p
            xmlin = fid;
            retour = -1;
            retour = xmlparse(&xmlD);
            /* ------> continuer analyse et affichage ----*/
            if (!retour)
            {
               #ifdef DEBUG
               cout<<"Entrée standard reconnue"<<endl;
               #endif
               //cout << "\n" << *xmlD;
               #ifdef DEBUG
               #endif
            }
            else
            {
               cerr<<"No root markup"<<endl;
               return 1;
            }
            if(xmlD != NULL){ //liberer la memoire
            	delete xmlD;
            }
            fclose(fid);
            //option -v
            if(strcmp(argv[1],"-v") == 0)
            {
                //récupération fichier xsd
                const char* nomfichier = argv[3];
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
                    cout<<"Fichier XSD Ouvert"<<endl;
                }

                xsdin = fid;
                retour = xsdparse(&xsdD);

                /* ------> continuer analyse et affichage ----*/

                if (!retour)
                {
                   cout<<"Entrée standard XSD reconnue"<<endl;
                   cout << xsdD->expr();
                }
                else
                {
                   cout<<"Entrée standard XSD non reconnue"<<endl;
                }
                fclose(fid);
            }
    	    else if(strcmp(argv[1],"-t") == 0)
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
                    cout<<"Fichier XSL Ouvert"<<endl;
                }

    	        xslin = fid;
                retour = xslparse(&xslD);

                /* ------> continuer analyse et affichage ----*/

                if (!retour)
                {
                    cout<<"Entrée standard XSL reconnue"<<endl;
		    cout << xslD->afficherHTML();
                }
                else
                {
                   cout<<"Entrée standard XSL non reconnue"<<endl;
                   return 1;
                }
                fclose(fid);
            }

        }/* --- fin si option reconnue ---*/
        else if(strcmp(argv[1],"-p") == 0){
            cerr << "You must provide an argument to the command -p" << endl;
            return 1;
        }
        else if(strcmp(argv[1],"-v") == 0){
            cerr << "You must provide two arguments to the command -v: an xml file and an xsd file" << endl;
            return 1;
        } 
        else if(strcmp(argv[1],"-t") == 0){
            cerr << "You must provide two arguments to the command -t: an xml file and an xsl file" << endl;
            return 1;
        }
    }
    if(argc <= 1 || (strcmp(argv[1],"-p") && strcmp(argv[1],"-v") && strcmp(argv[1],"-t")))
    {/* ---- si pas d'argument ---*/
        if(argc <=1)
        {
            cerr << "No argument given" << endl;
        }
        else if(strcmp(argv[1],"-h"))
        {
            cerr << "Wrong argument given" << endl;
        }
        cerr << "Available commands are:" << endl;
        cerr << "../xmltool -p file.xml : parse and display the xml file" << endl;
        cerr << "../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result" << endl;
        cerr << "../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl" << endl;
        cerr << "../xmltool -h : displays this help" << endl;

        return 1;
    }/* --- fin si pas d'argument ---*/
    /*else
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
    }*/

   return 0;
}
