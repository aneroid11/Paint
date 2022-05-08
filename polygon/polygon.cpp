#include "polygon.h"

#include "../json.hpp"

#include <QApplication>
#include <QDebug>

using json = nlohmann::json;

void Polygon::keyEventHandler(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        finishedDrawing = true;
    }
}

void Polygon::draw(QPainter &painter, QPoint localMousePos) const
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
}

std::string Polygon::getName() const
{
    return "polygon";
}

std::string Polygon::dumps() const
{
    json j;
    j["type"] = getName();
    return j.dump(2);
}

void Polygon::startDrawing(const QPoint startPoint)
{
    this->points.append(startPoint);
}

void Polygon::setNextPoint(const QPoint nextPoint)
{
    this->points.append(nextPoint);
}

// for exporting
extern "C" Shape *createShape()
{
    return new Polygon();
}
