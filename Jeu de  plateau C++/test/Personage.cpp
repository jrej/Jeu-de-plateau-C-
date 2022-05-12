#include "Personage.hh"

Personnage::Personnage()
{
    Element();
   solde = 1000000;
    this->image = new QPixmap("persoarret.jpg");
   image->scaled(30,60);
    //ctor
}


QPixmap* Personnage::GetImage(){
    return this->image ;
}



Personnage::~Personnage()
{
    //dtor
}

