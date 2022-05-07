#include "rectangle.h"

#include "../json.hpp"

using json = nlohmann::json;

void Rectangle::draw(QPainter &painter) const
{
    QPen pen(this->currentPenColor);
    pen.setWidth(this->currentLineWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush(this->currentBrushColor));

    QPoint firstPoint = this->points[0];
    QPoint secondPoint;

    if (this->points.size() < 2)
    {
        secondPoint = firstPoint;
    }
    else
    {
        secondPoint = this->points[1];
    }

    painter.drawRect(QRect(firstPoint, secondPoint));
}

std::string Rectangle::getName() const
{
    return "rectangle";
}

std::string Rectangle::dumps() const
{
    json j;
    j["type"] = getName();
    return j.dump(2);
}

void Rectangle::startDrawing(const QPoint startPoint)
{
    this->points.append(startPoint);
}

void Rectangle::setNextPoint(const QPoint nextPoint)
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
    return new Rectangle();
}
