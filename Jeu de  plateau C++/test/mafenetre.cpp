#include "mafenetre.hh"
#include "Pays.hh"

using namespace std;

int newsolde;
Pays payscour;


MaFenetre::MaFenetre(int x,int y,const char* chaine) : QWidget()
{
        setFixedSize(x,y);
        largeurEcran = QApplication::desktop()->screenGeometry().width();
        hauteurEcran = QApplication::desktop()->screenGeometry().height();

        image = new QLabel(this);
         QPixmap pixmap(chaine);
        pixmap = pixmap.scaled(QSize(x,y),Qt::IgnoreAspectRatio);

        image->setPixmap(pixmap);
           image->resize(this->size());
           image2 = new QLabel(this);

           InitPays();
           persoInit();

           invest =  new QPushButton(this);

            cashout =  new QPushButton(this);
            cashout->setText("Cash Out");
            cashout->setGeometry(1130,360,60,30);
            cashout->hide();

            texte = new QTextEdit(this) ;
            texte->hide();

            texte_cour =  new QTextEdit(this);
            texte_cour->setGeometry(1070,390,120,60);
            texte_cour->setText("Choisisser un pays ou investire votre argent");

            QString txt = QString::number(perso.GetSolde());
            QString text = QString("Vous avez :: %1 euros ").arg(txt);
            texte_cour->append(text);
            diceb = new QPushButton(this);
            diceb->setGeometry(largeurEcran*(1 - 0.56),hauteurEcran*(1-0.4),60,60);
            diceb->setText("Dé");

            QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(afficherUsa()));
            QObject::connect(bouton2, SIGNAL(clicked()), this, SLOT(afficherCanada()));
            QObject::connect(bouton4, SIGNAL(clicked()), this, SLOT(afficherUsa()));
            QObject::connect(bouton3, SIGNAL(clicked()), this, SLOT(afficherUsa()));
            QObject::connect(bouton5, SIGNAL(clicked()), this, SLOT(afficherUsa()));
            QObject::connect(bouton6, SIGNAL(clicked()), this, SLOT(afficherUsa()));
            QObject::connect(bouton7, SIGNAL(clicked()), this, SLOT(afficherUsa()));
            QObject::connect(bouton8, SIGNAL(clicked()), this, SLOT(afficherUsa()));
            QObject::connect(bouton9, SIGNAL(clicked()), this, SLOT(afficherChine()));
             QObject::connect(diceb, SIGNAL(clicked()), this, SLOT(lancer()));

             QObject::connect(cashout, SIGNAL(clicked()), this, SLOT(CashOut()));
}

void MaFenetre::sleep(int time)
{
    dieTime = QTime::currentTime().addMSecs(time);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(); // (QEventLoop::AllEvents, 100)
}

MaFenetre::MaFenetre(int x,int y)
{
 setFixedSize(x,y);
}

void MaFenetre::Setsolde(int i)
{
    newsolde = i;
 cout<<i<<endl;
cout<<payscour.GetSolde() <<endl;
}

void MaFenetre::Investir(){

    payscour.AddSolde(newsolde*1000);
    perso.SetSolde(-newsolde*1000);
    QWidget *fenetre = new QWidget();
   fenetre->setFixedSize(largeurEcran*0.2,hauteurEcran*0.1);
QString chaine = QString::fromStdString("\nSolde du pays : $") + QString::number(payscour.GetSolde()) +  QString::fromStdString("\nVotre Solde : $") + QString::number(perso.GetSolde());
    QLabel *label = new QLabel(fenetre);
    fenetre->setStyleSheet("background-color : #000080");
    label->setStyleSheet("color : #bfa100;");
    label->setText("Bravo vous avez investit !" + chaine);
       fenetre->show();
    this->sleep(5000);
       fenetre->hide();
}

