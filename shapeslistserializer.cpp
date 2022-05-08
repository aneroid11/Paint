#include "shapeslistserializer.h"
#include "json.hpp"

#include <iostream>

using json = nlohmann::json;

void dumpShapesListToFile(const QList<Shape *> &shapesList, QString fileName)
{
    std::cout << "here we need to dump the list of shapes to " << fileName.toStdString() << "\n";
}

QList<Shape *> loadShapesListFromFile(QString fileName)
{
    std::cout << "here we need to load the list of shapes from " << fileName.toStdString() << "\n";
    return QList<Shape *>();
}
