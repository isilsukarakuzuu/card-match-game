#include <QWidget>
#include <QGridLayout>
#include "grid_layout.cpp"

class CardMatchMainWindow : public QWidget {
public:
    QVBoxLayout *mainLayout;
    QGridLayout *topGridLayout;
    QWidget *gridWidget;

    explicit CardMatchMainWindow(CardMatchGame& game, QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Card Match Game");

        mainLayout = new QVBoxLayout;
        topGridLayout = new QGridLayout;
        gridWidget = new QWidget;

        QLabel *scoreLabel = new QLabel("Score: ");
        QLabel *remainingTriesLabel = new QLabel("Remaining tries: ");

        topGridLayout->addWidget(scoreLabel, 0, 0);
        topGridLayout->addWidget(remainingTriesLabel, 0, 1);

        topGridLayout->setAlignment(Qt::AlignTop);

        CardMatchGrid *grid = new CardMatchGrid(game, gridWidget);

        // one grid on the top
        mainLayout->addLayout(topGridLayout);
        // one grid on the bottom
        mainLayout->addWidget(gridWidget);

        setLayout(mainLayout);



    }
};