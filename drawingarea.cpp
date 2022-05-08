#include "drawingarea.h"
#include "shapeslistserializer.h"

#include <QPainter>
#include <QTimer>
#include <QDebug>

DrawingArea::DrawingArea(QWidget *parent, ShapesCreator *shapesCreator) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    this->redrawTimer = new QTimer(this);
    this->redrawTimer->setInterval(10);
    connect(this->redrawTimer, &QTimer::timeout, this, &DrawingArea::updateArea);
    this->redrawTimer->start();

    this->shapesCreator = shapesCreator;

    this->setMouseTracking(true);
    this->grabKeyboard();

    this->deserializeDrawnShapesList();
}

DrawingArea::~DrawingArea()
{
    // we COULD do this, but shape dlls are closed BEFORE this destructor is called.
    // and it caused segmentation fault.

    /*qDebug() << "deleting shapes\n";

    for (auto shape : shapes)
    {
        delete shape;
    }*/
}

void DrawingArea::addShape(Shape *shape)
{
    if (this->shapesListSize < this->shapes.size())
    {
        while (this->shapes.size() > this->shapesListSize)
        {
            delete this->shapes[this->shapes.size() - 1];
            this->shapes.pop_back();
        }
    }

    this->shapes.append(shape);
    this->shapesListSize++;
}

void DrawingArea::undo()
{
    this->shapesListSize--;

    if (this->shapesListSize < 0) { this->shapesListSize = 0; }

    this->serializeDrawnShapesList();
}

void DrawingArea::redo()
{
    this->shapesListSize++;

    if (this->shapesListSize > this->shapes.size()) { this->shapesListSize = this->shapes.size(); }

    this->serializeDrawnShapesList();
}

void DrawingArea::updateArea()
{
    this->repaint();
}

void DrawingArea::mousePressEvent(QMouseEvent *event)
{
    QPoint mousePos = QPoint(event->x(), event->y());

    if (this->shapesListSize < 1 || this->shapes[this->shapesListSize - 1]->drawingIsFinished())
    {
        Shape *newShape = this->shapesCreator->createShape(this->currentShapeName);
        newShape->setCurrentBrushColor(this->currentBrushColor);
        newShape->setCurrentPenColor(this->currentPenColor);
        newShape->setCurrentLineWidth(this->currentLineWidth);

        newShape->startDrawing(mousePos);

        this->addShape(newShape);
    }
    else
    {
        this->shapes[this->shapesListSize - 1]->setNextPoint(mousePos);

        if (this->shapes[this->shapesListSize - 1]->drawingIsFinished())
        {
            this->serializeDrawnShapesList();
        }
    }
}

void DrawingArea::mouseMoveEvent(QMouseEvent *event)
{
    this->mousePos = event->pos();
}

void DrawingArea::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);

    for (int i = 0; i < this->shapesListSize; i++)
    {
        Shape *s = this->shapes[i];
        s->draw(painter, this->mousePos);
    }
}

void DrawingArea::keyPressEvent(QKeyEvent *event)
{
    for (int i = 0; i < this->shapesListSize; i++)
    {
        this->shapes[i]->keyEventHandler(event);
    }
    this->serializeDrawnShapesList();
}

void DrawingArea::serializeDrawnShapesList()
{
    QList<Shape *> drawnShapes;

    for (int i = 0; i < this->shapesListSize; i++)
    {
        if (this->shapes[i]->drawingIsFinished())
        {
            drawnShapes.append(this->shapes[i]);
        }
    }

    dumpShapesListToFile(drawnShapes, "shapesList.json");
}

void DrawingArea::deserializeDrawnShapesList()
{
    if (this->shapes.size() > 0)
    {
        for (int i = 0; i < this->shapes.size(); i++)
        {
            delete this->shapes[i];
        }
        this->shapes.clear();
    }

    this->shapes = loadShapesListFromFile("shapesList.json");
    this->shapesListSize = this->shapes.size();
}
