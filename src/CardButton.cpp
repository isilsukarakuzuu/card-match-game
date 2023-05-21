#include "../include/CardButton.h"
#include "../include/GridLayout.h"
#include <QMessageBox>

CardButton::CardButton(QWidget *parent) : QPushButton(parent){
    resetButton();
    connect(this, &QPushButton::clicked, this, &CardButton::click);
}

void CardButton::resetButton() {
    buttonText = QString("               ");
    active = true;
    clicked = false;
}

void CardButton::click()
{
    if(!active && clicked) return;
    GridLayout* grid = (GridLayout*)parent();
    grid->click(this);
    setText(buttonText);
}

void CardButton::unclick() {

}

void CardButton::deactivate() {

}

