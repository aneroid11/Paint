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

extern "C" void deleteShape(Shape *s)
{
    delete s;
}
