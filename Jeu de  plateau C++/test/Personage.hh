//#ifndef PERSONAGE_HH
//#define PERSONAGE_HH
#include <QtGui>
#include <QVBoxLayout>
#include "Element.hh"
#include "Compte.hh"
#include <list>
using namespace std;
class Personnage : public Compte
{
    public:
        Personnage();
        virtual ~Personnage();
        void ajouter_Compte(Compte new_compte);
        void enlever_Compte(int id);
        QPixmap* GetImage();
        Compte GetCompte();


    protected:
    private:
         QPixmap *image;
};

//#endif // PERSONAGE_HH
