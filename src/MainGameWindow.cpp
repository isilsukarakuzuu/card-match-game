#include "../include/MainGameWindow.h"

MainGameWindow::MainGameWindow(QWidget *parent) : QWidget(parent)
{
    scoreLabel = new QLabel("", this);
    triesLabel = new QLabel("", this);
    newGameButton = new QPushButton("New Game", this);
    gridLayout = new GridLayout(this);
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
    gridLayout->build();
    setScoreAndTries();
}

void MainGameWindow::winGame()
{
    QMessageBox::information(this, "Congratulations", "You Won!");
}

void MainGameWindow::loseGame()
{
    gridLayout->openAllCards();
    QMessageBox::information(this, "Game Over", "You Lose!");
}
