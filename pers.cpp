#include "pers.h"

Pers::Pers()
{

}

Pers::Pers(int x)
{
    lvlexp = 7;
    cls = x;
    exp = 0;
    if (x == 1)
    {
        atk = 10;
        hp = 150;
        lvl = 0;
        weap = new Weapon;
        weap->stndrt(x);

    }
    if (x == 2)
    {
        atk = 14;
        hp = 100;
        lvl = 0;
        weap = new Weapon;
        weap->stndrt(x);
    }
    if (x == 3)
    {
        atk = 12;
        hp = 100;
        lvl = 0;
        weap = new Weapon;
        weap->stndrt(x);
    }
}

void Pers::levlup()
{
    int x = cls;
    if (x==1)
    {
        atk++;
        hp+=50;
    }
    if (x==2)
    {
        atk+=2;
        hp+=40;
    }
    if (x==3)
    {
        atk++;
        hp+=40;
    }
    lvl++;
    lvlexp++;
}

int Pers::attack()
{
    return atk+rand()%(weap->weapdif())+weap->weapmin();
}
int Pers::levl()
{
    return lvl;
}

void Pers::dmg(int x)
{
    hp -= x;
}

int Pers::hpp()
{
    return hp;
}

void Pers::gexp(int x)
{
    exp += x;
}

int Pers::gcls()
{
    return cls;
}

int Pers::expp()
{
    return exp;
}

int Pers::maxattk()
{
    return atk + weap->weapmin() + weap->weapdif();
}

int Pers::minattk()
{
    return atk + weap->weapmin();
}

int Pers::lvlupexp()
{
    return lvlexp;
}
