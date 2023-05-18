#include <QGridLayout>
#include <QLabel>
#include "card_button.cpp"
#include "card_match.cpp"

class CardMatchGrid : public QGridLayout {
public:
    CardMatchGame *game;

    explicit CardMatchGrid(CardMatchGame& _game, QWidget *parent = nullptr) : QGridLayout(parent) {
        game = &_game;
        for(int i = 0; i < game->height; i++){
            for(int j = 0; j < game->width; j++){
                CardButton *button = new CardButton(game->card_grid[i][j]);
                addWidget(button, i, j);
            }
        }
    }
};
