//
// Created by yakud on 2019-02-08.
//

#ifndef TRACK_RECOGNIZER_SHADER_LOADER_H
#define TRACK_RECOGNIZER_SHADER_LOADER_H

#include <GL/glew.h>
#include "../error.h"

namespace engine { namespace shader {

class Loader {
public:
    std::tuple<const GLchar *, engine::Error *> Load(const GLchar *shaderPath);
};

}}
#endif //TRACK_RECOGNIZER_SHADER_LOADER_H
