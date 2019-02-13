//
// Created by yakud on 2019-02-08.
//

#include "compiler.h"

using namespace engine::shader;

std::tuple<GLuint, std::optional<engine::Error>> Compiler::Compile(GLenum shaderType, const GLchar *shaderSource) {
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
        return {0, engine::Error(1, message)};
    };

    return {shader, std::nullopt};
}
