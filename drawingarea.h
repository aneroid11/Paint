#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include "shape.h"
#include "shapescreator.h"

#include <QWidget>
#include <QList>

class DrawingArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingArea(QWidget *parent, ShapesCreator *shapesCreator);
    ~DrawingArea();

    void setCurrentPenColor(QColor cl) { this->currentPenColor = cl; }
    void setCurrentBrushColor(QColor cl) { this->currentBrushColor = cl; }
    void setCurrentLineWidth(int currentLineWidth) { this->currentLineWidth = currentLineWidth; }

    void addShape(Shape *shape) { shapes.append(shape); }

private slots:
    void updateArea();

private:
    void paintEvent(QPaintEvent *event);

    QList<Shape *> shapes;
    ShapesCreator *shapesCreator;

    QTimer *redrawTimer;
    QColor currentPenColor;
    QColor currentBrushColor;
    int currentLineWidth = 1;
};

#endif // DRAWINGAREA_H
