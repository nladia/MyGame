#include "floor.h"
#include "ui_floor.h"

Floor::Floor(QWidget *mp, Pers *prs, int flor) :
    QMainWindow(mp),
    ui(new Ui::Floor)
{
    ui->setupUi(this);

    pers = prs;
    map = mp;
    floor = flor;
    createfloor();
    floor1();
    ui->label->setText(QString("Currect HP : %1").arg(pers->hpp()));
}

Floor::~Floor()
{
    delete ui;

    delete r1;
    delete r2;
    delete r3;
    delete r4;
    delete r5;
    delete r6;
}


int Floor::enter(int x)
{
    num = x;

    if (rom1[num-1][0] == 2)
    {
        return 2;
    }
    if (rom1[num-1][0] == 1)
    {
        if (alive(x) == true)
        {
        show();
        return 1;
        }
        else
            return 0;

    }
}



bool Floor::exist(int x)
{
    if (rom1[x-1][0] != 0)
        return true;
    else
        return false;

}

bool Floor::alive(int x)
{
    bool k = false;
    switch (rom1[x-1][1])
    {
        case 1 : {k = r1->alive(); break;}
        case 2 : {k = r2->alive(); break;}
        case 3 : {k = r3->alive(); break;}
        case 4 : {k = r4->alive(); break;}
        case 5 : {k = r5->alive(); break;}
        case 6 : {k = r6->alive(); break;}
        case 7 : {k = r7->alive(); break;}
        case 8 : {k = r8->alive(); break;}
        case 9 : {k = r9->alive(); break;}
        case 10 : {k = r10->alive(); break;}
    }
    return k;
}

void Floor::floor1()
{
    for(int i = 0; i<30; i++)
    {
        rom1[i][0] = false;
    }

    rom1[13][0] = true;
    rom1[13][1] = 1;
    rom1[11][0] = true;
    rom1[11][1] = 2;

    rom1[8][0] = true;
    rom1[8][1] = 3;
    rom1[10][0] = true;
    rom1[10][1] = 4;

    rom1[3][0] = true;
    rom1[3][1] = 5;

    rom1[16][0] = true;
    rom1[16][1] = 6;

    rom1[21][0] = 2;
}

void Floor::createfloor()
{
    r1 = new RoomBattle(map, 1, pers, floor);
    r2 = new RoomBattle(map, 2, pers, floor);
    r3 = new RoomBattle(map, 2, pers, floor);
    r4 = new RoomBattle(map, 2, pers, floor);
    r5 = new RoomBattle(map, 3, pers, floor);
    r6 = new RoomBattle(map, 3, pers, floor);
    /*
    r7 = new RoomBattle(map, x, pers);
    r8 = new RoomBattle(map, x, pers);
    r9 = new RoomBattle(map, x, pers);
    r10 = new RoomBattle(map, x, pers);
    */
}

void Floor::on_pushButton_clicked()
{
    if (rom1[num-1][0] == 1)
    switch (rom1[num-1][1])
    {
        case 1 : {r1->show(); break;}
        case 2 : {r2->show(); break;}
        case 3 : {r3->show(); break;}
        case 4 : {r4->show(); break;}
        case 5 : {r5->show(); break;}
        case 6 : {r6->show(); break;}
        case 7 : {r7->show(); break;}
        case 8 : {r8->show(); break;}
        case 9 : {r9->show(); break;}
        case 10 : {r10->show(); break;}
    }
    if (rom1[num-1][0] == 2)
    {
        map->show();
    }
    hide();
}
