#ifndef SHAPE_H
#define SHAPE_H

#include "isubject.h"

#include <QPainter>
#include <QPoint>
#include <QList>

#include <string>

class Shape : public ISubject
{
public:
    Shape() {}
    virtual ~Shape() {}

    virtual void keyEventHandler(QKeyEvent *event) { (void)event; }

    virtual void draw(QPainter &painter, QPoint localMousePos) const = 0;
    virtual std::string getName() const = 0;
    virtual std::string dumps() const = 0;

    void setCurrentPenColor(QColor currentPenColor) { this->currentPenColor = currentPenColor; }
    void setCurrentBrushColor(QColor currentBrushColor) { this->currentBrushColor = currentBrushColor; }
    void setCurrentLineWidth(int currentLineWidth) { this->currentLineWidth = currentLineWidth; }

    int getCurrentLineWidth() const { return this->currentLineWidth; }
    QColor getCurrentPenColor() const { return this->currentPenColor; }
    QColor getCurrentBrushColor() const { return this->currentBrushColor; }

    void setPoints(const QVector<QPoint> &points) { this->points = points; }
    QVector<QPoint> getPoints() const { return this->points; }

    virtual void startDrawing(const QPoint startPoint) = 0;
    virtual void setNextPoint(const QPoint nextPoint) = 0;

    bool drawingIsFinished() const { return this->finishedDrawing; }

    void attachObserver(IObserver *observer) override { this->observers.push_back(observer); }
    void detachObserver(IObserver *observer) override { this->observers.remove(observer); }

    void notify(std::string msgForObservers) override
    {
        for (IObserver *o : this->observers)
        {
            o->updateObserver(msgForObservers);
        }
    }

    void finishDrawing() { this->finishedDrawing = true; this->notify("finished drawing shape"); }

protected:
    QColor currentPenColor;
    QColor currentBrushColor;
    int currentLineWidth = 1;

    QVector<QPoint> points;
    bool finishedDrawing = false;

    std::list<IObserver *> observers;
};

typedef Shape *(* ShapeCreator)();

#endif // SHAPE_H
