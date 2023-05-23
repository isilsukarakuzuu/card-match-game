#include "../include/CardButton.h"
#include "../include/GridLayout.h"
#include <QMessageBox>

CardButton::CardButton(QWidget *parent) : QPushButton(parent)
{
    resetButton();
    connect(this, &QPushButton::clicked, this, &CardButton::click);
}

void CardButton::resetButton()
{
    setText(QString("               "));
    active = true;
    clicked = false;
    setEnabled(true);
}


// A button is clickable if it is active, not clicked, and not one of the first or second clicked button
bool CardButton::clickable()
{
    GridLayout* grid = (GridLayout*)parent();

    if(!active || clicked) return false;
    if(grid->first_clicked == this) return false;
    if(grid->second_clicked == this) return false;
    if(grid->first_clicked != nullptr && grid->second_clicked != nullptr) return false;
    return true;
}

void CardButton::click()
{
    if(!clickable()) return;

    GridLayout* grid = (GridLayout*)parent();

    clicked = true;
    setText(buttonText);
    grid->click(this);
}

void CardButton::unclick()
{
    clicked = false;
    setText(QString("               "));
}

void CardButton::deactivate()
{
    active = false;
    setEnabled(false);
}

