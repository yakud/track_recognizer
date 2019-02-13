//
// Created by yakud on 2019-02-12.
//

#include "model.h"
#include "camera.h"

using namespace engine::primitive;

Model::Model(engine::primitive::Mesh *mesh, engine::shader::Shader *shader) {
    this->entity = new Entity();
    this->mesh = mesh;
    this->shader = shader;

    glGenBuffers(3, &this->VBO[0]);
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->IBO);

    this->MVPID = static_cast<GLuint>(glGetUniformLocation(shader->Program(), "MVP"));
    this->BindGL();
}

void Model::BindGL() {
    // 1. Привязываем VAO
    glBindVertexArray(this->VAO);

    // 2. Копируем наш массив вершин в буфер для OpenGL
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, this->mesh->positions.size() * sizeof(glm::vec3), &this->mesh->positions[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, glm::vec3::length(), GL_FLOAT, GL_FALSE, glm::vec3::length() * sizeof(glm::vec3::value_type), 0);
    glEnableVertexAttribArray(0);

    // 2. Копируем наш массив цветов в буфер для OpenGL
    if (!this->mesh->colors.empty()) {
        glBindBuffer(GL_ARRAY_BUFFER, this->VBO[1]);
        glBufferData(GL_ARRAY_BUFFER, this->mesh->colors.size() * sizeof(glm::vec4), &this->mesh->colors[0], GL_STATIC_DRAW);
        glVertexAttribPointer(1, glm::vec4::length(), GL_FLOAT, GL_FALSE, glm::vec4::length() * sizeof(glm::vec4::value_type), 0);
        glEnableVertexAttribArray(1);
    }

    // 3. Копируем наш массив нормалей в буфер для OpenGL
    if (!this->mesh->normals.empty()) {
        glBindBuffer(GL_ARRAY_BUFFER, this->VBO[2]);
        glBufferData(GL_ARRAY_BUFFER, this->mesh->normals.size() * sizeof(glm::vec3), &this->mesh->normals[0], GL_STATIC_DRAW);
        glVertexAttribPointer(2, glm::vec3::length(), GL_FLOAT, GL_FALSE, glm::vec3::length() * sizeof(glm::vec3::value_type), 0);
        glEnableVertexAttribArray(2);
    }

    // 3. Копируем наши индексы в в буфер для OpenGL
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->mesh->indices.size() * sizeof(glm::uvec3), &this->mesh->indices[0], GL_STATIC_DRAW);

    //4. Отвязываем VAO
    glBindVertexArray(0);
}

void Model::Draw() {
    this->shader->Use();

    glBindVertexArray(this->VAO);

    // Bind mvp
    glUniformMatrix4fv(this->MVPID, 1, GL_FALSE, &(this->entity->MVP())[0][0]);

    // @TODO: render line mode
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glDrawElements(
            GL_TRIANGLES,
            static_cast<GLsizei>(this->mesh->indices.size() * glm::uvec3::length()),
            GL_UNSIGNED_INT,
            nullptr
    );
    glBindVertexArray(0);
}

glm::mat4 Model::UpdateMVP(Camera *camera) {
    return this->entity->UpdateMVP(camera->Projection(), camera->View());
}

Entity *Model::GetEntity() {
    return this->entity;
}
