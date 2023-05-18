#include <iostream>
#include "card_match.cpp"
#include "main_window.cpp"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]){

    CardMatchGame game;
    game.initialize_cards();

    QApplication app(argc, argv);
    CardMatchMainWindow *main_window = new CardMatchMainWindow(game);
    main_window->show();

//    while(!game.end()){
//        int row, column;
//        cin >> row >> column;
//        if(game.clickable(row, column)) {
//
//            game.click(row, column);
//            game.match();
//
//            cout << game.card_grid[row][column].content << endl;
//            cerr << "Score: " << game.score << endl;
//            cerr << "Remaining tries: " << game.remaining_tries << endl;
//
//        }
//        else {
//            cerr << "Card is not clickable" << endl;
//        }
//    }

    return app.exec();
}