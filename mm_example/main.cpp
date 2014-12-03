#include <QApplication>
#include <QWindow>
#include <QPushButton>
#include <QLabel>
#include <QLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.show();
    w.setGeometry(128,64,256,256);

    QPushButton* b1 = new QPushButton("B1", &w);
    QPushButton* b2 = new QPushButton("B2", &w);
    QLabel* l1 = new QLabel("L1", &w);
    QLabel* l2 = new QLabel("L2", &w);

    b1->show();
    b2->move(64, 64);b2->show();
    l1->move(128, 128);l1->show();
    l2->move(64, 128);l2->show();

    return a.exec();
}