void MaFenetre::lancer(){
    QPixmap pixmap;
    int indice ;
    int res ;
    for(int i = 0 ; i< 5 ; i++){
        cout<< "roll dice"<< endl;
        res = de.call();
        cout << " resultat dé ::  " << res  << endl ;
        switch(res){
        cout << " resultat dé ::  " << res  << endl ;
        case 1:
             pixmap.load("un.jpg");
            diceb->setIcon(pixmap);
             this->sleep(10);
            break;
        case 2:
             pixmap.load("deux.jpg");
             diceb->setIcon(pixmap);
              this->sleep(10);
            break;
        case 3:
            pixmap.load("trois.jpg");
            diceb->setIcon(pixmap);
             this->sleep(10);
            break;
        case 4:
            pixmap.load("quatre.jpg");
            diceb->setIcon(pixmap);
             this->sleep(10);
            break;
        case 5:
            pixmap.load("cinq.jpg");
            diceb->setIcon(pixmap);
             this->sleep(10);

            break;
        case 6:
            pixmap.load("sis.jpg");
            diceb->setIcon(pixmap);
            break;
        default:
            break;


     }

    }
    if((pos_cour + res) <= 9)
        indice = pos_cour + res ;
    else
        indice = pos_cour+ res - 9 ;
    if(indice < 1)
        indice = 1;

    // on doit deplacer le personnage sur le pays en question
    for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++){
        if(it->num ==  indice){
         pays_cour = it->GetNom();
         cout << "Vous etes arrivé a " << pays_cour << endl;
         //deplacement_perso(it->Getx()+30,it->Gety()+30);
        // perso.SetPos(largeurEcran*(1 - 0.84)+30,hauteurEcran*(1-0.2)+30);
        }
     }
       for(int j = pos_cour; j <= indice ; j++ ){
        for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++){
            if(it->num == j){
             pays_cour = it->GetNom();
             cout << " Position :: " << j << endl;
             deplacement_perso(it->Getx()+30,it->Gety()+30);
             this->sleep(10);
            // perso.SetPos(largeurEcran*(1 - 0.84)+30,hauteurEcran*(1-0.2)+30);
            }
       }
    }
    pos_cour = indice ;
    cout << " Position " << pos_cour << endl;
}

void MaFenetre::persoInit(){

    for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++){
        if(it->GetNom() == pays_cour){
        perso.SetPos(it->Getx()+30,it->Gety()+30);
        pos_cour = 1 ;
        }
    }

    image2->setPixmap(*perso.GetImage());
       image2->resize(perso.GetImage()->size());
       image2->move(perso.Getx(),perso.Gety());

}
void MaFenetre::deplacement_perso(int dest_x , int dest_y){
    int i, j ;
    bool flag1 = false ;
    bool flag2 = false;
    i = perso.Getx();
    j = perso.Gety();
    while(!(flag1)){

       if(i>dest_x)
           i--;
       else if(i<dest_x)
           i++;



       perso.SetPos(i,j);
       image2->move(perso.Getx(),perso.Gety());
       this->sleep(5);


    //   cout<<"dest x :: "<< dest_x << " dext y :: " << dest_y << endl;
     //  cout<< "x_cour :: "<< i << " y_cour :: " << j << endl;

       if(perso.Getx() == dest_x)
           flag1 = true ;

    }

    while(!(flag2)){

        if(j>dest_y)
            j--;
        else if(j<dest_y)
            j++;

        perso.SetPos(i,j);
        image2->move(perso.Getx(),perso.Gety());
        this->sleep(5);

       // cout<<"dest x :: "<< dest_x << " dext y :: " << dest_y << endl;
       // cout<< "x_cour :: "<< i << " y_cour :: " << j << endl;

        if (perso.Gety() == dest_y)
            flag2 = true ;
    }
}

void MaFenetre::afficher()
{
    this->show();
}


void MaFenetre::PlacerBoutonsEtPays(QPushButton *lebouton,float x,float y,int longeur,int largeur,QString nompays,Pays *adefinir,int solde)
{
    lebouton->setGeometry((float)largeurEcran*(1-x),(float)hauteurEcran*(1-y),longeur,largeur);
    lebouton->setText(nompays);
    adefinir->SetPos(largeurEcran*(1 - x),hauteurEcran*(1-y));
    cout<<"dans la fct";
    cout<<largeurEcran*(1-x);
    adefinir->SetSolde(solde);
     listePays.push_back(*adefinir);

}


