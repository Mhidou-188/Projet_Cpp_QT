#ifndef CLIENT_PARTICULIER_H
#define CLIENT_PARTICULIER_H

#include "Client.h"

struct DateNaissance

{
    int jj;
    int mm;
    int aa;

};

typedef struct DateNaissance DN;




class Client_particulier : public Client
{
    public:
        Client_particulier(int, string,ADP,string,DN,string,char);
        virtual ~Client_particulier();

        DN GetDateNaissance()
        {
            return DateNaissance;
        }

        void SetDateNaissance(DN val)

        { if ((val.jj==0)||(val.jj>31)|| (val.mm==0)||(val.mm>12))

        {
            Tostring_Msg_erreur_Date();
        }

            else

            DateNaissance = val;




        }

        string GetPrenom() { return Prenom; }

        void SetPrenom(string ch)

        {   if ( ch.size()<=50)

            {ch[0]=toupper(ch[0]);

            Prenom =  ch;
            }

            else

                Tostring_Msg_erreur_Prenom();



        }

        char Getsexe() { return sexe; }

    void Setsexe(char val)
    {
        if ((val=='F') || (val=='M'))
                sexe = val;

                else

                    Tostring_Msg_erreur_sexe();
        }

        string Tostring_Msg_erreur_Prenom();
        string Tostring_Msg_erreur_Date();
        string Tostring_Msg_erreur_sexe();
        string Tostring_Prst_Client_Particulier();


    protected:

    private:
        DN DateNaissance;
        string Prenom;
        char sexe;
};

#endif // CLIENT_PARTICULIER_H
