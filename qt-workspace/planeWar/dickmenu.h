#ifndef DICKMENU_H
#define DICKMENU_H
#include"startgame.h"
#include <QDialog>

namespace Ui {
class DickMenu;
}

class DickMenu : public QDialog
{
    Q_OBJECT

public:
    explicit DickMenu(QWidget *parent = nullptr);
    ~DickMenu();

public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DickMenu *ui;

signals:
    void returnWindow();
};

#endif // DICKMENU_H

