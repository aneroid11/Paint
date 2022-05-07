#include "line.h"

#include "../json.hpp"

using json = nlohmann::json;

void Line::draw(QPainter &painter, QPoint localMousePos) const
{
    QPen pen(this->currentPenColor);
    pen.setWidth(this->currentLineWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush(this->currentBrushColor));

    QPoint firstPoint = this->points[0];
    QPoint secondPoint;

    if (this->points.size() < 2)
    {
        secondPoint = localMousePos;
    }
    else
    {
        secondPoint = this->points[1];
    }

    painter.drawLine(firstPoint, secondPoint);
}

std::string Line::getName() const
{
    return "line";
}

std::string Line::dumps() const
{
    json j;
    j["type"] = getName();
    return j.dump(2);
}

void Line::startDrawing(const QPoint startPoint)
{
    this->points.append(startPoint);
}

void Line::setNextPoint(const QPoint nextPoint)
{
    this->points.append(nextPoint);

    if (this->points.size() == 2)
    {
        this->finishedDrawing = true;
    }
}

// for exporting
extern "C" Shape *createShape()
{
    return new Line();
}
