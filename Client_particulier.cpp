#include "Client_particulier.h"
#include <sstream>


Client_particulier::Client_particulier(int Id, string N,ADP AdrP,string Mail,DN val,string Prenom,char S)
:    Client( Id,  N, AdrP,Mail)
{
    SetDateNaissance(val);
    SetPrenom(Prenom);
    Setsexe(S);
    //ctor
}



Client_particulier::~Client_particulier()
{
    //dtor
}


string Client_particulier::Tostring_Msg_erreur_Prenom()
{
    ostringstream oss ;
    oss << endl << "------------ LISTING -------------" << endl;


    //oss << endl <<  "collPers[" << i << "] : " << data[i].ToString() << endl;
    oss << endl <<  "Le prenom comporte au maximum 50 caractères." <<endl;
    oss << endl << "------------------------------------" << endl;

    return oss.str();

}

string Client_particulier::Tostring_Msg_erreur_Date()
{
    ostringstream oss ;
    oss << endl << "------------ LISTING -------------" << endl;


    //oss << endl <<  "collPers[" << i << "] : " << data[i].ToString() << endl;
    oss << endl <<  "Veuillez saisir une date valide." <<endl;
    oss << endl << "------------------------------------" << endl;

    return oss.str();

}

string Client_particulier::Tostring_Msg_erreur_sexe()
{
    ostringstream oss ;
    oss << endl << "------------ LISTING -------------" << endl;


    //oss << endl <<  "collPers[" << i << "] : " << data[i].ToString() << endl;
    oss << endl <<  "Saisie non valide." <<endl;
    oss << endl << "------------------------------------" << endl;

    return oss.str();

}

string Client_particulier:: Tostring_Prst_Client_Particulier()
{
    Client::Tostring_Prst_Client();

    ostringstream oss ;
   // oss << endl << "------------ LISTING -------------" << endl;

    oss << endl <<  "Date de naissance : " << this->GetDateNaissance().jj << "/ "<< this->GetDateNaissance().mm<<"/"<< this->GetDateNaissance().aa<<endl;


    oss<<" Prenom :"<<this->GetPrenom()<<" "<< "Sexe :"<<this->Getsexe()<< endl;
    oss << endl << "------------------------------------" << endl;





    return oss.str();





}

