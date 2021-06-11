#include "dickmenu.h"
#include "ui_dickmenu.h"
#include<QDebug>

DickMenu::DickMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DickMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("游戏失败");
}

DickMenu::~DickMenu()
{
    delete ui;
}

void DickMenu::on_pushButton_clicked()
{
    StartGame *st;
    st=new StartGame();
    st->show();
    this->close();
    emit returnWindow();
}

void DickMenu::on_pushButton_2_clicked()
{
    exit(0);
}

