#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QWidget>

class QPushButton;
class window : public QWidget
{
    Q_OBJECT
public:
    explicit window(QWidget *parent = 0);
private:
    QPushButton *button;
private slots:
    void slotButtonClicked(bool checked);
};

#endif // WINDOW_H
