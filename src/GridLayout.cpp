#include "../include/GridLayout.h"

GridLayout::GridLayout(QWidget *parent, std::vector<std::vector<QString> > &cardGrid, int height, int width)
: QWidget(parent), cardGrid(cardGrid), height(height), width(width)
{
    layout = new QGridLayout(this);
    for (int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            CardButton *button = new CardButton(this);
            layout->addWidget(button, i, j);
        }
    }
    build();

    connect(match_timer, &QTimer::timeout, this, &GridLayout::match);
}

void GridLayout::build()
{
    first_clicked = nullptr;
    second_clicked = nullptr;
    match_timer = new QTimer(this);

    for (int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            QString strValue = cardGrid[i][j];
            CardButton *button = (CardButton*)layout->itemAtPosition(i, j)->widget();
            button->buttonText = strValue;
            button->resetButton();
        }
    }
    setLayout(layout);
}

void GridLayout::click(CardButton *button) {

    if(first_clicked == nullptr) {
        first_clicked = button;
    }
    else if (second_clicked == nullptr){
        second_clicked = button;
        QTimer::singleShot(1000, this, &GridLayout::match);
    }
}

void GridLayout::match() {
    if(first_clicked == nullptr || second_clicked == nullptr) return;

    if(first_clicked->buttonText == second_clicked->buttonText) {
        second_clicked->deactivate();
        first_clicked->deactivate();

//        score++;
    }
    else {
        first_clicked->unclick();
        second_clicked->unclick();
    }

    first_clicked = nullptr;
    second_clicked = nullptr;

//    remaining_tries--;
}
