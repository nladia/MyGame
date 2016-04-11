#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent, Pers *prs) :
    QMainWindow(parent),
    ui(new Ui::Map)
{

    ui->setupUi(this);
    par = parent;
    pers = prs;
    floornum = 0;


    bindbuttons();
    hiden();

    floor = new Floor(this, pers, 1, floornum);
    shop = new Shop(this, pers, true, false);

    if (floor->exist(8))
        ui->b8->show();
    if (floor->exist(18))
        ui->b18->show();
    if (floor->exist(12))
        ui->b12->show();
    if (floor->exist(14))
        ui->b14->show();
}

Map::~Map()
{
    delete ui;
    delete floor;
}

void Map::hiden()
{
    for (int i = 1; i < 31; i++)
    {
        if (i == 13) continue;
        else
        {
            button[i]->hide();
            button[i]->setText("Room");
        }
    }
    /*
    ui->b1->hide();
    ui->b2->hide();
    ui->b3->hide();
    ui->b4->hide();
    ui->b5->hide();
    ui->b6->hide();
    ui->b7->hide();
    ui->b8->hide();
    ui->b9->hide();
    ui->b10->hide();
    ui->b11->hide();
    ui->b12->hide();
    ui->b14->hide();
    ui->b15->hide();
    ui->b16->hide();
    ui->b17->hide();
    ui->b18->hide();
    ui->b19->hide();
    ui->b20->hide();
    ui->b21->hide();
    ui->b22->hide();
    ui->b23->hide();
    ui->b24->hide();
    ui->b25->hide();
    ui->b26->hide();
    ui->b27->hide();
    ui->b28->hide();
    ui->b29->hide();
    ui->b30->hide();

    ui->b1->setText("Room");
    ui->b2->setText("Room");
    ui->b3->setText("Room");
    ui->b4->setText("Room");
    ui->b5->setText("Room");
    ui->b6->setText("Room");
    ui->b7->setText("Room");
    ui->b8->setText("Room");
    ui->b9->setText("Room");
    ui->b10->setText("Room");
    ui->b11->setText("Room");
    ui->b12->setText("Room");
    ui->b14->setText("Room");
    ui->b15->setText("Room");
    ui->b16->setText("Room");
    ui->b17->setText("Room");
    ui->b18->setText("Room");
    ui->b19->setText("Room");
    ui->b20->setText("Room");
    ui->b21->setText("Room");
    ui->b22->setText("Room");
    ui->b23->setText("Room");
    ui->b24->setText("Room");
    ui->b25->setText("Room");
    ui->b26->setText("Room");
    ui->b27->setText("Room");
    ui->b28->setText("Room");
    ui->b29->setText("Room");
    ui->b30->setText("Room");
*/
}

void Map::bindbuttons()
{
    button[1] = ui->b1;
    button[2] = ui->b2;
    button[3] = ui->b3;
    button[4] = ui->b4;
    button[5] = ui->b5;
    button[6] = ui->b6;
    button[7] = ui->b7;
    button[8] = ui->b8;
    button[9] = ui->b9;
    button[10] = ui->b10;
    button[11] = ui->b11;
    button[12] = ui->b12;
//    button[13] = ui->b13;
    button[14] = ui->b14;
    button[15] = ui->b15;
    button[16] = ui->b16;
    button[17] = ui->b17;
    button[18] = ui->b18;
    button[19] = ui->b19;
    button[20] = ui->b20;
    button[21] = ui->b21;
    button[22] = ui->b22;
    button[23] = ui->b23;
    button[24] = ui->b24;
    button[25] = ui->b25;
    button[26] = ui->b26;
    button[27] = ui->b27;
    button[28] = ui->b28;
    button[29] = ui->b29;
    button[30] = ui->b30;


}

void Map::simplebutton(int i)
{
    if (floor->alive(i))
    {
        floor->enter(i);
        hide();
    }

    button[i]->setText("Cleared");

    if ((i % 5 != 1) && (i-1 != 13))
        if (floor->exist(i-1))
            button[i-1]->show();
    if ((i % 5 != 0) && (i+1 != 13))
        if (floor->exist(i+1))
            button[i+1]->show();
    if ((i > 5)&& (i-5 != 13))
        if (floor->exist(i - 5))
            button[i-5]->show();
    if ((i < 26)&& (i+5 != 13))
        if (floor->exist(i+5))
            button[i+5]->show();
}

void Map::on_pushButton_clicked()
{
    shop->show();
    hide();
}

void Map::on_pushButton_31_clicked()
{
    delete floor;
    delete shop;
    hiden();
    floornum++;
    ui->pushButton_31->setText(QString("NG+%1").arg(floornum + 1));
    floor = new Floor(this, pers, 1, floornum);
    shop = new Shop(this, pers, rand() % 2 == 1, rand() % 2 == 1);

    if (floor->exist(8))
        ui->b8->show();
    if (floor->exist(18))
        ui->b18->show();
    if (floor->exist(12))
        ui->b12->show();
    if (floor->exist(14))
        ui->b14->show();
}

void Map::on_start_clicked()
{
    par->show();
    hide();
}




void Map::on_b8_clicked()
{
  simplebutton(8);


}

void Map::on_b3_clicked()
{
    simplebutton(3);

}

void Map::on_b14_clicked()
{
    simplebutton(14);

}

void Map::on_b9_clicked()
{
    simplebutton(9);
}

void Map::on_b4_clicked()
{
    simplebutton(4);
}

void Map::on_b12_clicked()
{
    simplebutton(12);
}

void Map::on_b11_clicked()
{
    simplebutton(11);
}

void Map::on_b17_clicked()
{
    simplebutton(17);
}



void Map::on_b1_clicked()
{
    simplebutton(1);
}

void Map::on_b2_clicked()
{
    simplebutton(2);
}

void Map::on_b5_clicked()
{
    simplebutton(5);
}

void Map::on_b6_clicked()
{
    simplebutton(6);
}

void Map::on_b7_clicked()
{
    simplebutton(7);
}

void Map::on_b10_clicked()
{
    simplebutton(10);
}

void Map::on_b15_clicked()
{
    simplebutton(15);
}

void Map::on_b16_clicked()
{
    simplebutton(16);
}

void Map::on_b18_clicked()
{
    simplebutton(18);
}

void Map::on_b19_clicked()
{
    simplebutton(19);
}

void Map::on_b20_clicked()
{
    simplebutton(20);
}

void Map::on_b21_clicked()
{
    simplebutton(21);
}

void Map::on_b22_clicked()
{
    simplebutton(22);
}

void Map::on_b23_clicked()
{
    simplebutton(23);
}

void Map::on_b24_clicked()
{
    simplebutton(24);
}

void Map::on_b25_clicked()
{
    simplebutton(25);
}

void Map::on_b26_clicked()
{
    simplebutton(26);
}

void Map::on_b27_clicked()
{
    simplebutton(27);
}

void Map::on_b28_clicked()
{
    simplebutton(28);
}

void Map::on_b29_clicked()
{
    simplebutton(29);
}

void Map::on_b30_clicked()
{
    simplebutton(30);
}