void MaFenetre::InitPays(){
    //genere les stat des pays aleatoirement
    bouton = new QPushButton(this);
    Pays *usa = new Pays("USA",1);
    PlacerBoutonsEtPays(bouton,0.87,0.8,60,40,"USA",usa,10000000);
    bouton->setStyleSheet("color: red;");
    pays_cour = usa->GetNom();


    bouton2 = new QPushButton(this);
    Pays *canada = new Pays("Canada",2);
    PlacerBoutonsEtPays(bouton2,0.84,0.86,60,40,"Canada",canada,5000000);
    bouton2->setStyleSheet("color: red;");

    bouton3 = new QPushButton(this);
    Pays *argentine = new Pays("Argentine",8) ;
    PlacerBoutonsEtPays(bouton3,0.84,0.5,47,40,"Argentine",argentine,5000000);
    bouton3->setStyleSheet("font-size : 10px;color:#48D1CC;");

    bouton4 = new QPushButton(this);
    Pays *bresil = new Pays("Bresil",9) ;
    PlacerBoutonsEtPays(bouton4,0.82,0.6,60,40,"Bresil",bresil,1000000);
     bouton4->setStyleSheet("font-size : 10px;color : green;");

   bouton5 = new QPushButton(this);
   Pays *france = new Pays("France",3) ;
   PlacerBoutonsEtPays(bouton5,0.67,0.83,50,30,"France",france,1000000);
    bouton5->setStyleSheet("color : blue;");

    bouton6 = new QPushButton(this);
    Pays *afrique = new Pays("Afrique du Sud",7) ;
    PlacerBoutonsEtPays(bouton6,0.64,0.55,65,30,"Afrique du Sud",afrique,200000);
    bouton6->setStyleSheet("font-size : 9px;color: green;");


    bouton7 = new QPushButton(this);
    Pays *qatar = new Pays("Qatar",4) ;
    PlacerBoutonsEtPays(bouton7,0.57,0.69,40,40,"Qatar",qatar,1000000);
    bouton7->setStyleSheet("color:  #B22222;");

    bouton8 = new QPushButton(this);
    Pays *inde = new Pays("Inde",5) ;
    PlacerBoutonsEtPays(bouton8,0.5,0.68,40,40,"Inde",inde,1000000);
    bouton8->setStyleSheet("color : #FF8C00;");

    bouton9 = new QPushButton(this);
    Pays *chine = new Pays("Chine",6) ;
    PlacerBoutonsEtPays(bouton9,0.47,0.78,80,60,"Chine",chine,1000000);
    bouton9->setStyleSheet("color :#FF0000");
    for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++){
        it->SetDetails( rand() % 1 + 100 , rand() % 1+100);
        cout << it->GetNom() <<  " + " << it->GetBenef() << " - "<< it->GetPerte() << endl ;
    }

}
void MaFenetre::InfosPays( QWidget *fenetre ,QLabel *label, QPushButton *cashout,QGridLayout *layout, QFormLayout *layout2, QGridLayout *layout3,QString str1){
    QPushButton *investi = new QPushButton(fenetre);


    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    QSpinBox *investissement = new QSpinBox;
    QString soldePays,soldePerso;

    QObject::connect(investi, SIGNAL(clicked()), this, SLOT(Investir()));
    QObject::connect(cashout, SIGNAL(clicked()), this, SLOT(CashOut()));

    QObject::connect(investissement, SIGNAL(valueChanged(int)),this, SLOT(Setsolde(int)));
    investissement->setMaximum(1000);
    fenetre->setFixedSize(this->largeurEcran*(1-0.7),this->hauteurEcran*(1-0.7));
label->setStyleSheet("font-style:Blippo; font-size:18px;");
label->setText(str1);
layout->addWidget(label,0,0);
layout->setHorizontalSpacing(3);
layoutPrincipal->addLayout(layout);
layout2->addRow("Investissement dans ce pays (k€):", investissement);
layoutPrincipal->addLayout(layout2);
fenetre->setLayout(layoutPrincipal);
cashout->setStyleSheet("font-style : Blippo;color : yellow;background : grey;");
cashout->setText("Cash Out");
investi->setStyleSheet("font-style : Blippo;color : yellow;background : grey;");
  investi->setText("Investir la somme");
  layout3->addWidget(investi,0,0);
layout3->addWidget(cashout,0,1);
   layoutPrincipal->addLayout(layout3);
fenetre->show();
this->sleep(5000);
label->hide();
}

