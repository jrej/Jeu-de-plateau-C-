#ifndef EVENEMENTS_H
#define EVENEMENTS_H
#include "Pays.hh"
#endif // EVENEMENTS_H

class Evenements : public Pays
{
protected :
    int random;
    bool bonus = false;
    bool malus = false;
public:
    Evenements();
    void event();
};
