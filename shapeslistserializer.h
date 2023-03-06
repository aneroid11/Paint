#ifndef SHAPESLISTSERIALIZER_H
#define SHAPESLISTSERIALIZER_H

#include "shape.h"
#include "shapescreator.h"

#include <QList>

void dumpShapesListToFile(const QList<Shape *> &shapesList, QString fileName);
QList<Shape *> loadShapesListFromFile(QString fileName, ShapesCreator *creator);

#endif // SHAPESLISTSERIALIZER_H
