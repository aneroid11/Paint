#ifndef SHAPESMANAGER_H
#define SHAPESMANAGER_H

#include <filesystem>
#include <dlfcn.h>
#include <string>
#include <map>

class ShapesManager
{
public:
    ShapesManager(std::string shapesDirPath);
    ~ShapesManager();

private:
    std::map<std::string, void *> dlls;
};

#endif // SHAPESMANAGER_H
