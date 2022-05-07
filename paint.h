#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QTimer>

class DrawingArea;
class QSlider;

class Paint : public QWidget
{
    Q_OBJECT

public:
    Paint(QWidget *parent = nullptr);
    ~Paint();

private slots:
    void selectColor();
    void updateLineWidth(int lineWidth);

private:
    DrawingArea *drawingArea;
};
#endif // PAINT_H
