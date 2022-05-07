#include "paint.h"
#include "ui_paint.h"

#include <QPainter>

Paint::Paint(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::Paint)
{
    ui->setupUi(this);
    this->show();
}

Paint::~Paint()
{
    delete ui;
}

void Paint::paintEvent(QPaintEvent *event)
{
    (void)event;
    QPainter *painter = new QPainter(this);
    painter->setPen(Qt::SolidLine);
    painter->drawLine(30, 30, 30, 200);
    delete painter;
}
