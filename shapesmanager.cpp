#include "shapesmanager.h"

#include <iostream>

ShapesManager::ShapesManager(std::string shapesDirPath)
{
    namespace fs = std::filesystem;

    for (const auto & entry : fs::directory_iterator(shapesDirPath))
    {
        std::string path = entry.path();
        std::cout << path << "\n";
        this->dlls[path] = dlopen(path.c_str(), RTLD_NOW | RTLD_LAZY);

        if (!this->dlls[path]) { this->dlls.erase(path); }
    }
}

ShapesManager::~ShapesManager()
{
    for (auto it = this->dlls.begin(); it != this->dlls.end(); it++)
    {
        dlclose(it->second);
    }
}
