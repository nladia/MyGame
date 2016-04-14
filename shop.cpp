#include "shop.h"
#include "ui_shop.h"

Shop::Shop(QWidget *parent, Pers *prs, bool weap, bool abil, Ability *abilit) :
    QMainWindow(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
    pers = prs;
    map = parent;
    weapon = weap;
    ability = abil;
    abilki = abilit;
    ui->pushButton->hide();
    ui->pushButton_2->hide();

    ui->exp->setText(QString("currect exp : %1").arg(pers->expp()));

    if (ability == true) ui->pushButton_2->show();
    if (weapon == true) ui->pushButton->show();
}

Shop::~Shop()
{
    delete ui;
}

void Shop::on_pushButton_clicked()
{
    if (pers->expp() >= 15)
    {
        ui->pushButton->hide();
        pers->gexp(-15);
        Loot *lot = new Loot(map, pers);
        lot->shop();
        lot->show();
        hide();

    }

}

void Shop::on_pushButton_3_clicked()
{
    map->show();
    hide();
}

void Shop::on_pushButton_2_clicked()
{
    if (pers->expp() >= 4)
    {
        pers->gexp(0);
        abilki->abilitybuy(rand() % 3, rand() % 5);
        abilki->remap(this);
        abilki->show();
        hide();

    }
}

void Shop::showEvent( QShowEvent * event)
{
    ui->exp->setText(QString("currect exp : %1").arg(pers->expp()));
}
