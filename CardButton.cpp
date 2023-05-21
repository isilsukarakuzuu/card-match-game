#include "CardButton.h"
#include <QMessageBox>

CardButton::CardButton(QWidget *parent, QString text) : QPushButton(parent), buttonText(text){
    connect(this, &QPushButton::clicked, this, &CardButton::displayText);
}

void CardButton::displayText()
{
    setText(buttonText);
}

