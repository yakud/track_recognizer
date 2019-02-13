//
// Created by yakud on 2019-02-12.
//

#ifndef TRACK_RECOGNIZER_CAMERA_H
#define TRACK_RECOGNIZER_CAMERA_H

#include "entity.h"

namespace engine{namespace primitive{

const float DEFAULT_FIELD_OF_VIEW = 45.0f;
const float DEFAULT_ASPECT_RATIO = 4.0f / 3.0f;
const float DEFAULT_MIN_DIST = 0.1f;
const float DEFAULT_MAX_DIST = 100.0f;

class Camera {
protected:
    Entity *entity{};
    glm::mat4 projection{};
    glm::mat4 view{};
    glm::vec3 head = glm::vec3(0,1,0); // Head is up (set to 0,-1,0 to look upside-down)

public:

    float fov = DEFAULT_FIELD_OF_VIEW;
    float aspectRatio = DEFAULT_ASPECT_RATIO;
    float minDist = DEFAULT_MIN_DIST;
    float maxDist = DEFAULT_MAX_DIST;

    Camera();

    void InitPerspectiveProjection();
    void LookAt(glm::vec3 coord);

    Entity* GetEntity();

    glm::mat4 Projection();
    glm::mat4 View();
};

}};

#endif //TRACK_RECOGNIZER_CAMERA_H
