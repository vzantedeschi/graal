#define DEBUG

#include "commun.h"
#include "structXSL.h"
#include "struct.h"
#include "structXSD.h"
#include <iostream>
#include <cstring>
#include <string>
#include <regex>

using namespace std;

extern FILE* xmlin;
extern FILE* xsdin;
extern FILE* xslin;

int xmlparse(Document **);
int xslparse(XSLDocument **);
int xsdparse(XSDDocument **);
int xmllex_destroy(void);
int xsdlex_destroy(void);
int xsllex_destroy(void);

int main(int argc, char *argv[])
{
    Document * xmlD;
    XSDDocument * xsdD;
    XSLDocument * xslD;

    bool xmlCreated = false;
    bool xsdCreated = false;
    bool xslCreated = false;

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
            //retour = -1;
            retour = xmlparse(&xmlD);

            /* ------> continuer analyse et affichage ----*/
            if (!retour)
            {
                xmlCreated = true;
#ifdef DEBUG
                cout<<"Entrée standard reconnue"<<endl;
#endif
                cout << "\n" << *xmlD;
#ifdef DEBUG
#endif
            }
            else
            {
                cerr<<"No root markup"<<endl;
                return 1;
            }

            fclose(fid);
            xmllex_destroy();

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
                    xsdCreated = true;
#ifdef DEBUG
                    cout<<"Entrée standard XSD reconnue"<<endl;
#endif
                    string exp = xsdD->expr();
#ifdef DEBUG
                    cout << exp <<endl;
#endif

                    try
                    {
                        regex e (exp);
#ifdef DEBUG
                        cout << "regex creee" <<endl;
#endif
                        std::ostringstream stream;
                        stream << *xmlD;
                        string str =  stream.str();
#ifdef DEBUG
                        cout << "stream cree" <<endl;
#endif
                        if (regex_match (str,e))
                        {
                            cout << "xml and xsd match" << endl;
                        }
                        else
                        {
                            cout << "xml and xsd don t match" << endl;
                        }
                    }catch(regex_error exe){
                        if (exe.code() == std::regex_constants::error_badrepeat)
                            cerr << "error_badrepeat : The expression contained a repeat specifier (one of *?+{) that was not preceded by a valid regular expression." << endl;
                        if (exe.code() == std::regex_constants::error_space)
                            cerr << "error_space : There was insufficient memory to convert the expression into a finite state machine." << endl;
                        if (exe.code() == std::regex_constants::error_stack)
                            cerr << "error_stack : There was insufficient memory to determine whether the regular expression could match the specified character sequence." << endl;
                        if (exe.code() == std::regex_constants::error_complexity)
                            cerr << "error_complexity :The complexity of an attempted match against a regular expression exceeded a pre-set level." << endl;
                        if (exe.code() == std::regex_constants::error_range)
                            cerr << "error_range : The expression contained an invalid character range." << endl;
                        if (exe.code() == std::regex_constants::error_badbrace)
                            cerr << "error_badbrace : The expression contained an invalid range between braces ({ and })." << endl;
                        if (exe.code() == std::regex_constants::error_brace)
                            cerr << "error_brace : The expression contained mismatched braces ({ and })." << endl;
                        if (exe.code() == std::regex_constants::error_paren)
                            cerr << "error_paren The expression contained mismatched parentheses (( and ))." << endl;
                        if (exe.code() == std::regex_constants::error_brack)
                            cerr << "error_brack : The expression contained mismatched brackets ([ and ])." << endl;
                        if (exe.code() == std::regex_constants::error_backref)
                            cerr << "error_backref : The expression contained an invalid back reference." << endl;
                        if (exe.code() == std::regex_constants::error_escape)
                            cerr << "error_escape : The expression contained an invalid escaped character, or a trailing escape." << endl;
                        if (exe.code() == std::regex_constants::error_ctype)
                            cerr << "error_ctype The expression contained an invalid character class name." << endl;
                        if (exe.code() == std::regex_constants::error_collate)
                            cerr << "error_collate : The expression contained an invalid collating element name." << endl;
                        return 1;
                    }


                }
                else
                {
                    cout<<"Entrée standard XSD non reconnue"<<endl;
                }
                fclose(fid);
                xsdlex_destroy();
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
#ifdef DEBUG
                    cout<<"Fichier XSL Ouvert"<<endl;
#endif
                }

                xslin = fid;
                retour = xslparse(&xslD);

                /* ------> continuer analyse et affichage ----*/

                if (!retour)
                {
                    xslCreated = true;
#ifdef DEBUG
                    cout<<"Entrée standard XSL reconnue"<<endl;
#endif
                    xslD->afficherHTML(&xmlD);
                    //xslD->afficherHTML();
                }
                else
                {
                    cout<<"Entrée standard XSL non reconnue"<<endl;
                    return 1;
                }
                fclose(fid);
                xsllex_destroy();
            }

            if(xmlCreated){ //liberer la memoire
                delete xmlD;
            }
            if(xslCreated){ //liberer la memoire
                delete xslD;
            }
            if(xsdCreated){ //liberer la memoire
                delete xsdD;
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

    return 0;
}
