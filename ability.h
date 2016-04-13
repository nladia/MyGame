#ifndef ABILITY_H
#define ABILITY_H

#include <QMainWindow>
#include "room.h"

namespace Ui {
class Ability;
}

class Ability : public QMainWindow
{
    Q_OBJECT
    bool pass[5];
    int afterbattle;

    bool prebat[5][2];
    int prebatcd[5][2];

    bool inbat[5];
    int inbatcd[5][2];

public:
    explicit Ability(QWidget *parent = 0);
    ~Ability();

private:
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
