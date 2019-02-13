//
// Created by yakud on 2019-02-12.
//

#ifndef TRACK_RECOGNIZER_ENTITY_H
#define TRACK_RECOGNIZER_ENTITY_H

#include <glm/ext.hpp>
#include <shader/shader.h>
#include "mesh.h"

namespace engine {namespace primitive{

class Entity {
    glm::mat4 _model;  // translate * rotate * scale
    glm::mat4 _mvp;    // model view projection

public:
    glm::mat4 rotate;
    glm::mat4 translate;
    glm::mat4 scale;

    Entity();

    void ResetMatrix();
    void UpdateMatrix();

    glm::vec3 GetTranslation();

    /**
     * Calc mvp and cache it
     * @param projection
     * @param view
     * @return
     */
    glm::mat4 UpdateMVP(glm::mat4 projection, glm::mat4 view);

    /*
     * Return cached mvp matrix
     * @return
     */
    glm::mat4 MVP();
};

}};

#endif //TRACK_RECOGNIZER_ENTITY_H
