#include <QPushButton>
#include "card.cpp"

using namespace std;

class CardButton : public QPushButton {
public:
    explicit CardButton(Card& card, QWidget* parent = nullptr) : QPushButton(parent) {
        QPalette pal = palette();
        setEnabled(card.active && !card.clicked);
        if(card.clicked){
            pal.setColor(QPalette::Button, QColor(Qt::green));
            QString buttonText = QString::fromStdString(card.content);
            setText(buttonText);
        }else{
            pal.setColor(QPalette::Button, QColor(Qt::blue));
        }
        setAutoFillBackground(true);
        setPalette(pal);
        update();
    }
};