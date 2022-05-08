#ifndef SHAPESLISTSERIALIZER_H
#define SHAPESLISTSERIALIZER_H

#include "shape.h"

#include <QList>

void dumpShapesListToFile(const QList<Shape *> &shapesList, QString fileName);
QList<Shape *> loadShapesListFromFile(QString fileName);

#endif // SHAPESLISTSERIALIZER_H
