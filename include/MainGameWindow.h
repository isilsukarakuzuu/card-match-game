#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H
#include "GridLayout.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

class MainGameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainGameWindow(QWidget *parent = nullptr);
    void setScoreAndTries();
    void winGame();
    void loseGame();

private slots:
    void startNewGame();

private:
    QVBoxLayout *mainLayout;
    QLabel *scoreLabel;
    QLabel *triesLabel;
    QPushButton *newGameButton;
    GridLayout *gridLayout;
    QHBoxLayout *topLayout;
    std::vector<std::vector<QString>> cardGrid;
};

#endif // MAINGAMEWINDOW_H
