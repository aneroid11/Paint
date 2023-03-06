#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include "shape.h"
#include "shapescreator.h"
#include "iobserser.h"

#include <QWidget>
#include <QList>
#include <QDebug>

class DrawingArea : public QWidget, IObserver
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

    void updateObserver(std::string msgFromSubject) override;

public slots:
    void undo();
    void redo();

private slots:
    void updateArea();

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    void keyPressEvent(QKeyEvent *event);

    void serializeDrawnShapesList();
    void deserializeDrawnShapesList();

    QList<Shape *> shapes;
    int shapesListSize = 0;

    ShapesCreator *shapesCreator;

    QTimer *redrawTimer;

    // parameters for the next shape to be drawn
    QColor currentPenColor;
    QColor currentBrushColor;
    int currentLineWidth = 1;
    std::string currentShapeName;

    QPoint mousePos;
};

#endif // DRAWINGAREA_H
