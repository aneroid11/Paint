#include "rectangle.h"

#include "../json.hpp"

using json = nlohmann::json;

void Rectangle::draw(QPainter &painter) const
{
    painter.drawRect(rand() % 400, rand() % 400, rand() % 400, rand() % 400);
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
