#ifndef FLOOR_H
#define FLOOR_H

#include <QMainWindow>
#include "roombattle.h"



class Floor
{
    QWidget *map;
    RoomBattle *r1;
    RoomBattle *r2;
    RoomBattle *r3;
    RoomBattle *r4;
    RoomBattle *r5;
    RoomBattle *r6;
    RoomBattle *r7;
    RoomBattle *r8;
    RoomBattle *r9;
    RoomBattle *r10;
    Pers *pers;
    int rom1[30][2];
    int floor;


public:
//    RoomBattle *r1;
    void enter(int);
    bool alive(int);
//    Floor();
    Floor(QWidget *mp = 0, Pers *prs = 0,int x = 0, int flor = 0);
    bool exist(int);
    void floor1();
    void createfloor(int x);
    ~Floor();
};

#endif // FLOOR_H
