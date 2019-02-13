//
// Created by yakud on 2019-02-08.
//

#ifndef TRACK_RECOGNIZER_SHADER_COMPILER_H
#define TRACK_RECOGNIZER_SHADER_COMPILER_H

#include <GL/glew.h>
#include "../error.h"

namespace engine { namespace shader {

class Compiler {
public:
    std::tuple<GLuint, engine::Error *> Compile(GLenum shaderType, const GLchar *shaderSource);
};

}}
#endif //TRACK_RECOGNIZER_SHADER_COMPILER_H
