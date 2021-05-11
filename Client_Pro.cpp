#include "Client_Pro.h"

Client_Pro:: Client_Pro(int Id , string N,ADP AdrP,string Mail,
                string Siret,StatutJ Statut,ADS AdrSI )
            : Client ( Id,  N, AdrP, Mail)
{
    SetSiret(Siret);
    SetStatut(Statut);
    SetAdresseSiege(AdrSI);

    //ctor
}

Client_Pro::~Client_Pro()
{
    //dtor
}


void Client_Pro::SetSiret(string num)
{
    if (num.size()==14)

    {
        Siret=num;
    }

    else
    {
     //   throw range_error ("Nombre de caacters errone (Le Siret doit comporter 14 caracteres." );
    }
}

string Client_Pro::Tostring_Prst_Client_Pro()
{


    ostringstream oss ;
    oss << endl;
    oss<< Tostring_Prst_Client();

    //oss << endl <<  "collPers[" << i << "] : " << data[i].ToString() << endl;
    oss << endl <<  "Siret: " <<GetSiret()
        <<" Statut juridique :" << GetStatut()
        <<"Adresse siège  :"<<GetAdresseSiege().libelle<<"  "
        <<GetAdresseSiege().complement<<" "<<GetAdresseSiege().codePostal
        <<" "<<GetAdresseSiege().ville;
    oss << endl << "------------------------------------" << endl;

    return oss.str();


}

