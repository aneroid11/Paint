#include "shapesmanager.h"

#include <iostream>

ShapesManager::ShapesManager(std::string shapesDirPath)
{
    namespace fs = std::filesystem;

    for (const auto & entry : fs::directory_iterator(shapesDirPath))
    {
        std::string path = entry.path();
        std::cout << "loading " << path << "\n";
        this->dlls[path] = dlopen(path.c_str(), RTLD_NOW | RTLD_LAZY);

        if (!this->dlls[path])
        {
            this->dlls.erase(path);
            continue;
        }

        ShapeCreator create = (ShapeCreator)dlsym(this->dlls[path], "createShape");

        if (!create)
        {
            this->dlls.erase(path);
            continue;
        }

        Shape *exampleShape = create();
        shapes[exampleShape->getName()] = create;
        delete exampleShape;
    }
}

ShapesManager::~ShapesManager()
{
    for (auto it = this->dlls.begin(); it != this->dlls.end(); it++)
    {
        dlclose(it->second);
    }
}

Shape* ShapesManager::createShape(std::string shapeName)
{
    return shapes[shapeName]();
}
