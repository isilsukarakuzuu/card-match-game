#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <QWidget>
#include <QGridLayout>
#include <QTimer>
#include "CardButton.h"

class GridLayout : public QWidget
{
    Q_OBJECT

public:
    CardButton* first_clicked;
    CardButton* second_clicked;
    QTimer* match_timer;
    int height;
    int width;
    int score;
    int tries;

    explicit GridLayout(QWidget *parent, int height = 5, int width = 6, int score = 0, int tries = 50);
    void build();
    void clickHandlerForGrid(CardButton* button);
    void openAllCards();

public slots:
    void matchingHandler();

private:
    QGridLayout *layout;
    std::vector<std::vector<QString>> cardGrid;

};

#endif // GRIDLAYOUT_H
