#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "rectangle_global.h"

#include "../shape.h"

class RECTANGLE_EXPORT Rectangle : public Shape
{
public:
    Rectangle() {}
    ~Rectangle() override {}

    void draw(QPainter &painter) const override;
    std::string getName() const override;
    std::string dumps() const override;

    void startDrawing(const QPoint startPoint) override;
    void setNextPoint(const QPoint nextPoint) override;
};

#endif // RECTANGLE_H
