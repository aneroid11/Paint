#ifndef SHAPESMANAGER_H
#define SHAPESMANAGER_H

#include <filesystem>
#include <dlfcn.h>
#include <string>
#include <map>

#include "shape.h"

class ShapesManager
{
public:
    ShapesManager(std::string shapesDirPath);
    ~ShapesManager();

    Shape *createShape(std::string shapeName);

private:
    std::map<std::string, void *> dlls;

    // name of the shape -> its creator and deleter
    std::map<std::string, ShapeCreator> shapes;
};

#endif // SHAPESMANAGER_H
