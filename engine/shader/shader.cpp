//
// Created by yakud on 2019-02-08.
//

#include "shader.h"

using namespace engine::shader;

Shader::Shader(Loader *loader, Compiler *compiler) {
    this->loader = loader;
    this->compiler = compiler;
    this->program = glCreateProgram();
}

std::optional<engine::Error> Shader::AddShader(GLenum shaderType, const GLchar *shaderPath) {
    auto [shaderCode, errLoad] = this->loader->Load(shaderPath);
    if (errLoad) {
        return errLoad;
    }

    auto [shader, errCompile] = this->compiler->Compile(shaderType, shaderCode);
    if (errCompile) {
        return errCompile;
    }

    glAttachShader(this->program, shader);

    return std::nullopt;
}

std::optional<engine::Error> Shader::Link() {
    GLint success;

    glLinkProgram(this->program);

    glGetProgramiv(this->program, GL_LINK_STATUS, &success);
    if(success != GL_TRUE) {
        GLchar infoLog[512];
        glGetProgramInfoLog(this->program, 512, nullptr, infoLog);
        std::string message = "ERROR::SHADER::PROGRAM::LINKING_FAILED: " + std::string(infoLog);

        return Error(1, message);
    }

    return std::nullopt;
}

void Shader::Use() {
    glUseProgram(this->program);
}

GLuint Shader::Program() {
    return this->program;
}

