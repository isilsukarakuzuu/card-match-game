#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include "GridLayout.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>

class MainGameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainGameWindow(QWidget *parent = nullptr);

private slots:
    void startNewGame();

private:
    QVBoxLayout *mainLayout;
    QLabel *scoreLabel;
    QLabel *triesLabel;
    QPushButton *newGameButton;
    GridLayout *gridLayout;
    QHBoxLayout *topLayout;
};

#endif // MAINGAMEWINDOW_H
