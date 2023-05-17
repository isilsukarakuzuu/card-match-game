#include <vector>
#include "card.cpp"
using namespace std;

struct CardMatchGame {
    int height;
    int width;
    vector<vector<Card>> card_grid;

    int score;
    int remaining_tries;

    Card* last_clicked;

    explicit CardMatchGame(int _height=5, int _width=6, int _remaining_tries=50) {
        height = _height;
        width = _width;
        remaining_tries = _remaining_tries;
        score = 0;
        last_clicked = nullptr;

        card_grid = vector<vector<Card>> (height, vector<Card>(width, Card("empty")));

        initialize_cards();
    }

    void initialize_cards();

    bool end();

    bool clickable(int row, int column);

    bool click(int row, int column);


};