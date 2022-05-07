#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>

class DrawingArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingArea(QWidget *parent = nullptr);

    void setCurrentColor(QColor currentColor) { this->currentColor = currentColor; }
    void setCurrentLineWidth(int currentLineWidth) { this->currentLineWidth = currentLineWidth; }

private slots:
    void updateArea() { this->repaint(); }

private:
    void paintEvent(QPaintEvent *event);

    QTimer *redrawTimer;
    QColor currentColor;
    int currentLineWidth = 1;
};

#endif // DRAWINGAREA_H
