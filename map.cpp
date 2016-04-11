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
    if (floor->alive(8))
    {
        floor->enter(8);
        hide();
        ui->b8->setText("Cleared");
    }
    if (floor->exist(3))
        ui->b3->show();
    if (floor->exist(7))
        ui->b7->show();
    if (floor->exist(9))
        ui->b9->show();


}

void Map::on_b3_clicked()
{
    if (floor->alive(3))
    {
        floor->enter(3);
        hide();
        ui->b3->setText("Cleared");
    }
    if (floor->exist(2))
        ui->b2->show();
    if (floor->exist(8))
        ui->b8->show();
    if (floor->exist(4))
        ui->b4->show();

}

void Map::on_b14_clicked()
{
    if (floor->alive(14))
    {
        floor->enter(14);
        hide();
        ui->b14->setText("Cleared");
    }
    if (floor->exist(9))
        ui->b9->show();
    if (floor->exist(15))
        ui->b15->show();
    if (floor->exist(19))
        ui->b19->show();

}

void Map::on_b9_clicked()
{
    if (floor->alive(9))
    {
        floor->enter(9);
        hide();
        ui->b9->setText("Cleared");
    }
    if (floor->exist(10))
        ui->b10->show();
    if (floor->exist(14))
        ui->b14->show();
    if (floor->exist(4))
        ui->b4->show();
    if (floor->exist(8))
        ui->b8->show();
}

void Map::on_b4_clicked()
{
    if (floor->alive(4))
    {
        floor->enter(4);
        hide();
        ui->b4->setText("Cleared");
    }
    if (floor->exist(3))
        ui->b3->show();
    if (floor->exist(9))
        ui->b9->show();
    if (floor->exist(5))
        ui->b5->show();
}

void Map::on_b12_clicked()
{
    if (floor->alive(12))
    {
        floor->enter(12);
        hide();
        ui->b12->setText("Cleared");
    }
    if (floor->exist(11))
        ui->b11->show();
    if (floor->exist(17))
        ui->b17->show();
    if (floor->exist(7))
        ui->b7->show();


}

void Map::on_b11_clicked()
{
    if (floor->alive(11))
    {
        floor->enter(11);
        hide();
        ui->b11->setText("Cleared");
    }
    if (floor->exist(16))
        ui->b16->show();
    if (floor->exist(12))
        ui->b12->show();
    if (floor->exist(6))
        ui->b6->show();
}

void Map::on_b17_clicked()
{
    if (floor->alive(17))
    {
        floor->enter(17);
        hide();
        ui->b17->setText("Cleared");
    }
    if (floor->exist(12))
        ui->b12->show();
    if (floor->exist(16))
        ui->b16->show();
    if (floor->exist(22))
        ui->b22->show();
    if (floor->exist(18))
        ui->b18->show();
}



void Map::on_b1_clicked()
{
    if (floor->alive(1))
    {
        floor->enter(1);
        hide();
        ui->b1->setText("Cleared");
    }
    if (floor->exist(2))
        ui->b2->show();
    if (floor->exist(6))
        ui->b6->show();
}

void Map::on_b2_clicked()
{
    if (floor->alive(2))
    {
        floor->enter(2);
        hide();
        ui->b2->setText("Cleared");
    }
    if (floor->exist(3))
        ui->b3->show();
    if (floor->exist(1))
        ui->b1->show();
    if (floor->exist(7))
        ui->b7->show();
}

void Map::on_b5_clicked()
{
    if (floor->alive(5))
    {
        floor->enter(5);
        hide();
        ui->b5->setText("Cleared");
    }
    if (floor->exist(4))
        ui->b4->show();
    if (floor->exist(10))
        ui->b10->show();
}

void Map::on_b6_clicked()
{
    if (floor->alive(6))
    {
        floor->enter(6);
        hide();
        ui->b6->setText("Cleared");
    }
    if (floor->exist(1))
        ui->b1->show();
    if (floor->exist(7))
        ui->b7->show();
    if (floor->exist(11))
        ui->b11->show();
}

void Map::on_b7_clicked()
{
    if (floor->alive(7))
    {
        floor->enter(7);
        hide();
        ui->b7->setText("Cleared");
    }
    if (floor->exist(6))
        ui->b6->show();
    if (floor->exist(8))
        ui->b8->show();
    if (floor->exist(2))
        ui->b2->show();
    if (floor->exist(12))
        ui->b12->show();
}

void Map::on_b10_clicked()
{
    if (floor->alive(10))
    {
        floor->enter(10);
        hide();
        ui->b10->setText("Cleared");
    }
    if (floor->exist(5))
        ui->b5->show();
    if (floor->exist(9))
        ui->b9->show();
    if (floor->exist(15))
        ui->b15->show();
}

void Map::on_b15_clicked()
{
    if (floor->alive(15))
    {
        floor->enter(15);
        hide();
        ui->b15->setText("Cleared");
    }
    if (floor->exist(10))
        ui->b10->show();
    if (floor->exist(14))
        ui->b14->show();
    if (floor->exist(20))
        ui->b20->show();
}

