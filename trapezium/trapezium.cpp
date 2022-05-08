#include "trapezium.h"

#include "../json.hpp"

#include <QApplication>
#include <QDebug>

using json = nlohmann::json;

void Trapezium::draw(QPainter &painter, QPoint localMousePos) const
{
    QPen pen(this->currentPenColor);
    pen.setWidth(this->currentLineWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush(this->currentBrushColor));

    QVector<QPoint> points = this->points;
    if (!finishedDrawing)
    {
        int numPoints = points.size();
        QPoint currPoint = points[numPoints - 1];

        switch (numPoints)
        {
        case 1:
            if (currPoint.x() < localMousePos.x())
            {
                points.append(QPoint(localMousePos.x(), currPoint.y()));
            }
            break;
        case 2:
            if (currPoint.y() < localMousePos.y())
            {
                points.append(localMousePos);
            }
            break;
        case 3:
            if (currPoint.x() > localMousePos.x())
            {
                points.append(QPoint(localMousePos.x(), currPoint.y()));
            }
            break;
        default:
            break;
        }

    }

    QPolygon poly(points);
    painter.drawPolygon(poly);
}

std::string Trapezium::getName() const
{
    return "trapezium";
}

std::string Trapezium::dumps() const
{
    json j;
    j["type"] = getName();
    return j.dump(2);
}

void Trapezium::startDrawing(const QPoint startPoint)
{
    this->points.append(startPoint);
}

void Trapezium::setNextPoint(const QPoint nextPoint)
{
    int currNumPoints = this->points.size();

    if (currNumPoints == 1)
    {
        QPoint currPoint = this->points[currNumPoints - 1];
        int deltaX = nextPoint.x() - currPoint.x();

        // if the next point is on the left side
        if (deltaX < 0)
        {
            return;
        }

        this->points.append(QPoint(nextPoint.x(), currPoint.y()));
    }
    else
    {
        this->points.append(nextPoint);

        if (this->points.size() > 3)
        {
            finishedDrawing = true;
        }
    }
}

// for exporting
extern "C" Shape *createShape()
{
    return new Trapezium();
}
