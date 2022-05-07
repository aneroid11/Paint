#include "rectangle.h"

#include "../json.hpp"

using json = nlohmann::json;

void Rectangle::draw(QPainter &painter) const
{
    QPen pen(this->currentPenColor);
    pen.setWidth(this->currentLineWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush(this->currentBrushColor));
    painter.drawRect(QRect(points[0], points[1]));
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

// for exporting
extern "C" Shape *createShape()
{
    return new Rectangle();
}
