#include "drawingarea.h"

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
}

DrawingArea::~DrawingArea()
{
    for (auto shape : shapes)
    {
        delete shape;
    }
}

void DrawingArea::addShape(Shape *shape)
{
    if (shapesListSize < shapes.size())
    {
        while (shapes.size() > shapesListSize)
        {
            shapes.pop_back();
        }
    }

    shapes.append(shape);
    shapesListSize++;
}

void DrawingArea::undo()
{
    shapesListSize--;

    if (shapesListSize < 0) { shapesListSize = 0; }
}

void DrawingArea::redo()
{
    shapesListSize++;

    if (shapesListSize > shapes.size()) { shapesListSize = shapes.size(); }
}

void DrawingArea::updateArea()
{
    this->repaint();
}

void DrawingArea::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse was pressed. coordinates: " << event->x() << ", " << event->y() << "\n";
    qDebug() << "next shape: " << this->currentShapeName.c_str();

    Shape *newShape = this->shapesCreator->createShape(this->currentShapeName);
    newShape->setCurrentBrushColor(this->currentBrushColor);
    newShape->setCurrentPenColor(this->currentPenColor);
    newShape->setCurrentLineWidth(this->currentLineWidth);
    QList<QPoint> points;
    points.append(QPoint(rand() % 400, rand() % 400));
    points.append(QPoint(rand() % 400, rand() % 400));
    newShape->setPoints(points);

    this->addShape(newShape);
}

void DrawingArea::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);

    for (int i = 0; i < shapesListSize; i++)
    {
        Shape *s = shapes[i];
        s->draw(painter);
    }
}
