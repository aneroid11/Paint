#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include "trapezium_global.h"

#include "../shape.h"

class TRAPEZIUM_EXPORT Trapezium : public Shape
{
public:
    Trapezium() {}
    ~Trapezium() override {}

    void draw(QPainter &painter, QPoint localMousePos) const override;
    std::string getName() const override;
    std::string dumps() const override;

    void startDrawing(const QPoint startPoint) override;
    void setNextPoint(const QPoint nextPoint) override;
};

#endif // TRAPEZIUM_H
