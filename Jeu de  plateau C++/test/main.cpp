#include <QtGui>
#include <QApplication>
#include <QLabel>
#include <QtWidgets>
#include "mafenetre.hh"
#include "buton.hh"
#include <iostream>
#include "Pays.hh"
using namespace std;


int main(int argc, char* argv[])
{

    QApplication app(argc, argv);
    int largeurEcran = QApplication::desktop()->screenGeometry().width();
    int hauteurEcran = QApplication::desktop()->screenGeometry().height();
    MaFenetre *secondfenetre = new MaFenetre(largeurEcran*0.8,hauteurEcran*0.8,"a.jpg"); //fenetre avec limage
    MaFenetre *fenetre = new MaFenetre(largeurEcran*0.25,hauteurEcran*0.4);
    QVBoxLayout *layout = new QVBoxLayout;

    fenetre -> setWindowTitle("Launcher");
    MonButon *bouton = new MonButon("Lancer le jeu",fenetre,largeurEcran*0.23,hauteurEcran*0.15);
    QPixmap pixmap;
    pixmap.load(":/a.jpg");
    QIcon ButtonIcon(pixmap);
    bouton->setIcon(ButtonIcon);
    bouton->setIconSize(pixmap.rect().size());
    MonButon *bouton2 = new MonButon("Quitter",fenetre,largeurEcran*0.23,hauteurEcran*0.15);


    bouton->setCursor(Qt::PointingHandCursor); //avoir la main a la place de la souris
    bouton2->setCursor(Qt::PointingHandCursor); //avoir la main a la place de la souris


    bouton2->setFont(QFont("Blippo", 20,QFont::Bold, true));
    bouton->setFont(QFont("Blippo", 20,QFont::Bold, true));


    bouton2->setStyleSheet("background-color:#ffffff;");
    bouton->setStyleSheet("background-color:#ffffff;");


    fenetre->setStyleSheet("background-color:#2C75FF;");
    layout->addWidget(bouton);
    layout->addWidget(bouton2);


     fenetre->setLayout(layout);

  //   QObject::connect(bouton2, SIGNAL(clicked()), fenetre, SLOT(afficherPosition()));

     QObject::connect(bouton, SIGNAL(clicked()), secondfenetre, SLOT(afficher()));
     QObject::connect(bouton2, SIGNAL(clicked()), fenetre, SLOT(hide()));
     fenetre->move(500, 300);
     fenetre->show();




     return app.exec();
}
