#include "drawingarea.h"

#include <QPainter>
#include <QTimer>
#include <QDebug>

DrawingArea::DrawingArea(QWidget *parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    this->redrawTimer = new QTimer(this);
    this->redrawTimer->setInterval(10);
    connect(this->redrawTimer, &QTimer::timeout, this, &DrawingArea::updateArea);
    this->redrawTimer->start();
}

void DrawingArea::updateArea()
{
    this->repaint();
}

void DrawingArea::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    // iterate over all shapes and draw them here

    for (auto s : shapes)
    {
        s->draw(painter);
    }

    /*QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(currentPenColor);
    pen.setWidth(currentLineWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush(currentBrushColor));

    painter.drawEllipse(QPoint(this->width() / 2, this->height() / 2), 50, 40);*/
}
