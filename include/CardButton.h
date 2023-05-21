#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <QPushButton>

class CardButton : public QPushButton
{
    Q_OBJECT

public:
    QString buttonText;
    explicit CardButton(QWidget *parent = nullptr, QString text = "");
private slots:
    void displayText();


};

#endif // CARDBUTTON_H
