//
// Created by yakud on 2019-02-09.
//
#ifndef TRACK_RECOGNIZER_BASIC_SHADER_H
#define TRACK_RECOGNIZER_BASIC_SHADER_H

#include <error.h>
#include "shader.h"

namespace engine { namespace shader{

engine::Error *InitBasicShader(Shader *shader) {
    Error *err;

    if (err = shader->AddShader(GL_VERTEX_SHADER, "res/shader/basic.vert"); err != nullptr) {
        return err;
    }

    if (err = shader->AddShader(GL_FRAGMENT_SHADER, "res/shader/basic.frag"); err != nullptr) {
        return err;
    }

    if (err = shader->Link(); err != nullptr) {
        return err;
    }

    return nullptr;
};

}}

#endif //TRACK_RECOGNIZER_BASIC_SHADER_H