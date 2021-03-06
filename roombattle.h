#ifndef ROOMBATTLE_H
#define ROOMBATTLE_H

#include <QMainWindow>
#include "room.h"
#include "looser.h"
#include "loot.h"

namespace Ui {
class RoomBattle;
}

class RoomBattle : public QMainWindow
{
    Q_OBJECT
    Room *roomh;
    QWidget *par;
    Pers *pers;
    Loot *lot;

public:
    explicit RoomBattle(QWidget *parent = 0, int x = 0, Pers *h = 0, int floor = 0);
    bool alive();
    ~RoomBattle();

private slots:
    void on_pushButton_clicked();
    void winloot();
    void on_pushButton_2_clicked();
    void showEvent ( QShowEvent * event);
    void renew();


private:
    Ui::RoomBattle *ui;
};

#endif // ROOMBATTLE_H
