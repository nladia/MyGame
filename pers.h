#ifndef PERS_H
#define PERS_H
#include "weapon.h"


class Pers
{
    int hp;
    int lvl;
    int atk;
    int cls;
    int exp;
    int lvlexp;
    int maxhp;

public:
    Weapon *weap;
    Pers();
    Pers(int);
    void levlup();
    int attack();
    int levl();
    void dmg(int);
    int maxhpp();
    void incdmg(int);
    void sethp(int);
    int hpp();
    void gexp(int);
    int gcls();
    int expp();
    int minattk();
    int maxattk();
    int lvlupexp();
    void heal(int x);

};

#endif // PERS_H
