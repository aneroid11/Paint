#include "paint.h"
#include "ui_paint.h"

#include <QPainter>
#include <QDebug>

Paint::Paint(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::Paint)
{
    ui->setupUi(this);

    this->paintTimer = new QTimer(this);
    this->paintTimer->setInterval(10);
    connect(this->paintTimer, &QTimer::timeout, this, &Paint::updatePaint);
    this->paintTimer->start();
}

Paint::~Paint()
{
    delete ui;
}

void Paint::updatePaint()
{
    qDebug() << "update paint\n";
    this->repaint();
}

void Paint::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    QPainter painter(this);
    painter.setPen(Qt::SolidLine);
    painter.drawLine(30, 30, 30, 200);
}
