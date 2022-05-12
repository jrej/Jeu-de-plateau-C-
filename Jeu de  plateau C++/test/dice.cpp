#include "dice.hh"
#include <QtGui>
#include <QVBoxLayout>
#include <iostream>
#include <QTextEdit>
#include <QtWidgets>
#include <string>
using namespace std;

dice::dice()
{
    cout<<"Creation du dé" << endl;

}

    int dice::call(){
            srand (time(NULL));

            int n;
            n= rand();
            n = 1 + n % 6;
            return  n;
        }




