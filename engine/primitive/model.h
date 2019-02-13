//
// Created by yakud on 2019-02-12.
//

#ifndef TRACK_RECOGNIZER_MODEL_H
#define TRACK_RECOGNIZER_MODEL_H

#include "entity.h"
#include "camera.h"

namespace engine{namespace primitive{

class Model {
protected:
    Entity *entity;
    Mesh *mesh;
    engine::shader::Shader *shader;

    // Vertex Buffer Object
    GLuint VBO[3];

    // Vertex Array Object
    GLuint VAO;

    // Index Buffer Object
    GLuint IBO;

    // MVP uniform in shader
    GLuint MVPID;

public:
    Model(Mesh *mesh, engine::shader::Shader *shader);

    glm::mat4 UpdateMVP(Camera *camera);
    void BindGL();
    void Draw();

    Entity* GetEntity();
};

}};


#endif //TRACK_RECOGNIZER_MODEL_H
