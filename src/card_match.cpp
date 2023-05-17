#include <vector>
#include "card.cpp"
using namespace std;

struct CardMatchGame {
    int height;
    int width;
    vector<vector<Card>> card_grid;

    int score;
    int remaining_tries;

    Card* first_clicked;
    Card* second_clicked;

    explicit CardMatchGame(int _height=5, int _width=6, int _remaining_tries=50) {
        height = _height;
        width = _width;
        remaining_tries = _remaining_tries;
        score = 0;
        first_clicked = nullptr;
        second_clicked = nullptr;

        card_grid = vector<vector<Card>> (height, vector<Card>(width, Card("empty")));

        initialize_cards();
    }

    void initialize_cards();

    bool end() const {
        return remaining_tries <= 0;
    }

    bool clickable(Card& card) const {
        if(end()) return false;
        if(!card.active) return false;
        if(card.clicked) return false;
        return true;
    }

    bool click(int row, int column) {
        Card& card = card_grid[row][column];

        if(!clickable(card)) throw "Card is not clickable";

        card.setClicked(true);

        if(first_clicked == nullptr) {
            first_clicked = &card;
            return false;
        }
        else {
            second_clicked = &card;
            return true;
        }
    }

    void match() {
        first_clicked->setClicked(false);
        second_clicked->setClicked(false);

        if(first_clicked->content == second_clicked->content) {
            second_clicked->setActive(false);
            first_clicked->setActive(false);

            score++;
        }

        first_clicked = nullptr;
        second_clicked = nullptr;

        remaining_tries--;
    }

};