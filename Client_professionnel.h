#ifndef CLIENT_PROFESSIONNEL_H
#define CLIENT_PROFESSIONNEL_H

#include "Client.h"

struct AdresseSiege

{
    string libelle;
    string complement;
    int codePostal;
    string ville;

};

typedef struct AdressePostale ADS;

class Client_professionnel : public Client
{
    public:
        Client_professionnel();
        virtual ~Client_professionnel();

        string GetSiret() { return Siret; }
        void SetSiret(string val) { Siret = val; }
        string GetStatutJ() { return StatutJ; }
        void SetStatutJ(string val) { StatutJ = val; }
        ADS GetAdresseSiege() { return AdresseSiege; }
        void SetAdresseSiege(ADS val) { AdresseSiege = val; }

    protected:

    private:
        string Siret;
        string StatutJ;
        ADS AdresseSiege;
};

#endif // CLIENT_PROFESSIONNEL_H
