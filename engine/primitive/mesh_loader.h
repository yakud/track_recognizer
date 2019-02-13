//
// Created by yakud on 2019-02-11.
//


#ifndef TRACK_RECOGNIZER_PRIMITIVE_MESH_LOADER_H
#define TRACK_RECOGNIZER_PRIMITIVE_MESH_LOADER_H

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <error.h>
#include <utility>
#include <optional>
#include <glm/glm.hpp>

#include "mesh.h"
#include <vendor/obj_loader_bly7.h>

namespace engine{ namespace primitive{

class MeshLoader {
public:
    std::tuple<Mesh *, std::optional<engine::Error>> LoadObj(std::string path);
};

}};


#endif //TRACK_RECOGNIZER_PRIMITIVE_MESH_LOADER_H
