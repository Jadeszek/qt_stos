#include "window.h"
#include "ui_window.h"

#include <QPushButton>

window::window(QWidget *parent) :
    QWidget(parent)
{
    button = new QPushButton("Button", this);
    button->setCheckable(true);
    connect(button, &QPushButton::clicked, this, &window::slotButtonClicked);
}

void window::slotButtonClicked(bool checked)
{
    button->setText(checked ? "Zaznaczony" : "Nope!");
}
