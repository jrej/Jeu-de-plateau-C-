#include "buton.hh"

MonButon::MonButon(const QString & chaine, QWidget *parent,int x,int y):QPushButton(chaine, parent)
{
this->setFixedSize(x,y);
}

MonButon::MonButon(QWidget *parent,int x,int y):QPushButton(parent)
{
this->setFixedSize(x,y);
}


