#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <QWidget>
#include <QGridLayout>
#include "CardButton.h"

class GridLayout : public QWidget
{
    Q_OBJECT

public:
    explicit GridLayout(QWidget *parent = nullptr, std::vector<std::vector<QString>> cardGrid = {});
    void build();

private:
    QGridLayout *layout;
    QVector<CardButton*> buttons;
    std::vector<std::vector<QString>> cardGrid;
};

#endif // GRIDLAYOUT_H
