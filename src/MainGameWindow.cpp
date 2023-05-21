#include "../include/MainGameWindow.h"
#include "../include/Shuffle.h"

std::vector<std::vector<QString>> cardGrid;

MainGameWindow::MainGameWindow(QWidget *parent) : QWidget(parent)
{
    cardGrid = getShuffledWords(5, 6);
    scoreLabel = new QLabel("Score: 0", this);
    triesLabel = new QLabel("Tries: 50", this);
    newGameButton = new QPushButton("New Game", this);
    gridLayout = new GridLayout(this, cardGrid);
    topLayout = new QHBoxLayout();

    topLayout->addWidget(scoreLabel);
    topLayout->addWidget(triesLabel);
    topLayout->addWidget(newGameButton);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(gridLayout);
    setLayout(mainLayout);

    connect(newGameButton, &QPushButton::clicked, this, &MainGameWindow::startNewGame);

}


void MainGameWindow::startNewGame()
{
    cardGrid = getShuffledWords(5, 6);
    gridLayout->build();
}
