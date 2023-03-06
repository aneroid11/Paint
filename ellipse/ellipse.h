#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "ellipse_global.h"

#include "../shape.h"

class ELLIPSE_EXPORT Ellipse : public Shape
{
public:
    Ellipse() {}
    ~Ellipse() override {}

    void draw(QPainter &painter, QPoint localMousePos) const override;
    std::string getName() const override;
    std::string dumps() const override;

    void startDrawing(const QPoint startPoint) override;
    void setNextPoint(const QPoint nextPoint) override;
};

#endif // ELLIPSE_H
