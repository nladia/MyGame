#ifndef LOOT_H
#define LOOT_H

#include <QMainWindow>
#include "room.h"

namespace Ui {
class Loot;
}

class Loot : public QMainWindow
{
    Q_OBJECT
    Pers *pers;
    QWidget *par;
    Weapon *weap;
    int exp;

public:
    explicit Loot(QWidget *parent = 0, Pers *persb = 0, int ex = 0);
    void shop();
    ~Loot();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Loot *ui;
};

#endif // LOOT_H
