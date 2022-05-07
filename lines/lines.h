#ifndef LINES_H
#define LINES_H

#include "lines_global.h"

#include "../shape.h"

class LINES_EXPORT Lines : public Shape
{
public:
    Lines() {}
    ~Lines() override {}

    void draw(QPainter &painter, QPoint localMousePos) const override;
    std::string getName() const override;
    std::string dumps() const override;

    void startDrawing(const QPoint startPoint) override;
    void setNextPoint(const QPoint nextPoint) override;
};

#endif // LINES_H
