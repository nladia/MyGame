#include "monster.h"

Monster::Monster()
{

}

Monster::Monster(int y, int x)
{
    if (y == 1)
    {
        hp = 45;
        minatk = 2;
        maxatk = 4;
        exp = 10;
    }
    if (y == 2)
    {
        hp = 50;
        minatk = 10;
        maxatk = 14;
        exp = 12;
    }
    if (y == 3)
    {
        hp = 40;
        minatk = 18;
        maxatk = 25;
        exp = 14;
    }
    hp += 50 * x;
    minatk += 5 * x;
    maxatk += 5 * x;
    exp += 3*x;

}

int Monster::attack()
{
    return rand()%(maxatk - minatk) + minatk;
}
void Monster::dmg(int x)
{
    hp-=x;
}

int Monster::hpp()
{
    return hp;
}

int Monster::gexp()
{
    return exp;
}

int Monster::maxattk()
{
    return maxatk;
}

int Monster::minattk()
{
    return minatk;
}