void MaFenetre::afficherUsa(){
  QWidget *fenetre = new QWidget();
    QLabel *label = new QLabel(fenetre);
    QPushButton *cashout = new QPushButton(fenetre);
    QGridLayout *layout = new QGridLayout;
     QFormLayout *layout2 = new QFormLayout;
     QGridLayout *layout3 = new QGridLayout;
    QString str1;
    QString str2 ;
    QString str3 ;

    for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++)
      {
        if(it->GetNom() == "USA"){
        payscour = *it;
         str1 = QString::fromStdString(it->GetNom()) + QString::fromStdString("\nPerte :") + QString::number(it->GetPerte()) + QString::fromStdString("\nBenefice :") + QString::number(it->GetBenef());
        }
    }
    InfosPays(fenetre,label,cashout,layout,layout2,layout3,str1);

}
void MaFenetre::afficherCanada(){

    QWidget *fenetre = new QWidget();
      QLabel *label = new QLabel(fenetre);
      QPushButton *cashout = new QPushButton(fenetre);
      QGridLayout *layout = new QGridLayout;
       QFormLayout *layout2 = new QFormLayout;
       QGridLayout *layout3 = new QGridLayout;
      QString str1;
      QString str2 ;
      QString str3 ;

      for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++)
        {
          if(it->GetNom() == "Canada"){
          payscour = *it;
           str1 = QString::fromStdString(it->GetNom()) + QString::fromStdString("\nPerte :") + QString::number(it->GetPerte()) + QString::fromStdString("\nBenefice :") + QString::number(it->GetBenef());
          }
      }
      InfosPays(fenetre,label,cashout,layout,layout2,layout3,str1);

}

void MaFenetre::afficherBresil(){

    QWidget *fenetre = new QWidget();
      QLabel *label = new QLabel(fenetre);
      QPushButton *cashout = new QPushButton(fenetre);
      QGridLayout *layout = new QGridLayout;
       QFormLayout *layout2 = new QFormLayout;
       QGridLayout *layout3 = new QGridLayout;
      QString str1;
      QString str2 ;
      QString str3 ;

      for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++)
        {
          if(it->GetNom() == "Bresil"){
          payscour = *it;
           str1 = QString::fromStdString(it->GetNom()) + QString::fromStdString("\nPerte :") + QString::number(it->GetPerte()) + QString::fromStdString("\nBenefice :") + QString::number(it->GetBenef());
          }
      }
      InfosPays(fenetre,label,cashout,layout,layout2,layout3,str1);




}


void MaFenetre::CashOut(){
   /* int largeurEcran = QApplication::desktop()->screenGeometry().width();
    int hauteurEcran = QApplication::desktop()->screenGeometry().height();
    for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++){
        if(it->GetNom() == pays_cour){
           it->SetSolde(-5);
           perso.SetSolde(5);

        }
    }
    QString txt = QString::number(perso.GetSolde());
    QString txt2 = QString::fromStdString(pays_cour);
    QString text = QString("Vous avez :: %1 euros dans votre compte \n Vous avez investis 5 euros dans %2 ").arg(txt,txt2);
     texte->setGeometry(largeurEcran*(1 - 0.8),hauteurEcran*(1-0.3),largeurEcran*(1 - 0.8),60);
    texte_cour->setText(text);*/

    payscour.AddSolde(-newsolde*1000);
    perso.SetSolde(newsolde*1000);
    QWidget *fenetre = new QWidget();
   fenetre->setFixedSize(largeurEcran*0.2,hauteurEcran*0.1);
QString chaine = QString::fromStdString("\nSolde du pays : $") + QString::number(payscour.GetSolde()) +  QString::fromStdString("\nVotre Solde : $") + QString::number(perso.GetSolde());
    QLabel *label = new QLabel(fenetre);
    fenetre->setStyleSheet("background-color : #000080");
    label->setStyleSheet("color : #bfa100;");
    label->setText("Bravo vous avez cash out !" + chaine);
       fenetre->show();
    this->sleep(5000);
       fenetre->hide();
}



void MaFenetre::afficherArgentine(){

    QWidget *fenetre = new QWidget();
      QLabel *label = new QLabel(fenetre);
      QPushButton *cashout = new QPushButton(fenetre);
      QGridLayout *layout = new QGridLayout;
       QFormLayout *layout2 = new QFormLayout;
       QGridLayout *layout3 = new QGridLayout;
      QString str1;
      QString str2 ;
      QString str3 ;

      for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++)
        {
          if(it->GetNom() == "Argentine"){
          payscour = *it;
           str1 = QString::fromStdString(it->GetNom()) + QString::fromStdString("\nPerte :") + QString::number(it->GetPerte()) + QString::fromStdString("\nBenefice :") + QString::number(it->GetBenef());
          }
      }
      InfosPays(fenetre,label,cashout,layout,layout2,layout3,str1);
}

