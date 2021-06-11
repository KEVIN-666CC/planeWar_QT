#include "mainscene.h"
#include <QApplication>
#include"startgame.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartGame st;
    st.show();
    return a.exec();
}

