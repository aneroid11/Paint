#include "lines.h"

#include "../json.hpp"

#include <QApplication>
#include <QDebug>

using json = nlohmann::json;

void Lines::keyEventHandler(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        qDebug() << "handle key escape event";
        // finish drawing
        finishedDrawing = true;
    }
}

void Lines::draw(QPainter &painter, QPoint localMousePos) const
{
    QPen pen(this->currentPenColor);
    pen.setWidth(this->currentLineWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush(this->currentBrushColor));

    QVector<QPoint> points = this->points;

    if (!finishedDrawing)
    {
        points.append(localMousePos);
    }

    QPolygon poly(points);
    painter.drawPolygon(poly);
    //painter.drawPolyline(points);
}

std::string Lines::getName() const
{
    return "lines";
}

std::string Lines::dumps() const
{
    json j;
    j["type"] = getName();
    return j.dump(2);
}

void Lines::startDrawing(const QPoint startPoint)
{
    this->points.append(startPoint);
}

void Lines::setNextPoint(const QPoint nextPoint)
{
    this->points.append(nextPoint);
}

// for exporting
extern "C" Shape *createShape()
{
    return new Lines();
}
