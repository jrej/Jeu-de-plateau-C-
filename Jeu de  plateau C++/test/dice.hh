#ifndef DICE_HH
#define DICE_HH
#include<time.h>
#include<stdlib.h>
#include <stdio.h>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
using namespace std;


class dice: public QWidget
{
public:
    dice();

    int call();


};


#endif // DICE_HH
