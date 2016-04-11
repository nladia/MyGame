#include "startroom.h"
#include "ui_startroom.h"

StartRoom::StartRoom(QWidget *parent, Pers *perss) :
    QMainWindow(parent),
    ui(new Ui::StartRoom)
{
    pers = perss;
    ui->setupUi(this);
    renew();

    map = new Map(this, pers);

}

StartRoom::~StartRoom()
{
    delete ui;
}

void StartRoom::on_pushButton_5_clicked()
{
    if (pers->expp() >= pers->lvlupexp())
    {
        pers->gexp(-1 * pers->lvlupexp());
        pers->levlup();
        renew();
    }
}

void StartRoom::on_pushButton_6_clicked()
{
    if (pers->expp() >= 4)
    {
        pers->gexp(-4);
        pers->dmg(-40);
        renew();
    }
}


void StartRoom::on_pushButton_clicked()
{
    map->show();
    hide();
}




void StartRoom::renew()
{
    ui->label_2->setText(QString("HP : %1").arg(pers->hpp()));
    ui->mina->setText(QString("MinAtk : %1").arg(pers->minattk()));
    ui->maxa->setText(QString("MaxAtk : %1").arg(pers->maxattk()));
    ui->label_6->setText(QString("lvl : %1").arg(pers->levl()));
    ui->exp->setText(QString("currect exp : %1").arg(pers->expp()));

    ui->pushButton_5->setText(QString("lvlup (%1 exp)").arg(pers->lvlupexp()));
}


void StartRoom::showEvent ( QShowEvent * event)
{
   renew();
}

