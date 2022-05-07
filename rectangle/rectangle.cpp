#include "rectangle.h"

std::string Rectangle::getName() const
{
    return "rectangle";
}

// for exporting
extern "C" Shape *createShape()
{
    return new Rectangle();
}
