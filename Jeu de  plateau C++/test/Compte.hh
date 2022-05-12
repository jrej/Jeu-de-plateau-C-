#ifndef COMPTE_HH
#define COMPTE_HH


#include "Element.hh"

class Compte : public Element{
    public:
        Compte();
        float GetTaux();
         int GetSolde();
         int GetId();
         std::string GetClient();
         void SetTaux(float difference);

         void SetSolde(int sol);

        virtual ~Compte();
         int solde;

    protected:
         int id;
        std::string client;
        float taux;
};

#endif // COMPTE_HH
