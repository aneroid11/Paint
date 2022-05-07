#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include "shape.h"
#include "shapescreator.h"

#include <QWidget>
#include <QList>
#include <QDebug>

class DrawingArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingArea(QWidget *parent, ShapesCreator *shapesCreator);
    ~DrawingArea();

    void setCurrentPenColor(QColor cl) { this->currentPenColor = cl; }
    void setCurrentBrushColor(QColor cl) { this->currentBrushColor = cl; }
    void setCurrentLineWidth(int currentLineWidth) { this->currentLineWidth = currentLineWidth; }
    void setCurrentShapeName(std::string currentShapeName) { this->currentShapeName = currentShapeName; }

    void addShape(Shape *shape);

public slots:
    void undo();
    void redo();

private slots:
    void updateArea();

private:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    QList<Shape *> shapes;
    int shapesListSize = 0;

    ShapesCreator *shapesCreator;

    QTimer *redrawTimer;

    // parameters for the next shape to be drawn
    QColor currentPenColor;
    QColor currentBrushColor;
    int currentLineWidth = 1;
    std::string currentShapeName;
};

#endif // DRAWINGAREA_H
