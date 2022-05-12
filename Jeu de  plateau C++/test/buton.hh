#ifndef BUTON_HH
#define BUTON_HH
#include <QString>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

class MonButon : public QPushButton {
    Q_OBJECT

public:
    MonButon(const QString &  chaine, QWidget *parent, int x, int y);
    MonButon(QWidget *parent,int x,int y);

};
#endif // BUTON_HH
