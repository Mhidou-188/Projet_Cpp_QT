#ifndef CLIENT_PRO_H
#define CLIENT_PRO_H
#include <cstring>
#include <sstream>

#include "Client.h"

using namespace std;
struct AdresseSiege

{
    string libelle;
    string complement;
    int codePostal;
    string ville;

};

typedef struct AdressePostale ADS;
//*********Statut_juridique**************
enum StatutJ {SARL,SA,SAS,EURL};
//**************************************

class Client_Pro : public Client
{
    public:
        Client_Pro();
        Client_Pro(int Id , string N,ADP AdrP,string Mail,
                string Siret,StatutJ Statut,ADS AdrSI );
        virtual ~Client_Pro();

        string GetSiret() { return Siret; }
        void SetSiret(string val);
        StatutJ GetStatut() { return Statut; }
        void SetStatut(StatutJ val) { Statut = val; }
        ADS GetAdresseSiege() { return AdresseSiege; }
        void SetAdresseSiege(ADS val) { AdresseSiege = val; }
     //   virtual string Tostring_Prst_Client() override;
        //---------Fonctions de messages-----------------------
        string Tostring_Prst_Client_Pro();

    protected:

    private:
        string Siret;
        StatutJ Statut;
        ADS AdresseSiege;
};

#endif // CLIENT_PRO_H
