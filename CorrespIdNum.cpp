#include "CorrespIdNum.h"



int NumCpteVersId(int NumCpte)

{
    int IdCompte;
    QString QIdCompte=QString::number(NumCpte);//QString::fromInt(NumCpte);
    QString MaBdd = "C:\\Users\\Mehdi.AMRI\\Documents\\Ajc\\QT\\Projet\\Projet_Cpp_QT\\BdComptes.db";
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(MaBdd);

    qDebug()<< "J arrive quand meme avant le bool!";

    bool cnxOK =db.open();

     qDebug()<< "J arrive quand meme apres le bool!";

    if (cnxOK)

    {
        qDebug()<< "Entre dans le if mais pas dasn le while";

        QString reqSQL="SELECT numcli FROM comptes where numcompte="+QIdCompte;
        QSqlQuery query (reqSQL,db);

        while (query.next())
        {
                IdCompte=(query.value(0)).toInt();
                qDebug()<< IdCompte;

           //   qDebug()<< "IdCompte pas trouvé!";

            //  ui->ResultatBdd_listWidget->addItem(ui->);

         }


      }

     db.close();

     return IdCompte;

    }

//void Affiche_Infos_CLient ()

//{


