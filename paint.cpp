#include "paint.h"
#include "drawingarea.h"

#include <QPainter>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSlider>
#include <QColorDialog>

Paint::Paint(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Paint");
    this->setFixedWidth(512);
    this->setFixedHeight(600);

    this->drawingArea = new DrawingArea(this);

    QGridLayout *gridLayout = new QGridLayout(this);

    QComboBox *shapesList = new QComboBox(this);
    shapesList->addItem("Rectangle");
    shapesList->addItem("Line");
    shapesList->addItem("Ellipse");
    shapesList->addItem("Polygon");
    shapesList->addItem("Lines");

    QSlider *lineWidth = new QSlider(Qt::Horizontal, this);
    lineWidth->setRange(0, 10);
    lineWidth->setTickInterval(1);
    connect(lineWidth, &QSlider::valueChanged, this, &Paint::updateLineWidth);

    QPushButton *colorButton = new QPushButton(this);
    colorButton->setText("Select color");
    connect(colorButton, &QPushButton::clicked, this, &Paint::selectColor);

    gridLayout->addWidget(this->drawingArea, 0, 0);
    gridLayout->addWidget(shapesList, 1, 0);
    gridLayout->addWidget(lineWidth, 2, 0);
    gridLayout->addWidget(colorButton, 3, 0);
}

Paint::~Paint()
{
}

void Paint::selectColor()
{
    QColorDialog dialog;
    QColor color = dialog.getColor();
    this->drawingArea->setCurrentColor(color);
}

void Paint::updateLineWidth(int lineWidth)
{
    this->drawingArea->setCurrentLineWidth(lineWidth);
}
