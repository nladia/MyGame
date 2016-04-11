#ifndef ROOM_H
#define ROOM_H
#include "Pers.h"
#include "monster.h"

class Room
{
    int num;
    int atkp;
    int atkm;
    int rol;
public:
    bool alive;
    Pers *pers;
    Monster *monstr;
    Room();
    Room(int, Pers*, int);
    ~Room ();
    int battle();
    int attkp();
    int attkm();
    int roll();
};

#endif // ROOM_H
