#include <string>
#include <utility>
using namespace std;

struct Card {

    string content;
    bool active;
    bool clicked;

    explicit Card(string _content) {
        content = std::move(_content);
        active = false;
        clicked = false;
    }

    void setActive(bool _active) {
        active = _active;
    }
    void setClicked(bool _clicked) {
        clicked = _clicked;
    }

};