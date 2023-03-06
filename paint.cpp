#include "paint.h"
#include "shape.h"

#include <QPainter>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSlider>
#include <QColorDialog>
#include <QString>
#include <QList>
#include <QShortcut>

#include <iostream>

Paint::Paint(QWidget *parent)
    : QWidget(parent)
{
    this->shapesCreator = new ShapesCreator("./shapes/");
    /*Shape *exampleRectangle = this->shapesManager->createShape("rectangle");
    std::cout << exampleRectangle->getName() << "\n";
    std::cout << exampleRectangle->dumps() << "\n";
    delete exampleRectangle;*/

    this->setWindowTitle("Paint");
    this->setFixedWidth(512);
    this->setFixedHeight(640);

    this->drawingArea = new DrawingArea(this, this->shapesCreator);

    QGridLayout *gridLayout = new QGridLayout(this);

    QComboBox *shapesList = new QComboBox(this);
    std::list<std::string> shapesNames = this->shapesCreator->getAllShapesNames();

    for (auto name : shapesNames)
    {
        shapesList->addItem(name.c_str());
    }
    connect(shapesList, &QComboBox::currentTextChanged, this, &Paint::updateCurrentShape);
    this->updateCurrentShape((*shapesNames.begin()).c_str());

    QSlider *lineWidth = new QSlider(Qt::Horizontal, this);
    lineWidth->setRange(0, 10);
    lineWidth->setTickInterval(1);
    connect(lineWidth, &QSlider::valueChanged, this, &Paint::updateLineWidth);

    QPushButton *penColorButton = new QPushButton(this);
    penColorButton->setText("Select line color");
    connect(penColorButton, &QPushButton::clicked, this, &Paint::selectPenColor);

    QPushButton *brushColorButton = new QPushButton(this);
    brushColorButton->setText("Select brush color");
    connect(brushColorButton, &QPushButton::clicked, this, &Paint::selectBrushColor);

    connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this),
            &QShortcut::activated, this->drawingArea, &DrawingArea::undo);

    connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this),
            &QShortcut::activated, this->drawingArea, &DrawingArea::redo);

    /*QPushButton *undoButton = new QPushButton(this);
    undoButton->setText("Undo");
    connect(undoButton, &QPushButton::clicked, this->drawingArea, &DrawingArea::undo);

    QPushButton *redoButton = new QPushButton(this);
    redoButton->setText("Redo");
    connect(redoButton, &QPushButton::clicked, this->drawingArea, &DrawingArea::redo);*/

    gridLayout->addWidget(this->drawingArea, 0, 0);
    gridLayout->addWidget(shapesList, 1, 0);
    gridLayout->addWidget(lineWidth, 2, 0);
    gridLayout->addWidget(penColorButton, 3, 0);
    gridLayout->addWidget(brushColorButton, 4, 0);
    //gridLayout->addWidget(undoButton, 5, 0);
    //gridLayout->addWidget(redoButton, 6, 0);
}

Paint::~Paint()
{
    delete this->shapesCreator;
}

QColor Paint::getColorFromUser() const
{
    QColorDialog dialog;
    QColor color = dialog.getColor();
    return color;
}
