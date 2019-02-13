//
// Created by yakud on 2019-02-12.
//

#include "camera.h"

using namespace engine::primitive;

Camera::Camera()  {
    this->entity = new Entity();
    this->InitPerspectiveProjection();
    this->LookAt(glm::vec3(0,0,0));
}

void Camera::InitPerspectiveProjection() {
    this->projection = glm::perspective(glm::radians(this->fov), this->aspectRatio, this->minDist, this->maxDist);
}

void Camera::LookAt(glm::vec3 coord) {
    this->view = glm::lookAt(
            this->entity->GetTranslation(), // Camera translation
            coord,                  // and looks at the origin
            this->head              // Head is up (set to 0,-1,0 to look upside-down)
    );
}

glm::mat4 Camera::Projection() {
    return this->projection;
}

glm::mat4 Camera::View() {
    return this->view;
}

Entity* Camera::GetEntity() {
    return this->entity;
}