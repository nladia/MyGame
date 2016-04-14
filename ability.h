#ifndef ABILITY_H
#define ABILITY_H

#include <QMainWindow>
#include <QPushButton>
#include "monster.h"
#include "pers.h"

namespace Ui {
class Ability;
}

class Ability : public QMainWindow
{
    Q_OBJECT
    bool pass[5];
    int afterbattle;

    QWidget *prebattlescr;

    bool prebat[5][2];
    int prebatcd[5][2];

    QPushButton *button[16];


    bool inbat[5];
    int inbatcd[5][4];

public:
    explicit Ability(QWidget *parent = 0);

    void remap(QWidget *parent = 0);

    ~Ability();

private slots:
    void on_pushButton_16_clicked();

private:
    void cdinbattle();
    void cdprebattle();



    void battle(Pers *pers, Monster *monster,int pdmg, int mdmg);

    void useability(int x, int y);

    bool abilityavailable(int x, int y);

    void showEvent(QShowEvent *event);

    void renew();
    void bindbuttons();

    void crepasive(int pas);
    void creprebattle(int pre);
    void creinbattle(int inb);

    void usepassive(Monster *monster, int mdmg);
    void useinbattle(Pers *pers, Monster *monster,int pdmg, int mdmg);
    void useprebattle(Pers *pers, Monster *monster);
    void useafterbattle(Pers *pers);

    Ui::Ability *ui;
};

#endif // ABILITY_H
