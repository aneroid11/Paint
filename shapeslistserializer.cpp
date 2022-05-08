#include "shapeslistserializer.h"
#include "json.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using json = nlohmann::json;

void dumpShapesListToFile(const QList<Shape *> &shapesList, QString fileName)
{
    std::cout << "dump the list of shapes to " << fileName.toStdString() << "\n";
    json shapesArray = {};

    for (int i = 0; i < shapesList.size(); i++)
    {
        Shape *currentShape = shapesList[i];
        shapesArray[i]["name"] = currentShape->getName();
    }

    std::string dumped = shapesArray.dump(2);
    std::ofstream out(fileName.toStdString());
    out << dumped;
    out.close();
}

std::string readAllText(std::ifstream& in) {
    std::ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

QList<Shape *> loadShapesListFromFile(QString fileName, ShapesCreator *creator)
{
    std::cout << "load the list of shapes from " << fileName.toStdString() << "\n";

    std::ifstream in(fileName.toStdString());
    json shapesArray = json::parse(readAllText(in));

    if (shapesArray.is_null())
    {
        return QList<Shape *>();
    }

    QList<Shape *> retList;

    Shape *s = creator->createShape("rectangle");
    s->setPoints( { QPoint(50, 50), QPoint(300, 300) } );

    retList.append(s);

    return retList;
}
