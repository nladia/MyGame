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

public:
    Weapon *weap;
    Pers();
    Pers(int);
    void levlup();
    int attack();
    int levl();
    void dmg(int);
    int hpp();
    void gexp(int);
    int gcls();
    int expp();
    int minattk();
    int maxattk();
    int lvlupexp();
};

#endif // PERS_H
