//
// Created by yakud on 2019-02-12.
//

#ifndef TRACK_RECOGNIZER_VERTEX_H
#define TRACK_RECOGNIZER_VERTEX_H

#include <glm/ext.hpp>

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};


#endif //TRACK_RECOGNIZER_VERTEX_H
