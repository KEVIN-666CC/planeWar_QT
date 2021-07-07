#ifndef MENU_H
#define MENU_H
#include <startgame.h>
#include <QDialog>
namespace Ui{class Menu;}

class Menu:public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
        ~Menu();

    public slots:
        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

    private:
        Ui::Menu *ui;

    signals:
        void returnWindow();


};

#endif // MENU_H
