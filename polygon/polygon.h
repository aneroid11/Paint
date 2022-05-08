#ifndef POLYGON_H
#define POLYGON_H

#include "polygon_global.h"

#include "../shape.h"

class POLYGON_EXPORT Polygon : public Shape
{
public:
    Polygon() {}
    ~Polygon() override {}

    void keyEventHandler(QKeyEvent *event) override;
    void draw(QPainter &painter, QPoint localMousePos) const override;
    std::string getName() const override;
    std::string dumps() const override;

    void startDrawing(const QPoint startPoint) override;
    void setNextPoint(const QPoint nextPoint) override;
};

#endif // POLYGON_H
