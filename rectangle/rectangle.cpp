#include "rectangle.h"

#include "../json.hpp"

using json = nlohmann::json;

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
