#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <list>
#include <QVBoxLayout>
#include <QApplication>
#include <QtGui>
#include <QTextEdit>
#include <QtWidgets>
#include <iostream>
#include "Pays.hh"
#include "Personage.hh"
#include "dice.hh"






class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT
    public:
    MaFenetre(int x, int y, const char* chaine);
     MaFenetre(int x, int y);
     void InitPays();
    // void PlacerBoutons(QPushButton *lebouton,float x,float y,int longeur,int largeur,QString nompays);
     void PlacerBoutonsEtPays(QPushButton *lebouton,float x,float y,int longeur,int largeur,QString nompays,Pays *adefinir,int solde);
     void InfosPays(QWidget *fenetre ,QLabel *label, QPushButton *cashout,QGridLayout *layout, QFormLayout *layout2, QGridLayout *layout3,QString str1);
 QLabel *image2;
     public slots:
        void Setsolde(int i); // regle le solde lorsquon appuie sur le bouton
        void afficher();
        void sleep(int time);
        void afficherPosition();
        void deplacement_perso(int dest_x , int dest_y);
        void afficherUsa();
        void afficherCanada();
        void afficherBresil();
        void afficherArgentine();
        void afficherFrance();
        void afficherAfrique();
        void afficherQatar();
        void afficherInde();
        void afficherChine();
        void persoInit();
        void Investir();
        void CashOut();
        void lancer();
    private:
        dice de;
    std::list<QPushButton> liste_bouton;
    std::list<Pays> listePays;
    int pos_cour;
    std::string pays_cour;
    QLabel *image;
    QTextEdit *texte;
    QPushButton *bouton;
    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *bouton3;
    QPushButton *bouton4;
    QPushButton *bouton5;
    QPushButton *bouton6;
    QPushButton *bouton7;
    QPushButton *bouton8;
    QPushButton *bouton9;
    QPushButton *cashout;
    QPushButton *invest;
    QPushButton *diceb ;
    Personnage perso;
    QTextEdit *texte_cour;
    QTime dieTime;
    int largeurEcran;
        int hauteurEcran;



};
