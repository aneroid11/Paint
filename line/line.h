#ifndef LINE_H
#define LINE_H

#include "line_global.h"

#include "../shape.h"

class LINE_EXPORT Line : public Shape
{
public:
    Line() {}
    ~Line() override {}

    void draw(QPainter &painter, QPoint localMousePos) const override;
    std::string getName() const override;
    std::string dumps() const override;

    void startDrawing(const QPoint startPoint) override;
    void setNextPoint(const QPoint nextPoint) override;
};

#endif // LINE_H
