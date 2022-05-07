#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}

    virtual std::string getName() const = 0;
    virtual std::string dumps() const = 0;
};

typedef Shape *(* ShapeCreator)();

#endif // SHAPE_H
