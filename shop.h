#ifndef SHOP_H
#define SHOP_H

#include <QMainWindow>
#include "loot.h"

namespace Ui {
class Shop;
}

class Shop : public QMainWindow
{
    Q_OBJECT
    QWidget *map;
    Pers *pers;
    bool weapon;
    bool ability;

public:
    explicit Shop(QWidget *parent = 0, Pers *prs = 0, bool weap = true, bool abil = false);
    void showEvent();
    bool weap();
    bool abil();
    ~Shop();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Shop *ui;
};

#endif // SHOP_H
