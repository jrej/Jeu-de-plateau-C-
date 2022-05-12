#ifndef PAYS_HH
#define PAYS_HH
#include <list>
#include <map>
#include "Compte.hh"
#include "Element.hh"
#include <QApplication>
#include <QWidget>


using namespace std;
class Pays : public Element{
    public:
        Pays();
        Pays(string nom,int num);
        virtual ~Pays();
        void ajouter_compte(Compte new_compte);
        void enlever_compte(int nid );
        void SetDetails(float benef, float perte);
        float GetBenef();
        float GetPerte();

        void SetSolde(int i);
        void AddSolde(int i);
        int GetSolde();
         int num;
    protected:
        Compte compte;
        float benef;
        float perte;
};

#endif // PAYS_HH