void MaFenetre::afficherFrance(){


    QWidget *fenetre = new QWidget();
      QLabel *label = new QLabel(fenetre);
      QPushButton *cashout = new QPushButton(fenetre);
      QGridLayout *layout = new QGridLayout;
       QFormLayout *layout2 = new QFormLayout;
       QGridLayout *layout3 = new QGridLayout;
      QString str1;
      QString str2 ;
      QString str3 ;

      for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++)
        {
          if(it->GetNom() == "France"){
          payscour = *it;
           str1 = QString::fromStdString(it->GetNom()) + QString::fromStdString("\nPerte :") + QString::number(it->GetPerte()) + QString::fromStdString("\nBenefice :") + QString::number(it->GetBenef());
          }
      }
      InfosPays(fenetre,label,cashout,layout,layout2,layout3,str1);
}

void MaFenetre::afficherAfrique(){
    QWidget *fenetre = new QWidget();
      QLabel *label = new QLabel(fenetre);
      QPushButton *cashout = new QPushButton(fenetre);
      QGridLayout *layout = new QGridLayout;
       QFormLayout *layout2 = new QFormLayout;
       QGridLayout *layout3 = new QGridLayout;
      QString str1;
      QString str2 ;
      QString str3 ;

      for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++)
        {
          if(it->GetNom() == "Afrique du Sud"){
          payscour = *it;
           str1 = QString::fromStdString(it->GetNom()) + QString::fromStdString("\nPerte :") + QString::number(it->GetPerte()) + QString::fromStdString("\nBenefice :") + QString::number(it->GetBenef());
          }
      }
      InfosPays(fenetre,label,cashout,layout,layout2,layout3,str1);


}


void MaFenetre::afficherQatar(){
    QWidget *fenetre = new QWidget();
      QLabel *label = new QLabel(fenetre);
      QPushButton *cashout = new QPushButton(fenetre);
      QGridLayout *layout = new QGridLayout;
       QFormLayout *layout2 = new QFormLayout;
       QGridLayout *layout3 = new QGridLayout;
      QString str1;
      QString str2 ;
      QString str3 ;

      for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++)
        {
          if(it->GetNom() == "Qatar"){
          payscour = *it;
           str1 = QString::fromStdString(it->GetNom()) + QString::fromStdString("\nPerte :") + QString::number(it->GetPerte()) + QString::fromStdString("\nBenefice :") + QString::number(it->GetBenef());
          }
      }
      InfosPays(fenetre,label,cashout,layout,layout2,layout3,str1);

}

void MaFenetre::afficherInde(){

    QWidget *fenetre = new QWidget();
      QLabel *label = new QLabel(fenetre);
      QPushButton *cashout = new QPushButton(fenetre);
      QGridLayout *layout = new QGridLayout;
       QFormLayout *layout2 = new QFormLayout;
       QGridLayout *layout3 = new QGridLayout;
      QString str1;
      QString str2 ;
      QString str3 ;

      for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++)
        {
          if(it->GetNom() == "Inde"){
          payscour = *it;
           str1 = QString::fromStdString(it->GetNom()) + QString::fromStdString("\nPerte :") + QString::number(it->GetPerte()) + QString::fromStdString("\nBenefice :") + QString::number(it->GetBenef());
          }
      }
      InfosPays(fenetre,label,cashout,layout,layout2,layout3,str1);

}

void MaFenetre::afficherChine(){
    QWidget *fenetre = new QWidget();
      QLabel *label = new QLabel(fenetre);
      QPushButton *cashout = new QPushButton(fenetre);
      QGridLayout *layout = new QGridLayout;
       QFormLayout *layout2 = new QFormLayout;
       QGridLayout *layout3 = new QGridLayout;
      QString str1;
      QString str2 ;
      QString str3 ;

      for (list<Pays>::iterator it = listePays.begin(); it != listePays.end(); it++)
        {
          if(it->GetNom() == "Chine"){
          payscour = *it;
           str1 = QString::fromStdString(it->GetNom()) + QString::fromStdString("\nPerte :") + QString::number(it->GetPerte()) + QString::fromStdString("\nBenefice :") + QString::number(it->GetBenef());
          }
      }
      InfosPays(fenetre,label,cashout,layout,layout2,layout3,str1);


}





void MaFenetre::afficherPosition()
{
  int i =  QString::number(cursor().pos().x()).toInt();
  int j =  QString::number(cursor().pos().y()).toInt();

   cout<<i<<endl;
  this->image2->move(i,j);
    cout << "whalah" ;
}

