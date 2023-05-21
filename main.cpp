#include <QApplication>
#include "include/MainGameWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainGameWindow gameWindow;
    gameWindow.show();

    return app.exec();
}
