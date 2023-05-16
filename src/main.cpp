#include <QApplication>
#include <QMainWindow>
#include <QLabel>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QMainWindow *mw = new QMainWindow;
    QLabel *ql = new QLabel;

    ql->setText("Its a project.");

    mw->setCentralWidget(ql);
    mw->setWindowTitle("Hello!");
    mw->show();
    return app.exec();
}