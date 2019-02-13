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


Entity::Entity() {
    this->ResetMatrix();
}

glm::mat4 Entity::MVP() {
    return this->_mvp;
}

glm::mat4 Entity::UpdateMVP(glm::mat4 projection, glm::mat4 view) {
    UpdateMatrix();
    this->_mvp = glm::mat4(projection * view * this->_model);
    return this->_mvp;
}

void Entity::ResetMatrix() {
    this->translate = glm::mat4(1.0f);
    this->scale = glm::mat4(1.0f);
    this->rotate = glm::mat4(1.0f);
    this->_model = glm::mat4(1.0f);
}

void Entity::UpdateMatrix() {
    this->_model = this->translate * this->rotate * this->scale;
}

glm::vec3 Entity::GetTranslation() {
    return glm::vec3(this->translate[3]);
}



//std:: Entity::DecomposeMatrix() {
//    glm::vec3 scale;
//    glm::quat rotation;
//    glm::vec3 translation;
//    glm::vec3 skew;
//    glm::vec4 perspective;
//    glm::decompose(this->matrix, scale, rotation, translation, skew, perspective);
//
//    rotation=glm::conjugate(rotation);
//}


}};


#endif //TRACK_RECOGNIZER_ENTITY_H
