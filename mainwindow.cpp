#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QTextStream>
#include <QTextStream>


QMap<int , float> mamap;

float SommeOp=0.0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

//Affichage du chemin de fichier//Soual
   qDebug() <<  QDir::homePath();
//----------------------------------------

// Ouvre les fichiers texte de l'emplacement où se trouve le projet//Soual
   //QString nomFichier = QFileDialog::getOpenFileName(this, "Sléctionner un Fichier Texte", QDir::homePath(), "Text Files (*.txt)" );
 //----------------------------------------------------------------
   //----------------Autre façon--------------------
 //  QString nomFichier = "Operations.txt"; //QFileDialog::getOpenFileName(this, "Sléctionner un Fichier Texte", QDir::homePath(), "Text Files (*.txt)" );

//----------------------------------------------

   QFile fichier("C:\\Users\\Mehdi.AMRI\\Desktop\\Operations.txt");

   bool openok = fichier.open(QIODevice::ReadOnly|QIODevice::Text);

if (openok)//if A
{
      qDebug()<<"Ouverture ok";

      ui->Infos_Compte_plainTextEdit->setPlainText("Ouverture ok");
     //Si l'ouverture fonctionne on continue:
       QTextStream flux(&fichier);
  //      QString mot;

 while ( !flux.atEnd() )
  {

      QString contenu =fichier.readLine();
      QStringList LigneFch=contenu.split(";");


      if (mamap.contains((LigneFch.at(0)).toInt())) //If B:Si on a déjà une première paire clef-valeur
      {

          if ( (LigneFch.at(2)=='1') or (LigneFch.at(2)=='2'))//if C
                 {
                        qDebug()<<  "j'arrive la";
                 //       SommeOp -= (LigneFch.at(3)).toFloat();
                    mamap[LigneFch.at(0).toInt()] -= LigneFch.at(3).toFloat();

                        qDebug()<<  "Je fais sommeOP dans les cas 1 ou 2, la preuve: " <<"Sommeop= "<<SommeOp;
                 }//fin if C





          else if (LigneFch.at(2)=='3') //else if A
                 {
                         qDebug()<<  "et la aussi";
                    //     SommeOp+=(LigneFch.at(3)).toFloat();
                       mamap[LigneFch.at(0).toInt()] += LigneFch.at(3).toFloat();
                         qDebug()<<  "Je fais sommeOP dans le cas 3, la preuve: " <<"Sommeop= "<<SommeOp;
                 }//Fin else if A



          else // Si le code est 4

          {
              QString fichier = ("C:\\Users\\Mehdi.AMRI\\Desktop\\Anomalies.txt");

              QFile file(fichier); // Appel du constructeur de la classe QFile

              if (file.open(QIODevice::WriteOnly | QIODevice::Text))

             {
              // Si l'ouverture du fichier en écriture à réussie

              // écrire dans le fichier
              file.write("Texte à écrire dans le fichier ou variable contenant ce texteOpération num\n");

              file.write("Autre chose\n");

              QTextStream stream(&file);

              stream<<"Essai Stream:  "<< " "<<"Essai Stream:  "<< " Anomalie_ En date du "<<LigneFch.at(1)<<"sur le compte"<<LigneFch.at(0) ;

              // Fermer le fichier
              file.close();
            }// Fin if file. open

          }// Fin else pour le code 4

    }// Fin du if pour le cas où on a déjà a clef




  else // Else B: Sinon c'est la première fois qu'on voit la clef


      {
         //(Re)Init de SommeOp
          SommeOp=0;

          if ( (LigneFch.at(2)=='1') or (LigneFch.at(2)=='2'))
                 {
                        qDebug()<<  "j'arrive la";
                        SommeOp -= (LigneFch.at(3)).toFloat();

                        qDebug()<<  "Je fais sommeOP dans les cas 1 ou 2, la preuve: " <<"Sommeop= "<<SommeOp;
                 }// Fin if


          else if (LigneFch.at(2)=='3')
                 {
                         qDebug()<<  "et la aussi";
                    //     SommeOp+=(LigneFch.at(3)).toFloat();
                       mamap[LigneFch.at(0).toInt()] += LigneFch.at(3).toFloat();
                         qDebug()<<  "Je fais sommeOP dans le cas 3, la preuve: " <<"Sommeop= "<<SommeOp;
                 }//Fin else if





          else
          {
              QString fichier = ("C:\\Users\\Mehdi.AMRI\\Desktop\\Anomalies.txt");

              QFile file(fichier); // Appel du constructeur de la classe QFile

              if (file.open(QIODevice::WriteOnly | QIODevice::Text))
              {
              // Si l'ouverture du fichier en écriture à réussie

              // écrire dans le fichier
              file.write("Texte à écrire dans le fichier ou variable contenant ce texteOpération num\n");

              file.write("Autre chose\n");

              QTextStream stream(&file);

              stream<<"Essai Stream:  "<< " Anomalie_ En date du "<<LigneFch.at(1)<<"sur le compte"<<LigneFch.at(0) ;

              // Fermer le fichier
              file.close();

              }// Fin if file.open




      }//Fin else pour le cas du 4

     // On insère vu que c'est la première fois qu'on voit la clef

     mamap.insert((LigneFch.at(0)).toInt(),SommeOp);



 }//Fin while

      qDebug()<< mamap;

}//Fin "if open(ok)"

}


 else
      {
     qDebug()<<"Ouverture Nok";
      }





}






MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Infos_Compte_pushButton_clicked()
{
   ui->Infos_Compte_plainTextEdit->setPlainText("Test");
}
