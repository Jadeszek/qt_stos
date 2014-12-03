#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <iostream>
using namespace std;

#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Counter sender, receiver;

    cout << "0.\tS:" << sender.value()
         << "\tR:" << receiver.value() << endl;

    QObject::connect(&sender, &Counter::valueChanged,
                     &receiver, &Counter::setValue);

    sender.setValue(8);
    cout << "1.\tS:" << sender.value()
         << "\tR:" << receiver.value() << endl;

    receiver.setValue(16);
    cout << "2.\tS:" << sender.value()
         << "\tR:" << receiver.value() << endl;

    QObject::disconnect(&sender, &Counter::valueChanged,
                     &receiver, &Counter::setValue);

    sender.setValue(32);
    cout << "3.\tS:" << sender.value()
         << "\tR:" << receiver.value() << endl;

    return a.exec();
}
