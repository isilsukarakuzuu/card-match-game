#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <QPushButton>

class CardButton : public QPushButton
{
    Q_OBJECT

public:
    explicit CardButton(QWidget *parent = nullptr, QString text = "");

private slots:
    void displayText();

private:
    QString buttonText;
};

#endif // CARDBUTTON_H
