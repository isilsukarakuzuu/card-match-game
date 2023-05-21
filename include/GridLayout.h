#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <QWidget>
#include <QGridLayout>
#include "CardButton.h"

class GridLayout : public QWidget
{
    Q_OBJECT

public:
    explicit GridLayout(QWidget *parent, std::vector<std::vector<QString>>& cardGrid, int height = 5, int width = 6);
    void build();

private:
    int height, width;
    QGridLayout *layout;
    std::vector<std::vector<QString>>& cardGrid;
};

#endif // GRIDLAYOUT_H
