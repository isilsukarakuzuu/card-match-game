#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <QPushButton>

class CardButton : public QPushButton
{
    Q_OBJECT

public:
    QString buttonText;
    bool active;
    bool clicked;
    explicit CardButton(QWidget *parent = nullptr);
    void resetButton();
    bool clickable();
    void unclick();
    void deactivate();

private slots:
    void click();

};

#endif // CARDBUTTON_H
