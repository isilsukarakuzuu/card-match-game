#include "../include/MainGameWindow.h"
#include "../include/Shuffle.h"

MainGameWindow::MainGameWindow(QWidget *parent) : QWidget(parent)
{
    cardGrid = getShuffledWords(5, 6);
    scoreLabel = new QLabel("", this);
    triesLabel = new QLabel("", this);
    newGameButton = new QPushButton("New Game", this);
    gridLayout = new GridLayout(this, cardGrid);
    topLayout = new QHBoxLayout();

    setScoreAndTries();
    topLayout->addWidget(scoreLabel);
    topLayout->addWidget(triesLabel);
    topLayout->addWidget(newGameButton);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(gridLayout);
    setLayout(mainLayout);

    connect(newGameButton, &QPushButton::clicked, this, &MainGameWindow::startNewGame);

}

void MainGameWindow::setScoreAndTries()
{
    scoreLabel->setText("Score: " + QString::number(gridLayout->score));
    triesLabel->setText("Tries: " + QString::number(gridLayout->tries));
}

void MainGameWindow::startNewGame()
{
    cardGrid = getShuffledWords(5, 6);
    gridLayout->build();
    setScoreAndTries();
}
