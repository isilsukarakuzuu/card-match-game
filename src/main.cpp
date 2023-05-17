#include <iostream>
#include "card_match.cpp"
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
using namespace std;

int main(int argc, char *argv[]){
    CardMatchGame game;
    game.initialize_cards();

    while(!game.end()){
        int row, column;
        cin >> row >> column;
        if(game.clickable(row, column)) {

            game.click(row, column);
            game.match();

            cout << game.card_grid[row][column].content << endl;
            cerr << "Score: " << game.score << endl;
            cerr << "Remaining tries: " << game.remaining_tries << endl;

        }
        else {
            cerr << "Card is not clickable" << endl;
        }
    }
//    QApplication app(argc, argv);
//    QMainWindow *mw = new QMainWindow;
//    QLabel *ql = new QLabel;
//
//    ql->setText("Its a project.");
//
//    mw->setCentralWidget(ql);
//    mw->setWindowTitle("Hello!");
//    mw->show();
//    return app.exec();
}