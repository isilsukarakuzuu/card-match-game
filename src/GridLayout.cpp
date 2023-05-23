#include "../include/GridLayout.h"
#include "../include/MainGameWindow.h"
#include "../include/Shuffle.h"

/*
 * GridLayout constructor
 * Sets the height, width, score, and tries
 * Creates the grid layout, creates and connects CardButtons to the grid layout
 * Connects the timer to the match slot
 */
GridLayout::GridLayout(QWidget *parent, int height, int width, int score, int tries)
    : QWidget(parent), height(height), width(width), score(score), tries(tries)
{
    layout = new QGridLayout(this);
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            CardButton *button = new CardButton(this);
            layout->addWidget(button, i, j);
        }
    }
    build();

    connect(match_timer, &QTimer::timeout, this, &GridLayout::matchingHandler);
}

// Resets the score and tries
// Shuffles the words and assigns them to the CardButtons texts
void GridLayout::build()
{
    score = 0;
    tries = 50;
    first_clicked = nullptr;
    second_clicked = nullptr;
    match_timer = new QTimer(this);

    cardGrid = getShuffledWords(height, width);

    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            QString strValue = cardGrid[i][j];
            CardButton *button = (CardButton*)layout->itemAtPosition(i, j)->widget();
            button->buttonText = strValue;
            button->resetButton();
        }
    }
    setLayout(layout);
}

// Checks if the first and second clicked CardButtons match
// Starts the timer to check for a match
void GridLayout::clickHandlerForGrid(CardButton *button)
{

    if(first_clicked == nullptr)
    {
        first_clicked = button;
    }
    else if (second_clicked == nullptr)
    {
        second_clicked = button;
        QTimer::singleShot(750, this, &GridLayout::matchingHandler);
    }
}

void GridLayout::matchingHandler()
{
    if(first_clicked == nullptr || second_clicked == nullptr) return;

    // If the two cards match, deactivate them and increment the score
    if(first_clicked->buttonText == second_clicked->buttonText)
    {
        second_clicked->deactivate();
        first_clicked->deactivate();

        score++;
    }
    // If the two cards don't match, unclick them
    else
    {
        first_clicked->unclick();
        second_clicked->unclick();
    }

    first_clicked = nullptr;
    second_clicked = nullptr;

    tries--;

    MainGameWindow* mainGameWindow = (MainGameWindow*)parent();
    mainGameWindow->setScoreAndTries();

    // win state: all cards are opened
    if(score == height * width / 2)
    {
        mainGameWindow->winGame();
    }
    // lose state: no more tries left
    else if(tries == 0)
    {
        mainGameWindow->loseGame();
    }
}

void GridLayout::openAllCards()
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            CardButton *button = (CardButton*)layout->itemAtPosition(i, j)->widget();
            button->setText(button->buttonText);
            button->setEnabled(false);
        }
    }
}
