#include "../include/GridLayout.h"

GridLayout::GridLayout(QWidget *parent, std::vector<std::vector<QString> > &cardGrid, int height, int width)
: QWidget(parent), cardGrid(cardGrid), height(height), width(width)
{
    layout = new QGridLayout(this);
    for (int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            CardButton *button = new CardButton(this, QString("               "));
            layout->addWidget(button, i, j);
        }
    }
    build();
}

void GridLayout::build()
{
    for (int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            QString strValue = cardGrid[i][j];
            CardButton *button = (CardButton*)layout->itemAtPosition(i, j)->widget();
            button->buttonText = strValue;
            button->setText(QString("               "));
        }
    }
    setLayout(layout);
}