void Map::on_b16_clicked()
{
    if (floor->alive(16))
    {
        floor->enter(16);
        hide();
        ui->b16->setText("Cleared");
    }
    if (floor->exist(11))
        ui->b11->show();
    if (floor->exist(17))
        ui->b17->show();
    if (floor->exist(21))
        ui->b21->show();
}

void Map::on_b18_clicked()
{
    if (floor->alive(18))
    {
        floor->enter(18);
        hide();
        ui->b18->setText("Cleared");
    }
    if (floor->exist(19))
        ui->b19->show();
    if (floor->exist(17))
        ui->b17->show();
    if (floor->exist(23))
        ui->b23->show();
}

void Map::on_b19_clicked()
{
    if (floor->alive(19))
    {
        floor->enter(19);
        hide();
        ui->b19->setText("Cleared");
    }
    if (floor->exist(20))
        ui->b20->show();
    if (floor->exist(14))
        ui->b14->show();
    if (floor->exist(24))
        ui->b24->show();
    if (floor->exist(18))
        ui->b18->show();
}

void Map::on_b20_clicked()
{
    if (floor->alive(20))
    {
        floor->enter(20);
        hide();
        ui->b20->setText("Cleared");
    }
    if (floor->exist(25))
        ui->b25->show();
    if (floor->exist(19))
        ui->b19->show();
    if (floor->exist(15))
        ui->b15->show();
}

void Map::on_b21_clicked()
{
    if (floor->alive(21))
    {
        floor->enter(21);
        hide();
        ui->b21->setText("Cleared");
    }
    if (floor->exist(16))
        ui->b16->show();
    if (floor->exist(22))
        ui->b22->show();
    if (floor->exist(26))
        ui->b26->show();
}

void Map::on_b22_clicked()
{
    if (floor->alive(22))
    {
        floor->enter(22);
        hide();
        ui->b22->setText("Cleared");
    }
    if (floor->exist(21))
        ui->b21->show();
    if (floor->exist(27))
        ui->b27->show();
    if (floor->exist(23))
        ui->b23->show();
    if (floor->exist(17))
        ui->b17->show();
}

void Map::on_b23_clicked()
{
    if (floor->alive(23))
    {
        floor->enter(23);
        hide();
        ui->b23->setText("Cleared");
    }
    if (floor->exist(22))
        ui->b22->show();
    if (floor->exist(28))
        ui->b28->show();
    if (floor->exist(24))
        ui->b24->show();
    if (floor->exist(18))
        ui->b18->show();
}

void Map::on_b24_clicked()
{
    if (floor->alive(24))
    {
        floor->enter(24);
        hide();
        ui->b24->setText("Cleared");
    }
    if (floor->exist(23))
        ui->b23->show();
    if (floor->exist(29))
        ui->b29->show();
    if (floor->exist(25))
        ui->b25->show();
    if (floor->exist(19))
        ui->b19->show();
}

void Map::on_b25_clicked()
{
    if (floor->alive(25))
    {
        floor->enter(25);
        hide();
        ui->b25->setText("Cleared");
    }
    if (floor->exist(30))
        ui->b30->show();
    if (floor->exist(24))
        ui->b24->show();
    if (floor->exist(20))
        ui->b20->show();
}

void Map::on_b26_clicked()
{
    if (floor->alive(26))
    {
        floor->enter(26);
        hide();
        ui->b26->setText("Cleared");
    }
    if (floor->exist(27))
        ui->b17->show();
    if (floor->exist(21))
        ui->b21->show();
}

void Map::on_b27_clicked()
{
    if (floor->alive(27))
    {
        floor->enter(27);
        hide();
        ui->b27->setText("Cleared");
    }
    if (floor->exist(26))
        ui->b26->show();
    if (floor->exist(28))
        ui->b28->show();
    if (floor->exist(22))
        ui->b22->show();
}

void Map::on_b28_clicked()
{
    if (floor->alive(28))
    {
        floor->enter(28);
        hide();
        ui->b28->setText("Cleared");
    }
    if (floor->exist(29))
        ui->b29->show();
    if (floor->exist(27))
        ui->b27->show();
    if (floor->exist(23))
        ui->b23->show();
}

void Map::on_b29_clicked()
{
    if (floor->alive(29))
    {
        floor->enter(29);
        hide();
        ui->b29->setText("Cleared");
    }
    if (floor->exist(30))
        ui->b30->show();
    if (floor->exist(24))
        ui->b24->show();
    if (floor->exist(28))
        ui->b28->show();
}

void Map::on_b30_clicked()
{
    if (floor->alive(30))
    {
        floor->enter(30);
        hide();
        ui->b30->setText("Cleared");
    }
    if (floor->exist(25))
        ui->b25->show();
    if (floor->exist(29))
        ui->b29->show();
}
