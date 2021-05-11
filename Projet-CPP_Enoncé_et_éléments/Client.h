#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include<cstring>
#include <cctype>
#include<algorithm>

using namespace std;


//---Pour le passage de minuscules � majuscules--------------------

struct my_tolower
{
    char operator()(char c) const
    {
        return std::tolower(static_cast<unsigned char>(c));
    }
};

struct my_toupper
{
    char operator()(char c) const
    {
        return std::toupper(static_cast<unsigned char>(c));
    }
};



//---Pour le passage de minuscules � majuscules--------------------


struct AdressePostale

{
    string libelle;
    string complement;
    int codePostal;
    string ville;

};

typedef struct AdressePostale ADP;

ADP Durand_ADP = {"4 Rue top","Appt 23", 79043,"Ailleurs" };

class Client
{
public:
    Client();

    Client (int, string,ADP,string);

    virtual ~Client();

    string Getidentifiant();

    void Setidentifiant( int val)
    {
        if (val<=99999)

        {identifiant = val;}

        else
    {
        identifiant=00000;
       // cout<<endl<<Tostring_Msg_erreur_id();
       cout<<Tostring_Msg_erreur_id();
    }


    }
    string GetNom()
    {
        return Nom;
    }
    void SetNom( string ch)
    {
        if ( ch.size()<=50)
        {
          transform(ch.begin(), ch.end(), ch.begin(), my_toupper());
          Nom = ch;

        }
        else
           cout<< Tostring_Msg_erreur_nom();
    }
    ADP GetAdressePostale()
    {
        return AdPostale;
    }
    void SetAdressePostale( ADP val)
    {
        AdPostale = val;
    }
    string GetMailContact()
    {
        return MailContact;
    }
    void SetMailContact( string mail)
    {
        int n =mail.find ('@');
        if (n!= -1)
        {
            MailContact = mail;
        }

        else
        {
           cout<< Tostring_Msg_erreur_mail();
        }

    }

    virtual string Tostring_Prst_Client();
    string Tostring_Msg_erreur_id();
    string Tostring_Msg_erreur_nom();
    string Tostring_Msg_erreur_mail();




protected:

private:
    int identifiant;
    string Nom;
    ADP AdPostale;
    string MailContact;
};

#endif // CLIENT_H
