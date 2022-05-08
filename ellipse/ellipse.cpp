#include "ellipse.h"

#include "../json.hpp"

using json = nlohmann::json;

void Ellipse::draw(QPainter &painter, QPoint localMousePos) const
{
    QPen pen(this->currentPenColor);
    pen.setWidth(this->currentLineWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush(this->currentBrushColor));

    QPoint firstPoint = this->points[0];
    QPoint secondPoint;

    if (this->points.size() < 2)
    {
        secondPoint = localMousePos;
    }
    else
    {
        secondPoint = this->points[1];
    }

    painter.drawEllipse(QRect(firstPoint, secondPoint));
}

std::string Ellipse::getName() const
{
    return "ellipse";
}

std::string Ellipse::dumps() const
{
    json j;
    j["type"] = getName();
    return j.dump(2);
}

void Ellipse::startDrawing(const QPoint startPoint)
{
    this->points.append(startPoint);
}

void Ellipse::setNextPoint(const QPoint nextPoint)
{
    this->points.append(nextPoint);

    if (this->points.size() == 2)
    {
        this->finishDrawing();
    }
}

// for exporting
extern "C" Shape *createShape()
{
    return new Ellipse();
}
