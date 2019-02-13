//
// Created by yakud on 2019-02-08.
//
#ifndef TRACK_RECOGNIZER_SHADER_H
#define TRACK_RECOGNIZER_SHADER_H

#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <primitive/mesh.h>
#include <primitive/entity.h>

#include "compiler.h"
#include "loader.h"

namespace engine { namespace shader {

class Shader {
protected:
    Loader *loader;
    Compiler *compiler;

    GLuint program;

public:
    Shader(Loader *loader, Compiler *compiler);

    std::optional<engine::Error> AddShader(GLenum shaderType, const GLchar *shaderPath);

    std::optional<engine::Error> Link();

    void Use();

    GLuint Program();
};

}}


#endif //TRACK_RECOGNIZER_SHADER_H
