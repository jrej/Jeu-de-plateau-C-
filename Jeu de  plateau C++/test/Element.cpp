#include "Element.hh"
#include <vector>


Element::Element()
{
    //ctor
    this->nom = "Vide";
    this->x = 0 ;
    this->y = 0 ;
}

void Element::SetNom(std::string nom){

		this->nom = nom ;
}

std::string  Element::GetNom(){
	return this->nom;
}

Element::Element(std::string nom)
{
    //ctor
    this->nom = nom;
}

Element::~Element()
{
    //dtor
}

void Element::SetPos(int x, int y){
    this->x = x ;
    this->y = y ;

}

int Element::Getx(){
    return this->x;
}
int Element::Gety(){
    return this->y;
}
