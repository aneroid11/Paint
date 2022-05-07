#include "paint.h"
#include "drawingarea.h"
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

#include <dlfcn.h>
#include <filesystem>
#include <iostream>

//QList<QString> loadShapesList()
void loadShapesList()
{
    namespace fs = std::filesystem;

    QList<QString> shapes;
    std::string path = "./shapes/";

    ShapeCreator createShape;
    ShapeDeleter deleteShape;

    //std::string shapeSoPath = entry.path();
    std::string shapeSoPath = "./shapes/librectangle.so";
    void *so = dlopen(shapeSoPath.c_str(), RTLD_NOW | RTLD_LAZY);
    if (!so)
    {
        std::cerr << "Cannot load dll\n";
        std::cerr << dlerror() << "\n";
        exit(-1);
    }

    std::cout << shapeSoPath << "\n";

    createShape = (ShapeCreator)dlsym(so, "createShape");
    deleteShape = (ShapeDeleter)dlsym(so, "deleteShape");

    Shape *s = createShape();

    std::cout << s->getName() << "\n";

    deleteShape(s);

    dlclose(so);
}

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

    QPushButton *penColorButton = new QPushButton(this);
    penColorButton->setText("Select line color");
    connect(penColorButton, &QPushButton::clicked, this, &Paint::selectPenColor);

    QPushButton *brushColorButton = new QPushButton(this);
    brushColorButton->setText("Select brush color");
    connect(brushColorButton, &QPushButton::clicked, this, &Paint::selectBrushColor);

    gridLayout->addWidget(this->drawingArea, 0, 0);
    gridLayout->addWidget(shapesList, 1, 0);
    gridLayout->addWidget(lineWidth, 2, 0);
    gridLayout->addWidget(penColorButton, 3, 0);
    gridLayout->addWidget(brushColorButton, 4, 0);

    loadShapesList();
}

Paint::~Paint()
{
}

QColor Paint::getColorFromUser() const
{
    QColorDialog dialog;
    QColor color = dialog.getColor();
    return color;
}
