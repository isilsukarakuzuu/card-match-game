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

    explicit GridLayout(QWidget *parent, std::vector<std::vector<QString>>& cardGrid, int height = 5, int width = 6);
    void build();
    void click(CardButton* button);

public slots:
    void match();

private:
    QGridLayout *layout;
    std::vector<std::vector<QString>>& cardGrid;
    int height;
    int width;
};

#endif // GRIDLAYOUT_H
