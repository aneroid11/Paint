#include "shapeslistserializer.h"
#include "json.hpp"

#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;

void dumpShapesListToFile(const QList<Shape *> &shapesList, QString fileName)
{
    std::cout << "dump the list of shapes to " << fileName.toStdString() << "\n";
    json shapesArray = {};

    std::string dumped = shapesArray.dump(2);
    std::ofstream out(fileName.toStdString());
    out << dumped;
    out.close();
}

QList<Shape *> loadShapesListFromFile(QString fileName)
{
    std::cout << "load the list of shapes from " << fileName.toStdString() << "\n";
    return QList<Shape *>();
}
