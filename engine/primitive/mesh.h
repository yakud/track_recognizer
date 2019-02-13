//
// Created by yakud on 2019-02-09.
//
#ifndef TRACK_RECOGNIZER_MESH_H
#define TRACK_RECOGNIZER_MESH_H

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

namespace engine { namespace primitive {

struct Mesh {
    std::vector<glm::vec3>  positions;
    std::vector<glm::vec3>  normals;
    std::vector<glm::vec4>  colors;
    std::vector<glm::vec2>  uv;

    std::vector<glm::uvec3> indices;
};

}};

#endif //TRACK_RECOGNIZER_MESH_H
