#include "Pays.hh"
#include <list>
using namespace std;
Pays::Pays()
{
    Element();
    this->benef = 0.0;
    this->perte = 0.0;
    //ctor
}

Pays::Pays(string nom, int num)
{
    Element();
    this->SetNom(nom) ;
    this->benef = 0.0;
    this->perte = 0.0;

    this->num = num ;
    //ctor
}

void Pays::SetSolde(int i)
{
    compte.solde = i;
}

void Pays::AddSolde(int i)
{
    compte.solde +=i;
}

int Pays::GetSolde()
{
    return compte.solde;
}


float Pays::GetBenef(){
    return this->benef;
}
float Pays::GetPerte(){
    return this->perte;
}

void Pays::SetDetails(float benef , float perte){
    this->perte = perte ;
    this->benef = benef ;
}

Pays::~Pays()
{
    //dtor
}
