#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <QWidget>
#include <QGridLayout>
#include "CardButton.h"

class GridLayout : public QWidget
{
    Q_OBJECT

public:
    CardButton* first_clicked;
    CardButton* second_clicked;

    explicit GridLayout(QWidget *parent, std::vector<std::vector<QString>>& cardGrid, int height = 5, int width = 6);
    void build();
    void click(CardButton* button);
    void match();

private:
    QGridLayout *layout;
    std::vector<std::vector<QString>>& cardGrid;
    int height;
    int width;
};

#endif // GRIDLAYOUT_H
