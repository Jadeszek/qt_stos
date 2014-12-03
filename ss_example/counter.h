#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <iostream>
using namespace std;
class Counter : public QObject
{
    Q_OBJECT

public:
    Counter():val(0){}

    int value() const { return val; }

public slots:
    void setValue(int new_val);

signals:
    void valueChanged(int newValue);

private:
    int val;
};

#endif // COUNTER_H
