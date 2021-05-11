#include "Client.h"
#include <sstream>




Client::Client(int Id, string N,ADP AdrP,string Mail )
{
    Setidentifiant(Id);
    SetNom(N);
    SetAdressePostale(AdrP);
    SetMailContact(Mail);

}

Client::~Client()
{
    //dtor
}


 string Client::Tostring_Prst_Client()
{
    ostringstream oss ;
    oss << endl << "------------ LISTING -------------" << endl;


    //oss << endl <<  "collPers[" << i << "] : " << data[i].ToString() << endl;
    oss << endl <<  "Client: " << this->Getidentifiant() << "   "<< this->GetNom()<<"Adresse : "<<
        this->GetAdressePostale().libelle<<" "<<this->GetAdressePostale().complement<< endl;
    oss << endl << "------------------------------------" << endl;

    return oss.str();

}



string Client::Tostring_Msg_erreur_nom()
{
    ostringstream oss ;
    oss << endl << "------------ LISTING -------------" << endl;


    //oss << endl <<  "collPers[" << i << "] : " << data[i].ToString() << endl;
    oss << endl <<  "Le nom comporte au maximum 50 caractères." <<endl;
    oss << endl << "------------------------------------" << endl;

    return oss.str();

}

string Client::Tostring_Msg_erreur_mail()
{ ostringstream oss ;
    oss << endl << "------------ LISTING -------------" << endl;


    //oss << endl <<  "collPers[" << i << "] : " << data[i].ToString() << endl;
    oss << endl <<  "Saisir une adresse mail vlaide de préférence. " <<endl;
    oss << endl << "------------------------------------" << endl;

    return oss.str();

}

string Client::Getidentifiant()
{

    ostringstream oss;
    oss.width(5);
    oss.fill('0');
    oss<<identifiant;

    return oss.str();
}

string Client::Tostring_Msg_erreur_id()
{  ostringstream oss ;
    oss << endl << "------------ LISTING -------------" << endl;


    //oss << endl <<  "collPers[" << i << "] : " << data[i].ToString() << endl;
    oss << endl <<  "L'identifiant doit comporter 5 chiffres au maximum. " <<endl;
    oss << endl << "------------------------------------" << endl;

    return oss.str();

}

