#ifndef STARTGAME_H
#define STARTGAME_H
#include<QString>
#include <QDialog>
#include"mainscene.h"

namespace Ui {
class StartGame;
}

class StartGame : public QDialog
{
    Q_OBJECT

public:
    explicit StartGame(QWidget *parent = nullptr);
    ~StartGame();

    QString MapStyle=":/res/img_bg_level_1.jpg";
    QString EnemyPlaneStyle=QString(":/res/img-plane_%1.png").arg(rand()%10);

    void changeMap();


public slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonStart_Design_clicked();

    void on_pushButtonStart_Exit_clicked();

    void on_pushButtonSureDeSign_clicked();
private slots:

private:
    Ui::StartGame *ui;
};

#endif // STARTGAME_H

