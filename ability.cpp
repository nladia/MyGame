#include "ability.h"
#include "ui_ability.h"

Ability::Ability(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ability)
{
    ui->setupUi(this);

    pass[0] = false;
    pass[1] = false;
    pass[2] = false;
    pass[3] = false;
    pass[4] = false;



    prebat[0][0] = false;
    prebat[1][0] = false;
    prebat[2][0] = false;
    prebat[3][0] = false;
    prebat[4][0] = false;

    prebatcd[0][0] = 4;
    prebatcd[0][1] = 2;
    prebatcd[0][2] = 2;
    prebatcd[0][3] = 6;
    prebatcd[0][4] = 16;

    inbat[0] = false;
    inbat[1] = false;
    inbat[2] = false;
    inbat[3] = false;
    inbat[4] = false;

    inbatcd[0][0] = 3;
    inbatcd[0][0] = 6;
    inbatcd[0][0] = 4;
    inbatcd[0][0] = 4;
    inbatcd[0][0] = 0;
}

Ability::~Ability()
{
    delete ui;

}

void Ability::crepasive(int pas)
{
    switch (pas)
    {
        case 0: {pass[0] = true; break;}
        case 1: {pass[1] = true; break;}
        case 2: {pass[2] = true; break;}
        case 3: {pass[3] = true; break;}
        case 4: {pass[4] = true; break;}
    }
}

void Ability::creprebattle(int pre)
{
    switch (pre)
    {
        case 0: {prebat[0][0] = true; break;}
        case 1: {prebat[1][0] = true; break;}
        case 2: {prebat[2][0] = true; break;}
        case 3: {prebat[3][0] = true; break;}
        case 4: {prebat[4][0] = true; break;}
    }
}

void Ability::creinbattle(int inb)
{
    switch (inb)
    {
        case 0: {inbat[0] = true; break;}
        case 1: {inbat[1] = true; break;}
        case 2: {inbat[2] = true; break;}
        case 3: {inbat[3] = true; break;}
        case 4: {inbat[4] = true; break;}
    }
}

void Ability::usepassive(Monster *monster, int mdmg)
{
    if (pass[0] == true)
        if (rand() % 10 == 1)
            mdmg = 0;

    if (pass[1] == true)
    {
        monster->dmg(mdmg / 8);
    }
}

void Ability::useinbattle(Pers *pers, Monster *monster, int pdmg, int mdmg)
{
    if ((inbat[0] == true) && (inbatcd[0][1]>0))
    {
        inbatcd[0][1]--;
        mdmg = 0;
    }
    if ((inbat[1] == true) && (inbatcd[1][1]>0))
    {
        inbatcd[1][1]--;
        pers->dmg(-1 * (pdmg / 3));
    }
    if ((inbat[2] == true) && (inbatcd[2][1]>0))
    {
        inbatcd[2][1]--;
        monster->dmg(30);
    }
    if ((inbat[3] == true) && (inbatcd[2][1]>0))
    {
        inbatcd[3][1]--;
        monster->dmg(150);
    }
    if ((inbat[4] == true) && (inbatcd[4][1]>0))
    {
        pdmg += 10;
        inbatcd[4][1]--;
    }
}

void Ability::useprebattle(Pers *pers, Monster *monster)
{
    if (prebat[0][0] == true && prebat[0][1] == true)
    {
        pers->heal(5);
    }
    if (prebat[1][0] == true && prebat[1][1] == true)
    {
        afterbattle = pers->attack() / 5;
        pers->incdmg(afterbattle);
    }

    if (prebat[2][0] == true && prebat[2][1] == true)
    {
        afterbattle = pers->hpp();
    }

    if (prebat[3][0] == true && prebat[3][1] == true)
    {
        monster->dmg(monster->hpp());
    }
}

void Ability::useafterbattle(Pers *pers)
{
    if (prebat[1][0] == true && prebat[1][1] == true)
    {
        pers->incdmg(-1 * afterbattle);
    }

    if (prebat[2][0] == true && prebat[2][1] == true)
    {
        pers->sethp(afterbattle);
    }
}
