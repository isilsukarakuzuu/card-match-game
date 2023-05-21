#include "../include/GridLayout.h"

GridLayout::GridLayout(QWidget *parent, std::vector<std::vector<QString>>& cardGrid) : QWidget(parent), cardGrid(cardGrid)
{
    layout = new QGridLayout(this);
    build();
}

void GridLayout::build()
{
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            QString strValue = cardGrid[i][j];
            CardButton *button = new CardButton(this, strValue);
            button->setText(QString("               "));
            buttons.append(button);
            layout->addWidget(button, i, j);
        }
    }
    setLayout(layout);
}
