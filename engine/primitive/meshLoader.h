//
// Created by yakud on 2019-02-11.
//

#ifndef TRACK_RECOGNIZER_MESH_LOADER_H
#define TRACK_RECOGNIZER_MESH_LOADER_H

#include <string>
#include <sstream>
#include <vector>
#include <glm/glm.hpp>
#include <iostream>
#include <error.h>
#include <utility>

#include "mesh.h"
#include "objLoaderBly7.h"

namespace engine{ namespace primitive{

class MeshLoader {
public:
    std::tuple<Mesh *, engine::Error *> LoadObj(std::string path);
};

}};


#endif //TRACK_RECOGNIZER_MESH_LOADER_H
