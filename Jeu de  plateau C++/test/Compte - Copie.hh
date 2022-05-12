#ifndef COMPTE_HH
#define COMPTE_HH


#include "Element.hh"

class Compte : public Element{
    public:
        Compte();
        float GetTaux();
         float GetSolde();
         int GetId();
         std::string GetClient();
         void SetTaux(float difference);
         void SetSolde(float difference);

        virtual ~Compte();
    protected:
    private:
         int id;
        float solde;
        std::string client;
        float taux;
};

#endif // COMPTE_HH
