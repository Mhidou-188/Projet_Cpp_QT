#include "mainwindow.h"
#include "Client_particulier.h"
#include <QApplication>
#include<QTextCodec>
#include"CorrespIdNum.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

  //  QTextCodec::setCodec//set(QTextCodec::codecForName("UTF-8"));
  //  QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    ADP Durand_ADP = {"4 Rue top","Appt 23", 79043,"Ailleurs" };

    DN DurandDate= {8,12,72};
    Client_particulier Cp1 ( 1, "Durand",Durand_ADP,"Dudurand@gmail.com",DurandDate,"Michel",'m');
    NumCpteVersId( 123);

    MainWindow w;
    w.show();
    return a.exec();
}
