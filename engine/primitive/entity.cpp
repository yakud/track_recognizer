//
// Created by yakud on 2019-02-13.
//

#include "entity.h"

using namespace engine::primitive;

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
