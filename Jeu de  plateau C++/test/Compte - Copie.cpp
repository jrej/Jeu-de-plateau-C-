#include "Compte.hh"
static int id = 0 ;
Compte::Compte()
{
    Element();
    this->id = id++ ;
    this->taux = 1 ;
    this->client = " vide " ;//ctor
}

float Compte::GetSolde(){
    return this->solde;
}
float Compte::GetTaux(){
    return this->taux;
}
std::string Compte::GetClient(){
    return this->client;
}
void Compte::SetSolde(float ajout){
    this->solde += ajout ;
}
void Compte::SetTaux(float ajout){
    this->taux += ajout ;
}
int Compte::GetId(){

	return this->id;
}

Compte::~Compte()
{
    //dtor
}
