#include "roombattle.h"
#include "ui_roombattle.h"


RoomBattle::RoomBattle(QWidget *parent, int x, Pers *persb, int floor) :
    QMainWindow(parent),
    ui(new Ui::RoomBattle)
{
    pers = persb;
    ui->setupUi(this);
    par = parent;
    roomh = new Room(x, persb, floor);

    renew();
}

RoomBattle::~RoomBattle()
{
    delete ui;
}

void RoomBattle::on_pushButton_clicked()
{
    int win;
    win = roomh->battle();
    renew();

    if (win == 1)
        {
            this->winloot();
        }
    if (win == -1)
        {
        Looser *l = new Looser(this);
        l->show();
        hide();
        }
}
void RoomBattle::on_pushButton_2_clicked()
{
    /*
    roomh->pers->dmg(30);
    par->show();
    hide();
    */
}

void RoomBattle::winloot()
{

    roomh->pers->gexp(roomh->monstr->gexp());
    Loot *lot = new Loot(par, pers, roomh->monstr->gexp());
    lot->show();
    hide();
}

bool RoomBattle::alive()
{
    return roomh->alive;
}

void RoomBattle::renew()
{
    ui->monster_hp->setText(QString("HP : %1").arg(roomh->monstr->hpp()));
    ui->pers_hp->setText(QString("HP : %1 / %2").arg(pers->hpp()).arg(pers->maxhpp()));
    ui->mdmg->setText(QString("Damage : %1").arg(roomh->attkm()));
    ui->Pdmg->setText(QString("Damage : %1").arg(roomh->attkp()));
    ui->Roll->setText(QString("Roll : %1").arg(roomh->roll()));
    ui->maxatk->setText(QString("MaxAttk : %1").arg(roomh->monstr->maxattk()));
    ui->Minatk->setText(QString("MinAttk : %1").arg(roomh->monstr->minattk()));
    ui->Minatkp->setText(QString("MinAttk : %1").arg(roomh->pers->minattk()));
    ui->Maxatkp->setText(QString("MaxAttk : %1").arg(roomh->pers->maxattk()));
}

void RoomBattle::showEvent(QShowEvent *event)
{
    renew();
    ui->mdmg->setText(QString("Damage : 0"));
    ui->Pdmg->setText(QString("Damage : 0"));
    ui->Roll->setText(QString("Roll : 0"));
}
