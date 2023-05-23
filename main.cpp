/*
 * Card Match Game
 * authors: Atakan Yasar, Isil Su Karakuzu
 * date: 2020/05/22
 *
 * description: This is a simple card match game. The purpose of this game is to find the same cards.
 * The number of cards is 30 and there are 15 different texts. The game is won when all cards are matched.
 * The game is lost when the number of tries is 0. The score is number of card pairs matched.
 * The game is played by clicking on the cards. When the game is over, the user can start a new game by
 * clicking the new game button.
 */

#include <QApplication>
#include "include/MainGameWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainGameWindow gameWindow;
    gameWindow.show();

    return app.exec();
}
