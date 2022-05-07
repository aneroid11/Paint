#include "rectangle.h"

#include "../json.hpp"

using json = nlohmann::json;

void Rectangle::draw(QPainter &painter) const
{
    if (this->points.size() < 2) { return; }

    QPen pen(this->currentPenColor);
    pen.setWidth(this->currentLineWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush(this->currentBrushColor));
    painter.drawRect(QRect(this->points[0], this->points[1]));
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
