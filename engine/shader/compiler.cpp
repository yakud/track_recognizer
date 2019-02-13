//
// Created by yakud on 2019-02-08.
//

#include "compiler.h"

std::tuple<GLuint, engine::Error *> engine::shader::Compiler::Compile(GLenum shaderType, const GLchar *shaderSource) {
    GLuint shader;
    GLint success;
    GLchar infoLog[512];

    shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(success != GL_TRUE) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::string message = "ERROR::SHADER::COMPILATION_FAILED " + std::string(infoLog);
        Error err = engine::Error(1, message);
        return {0, &err};
    };

    return {shader, nullptr};
}
