//
// Created by yakud on 2019-02-08.
//

#include "shader.h"

engine::shader::Shader::Shader(Loader *loader, Compiler *compiler) {
    this->loader = loader;
    this->compiler = compiler;
    this->program = glCreateProgram();
}

engine::Error *engine::shader::Shader::AddShader(GLenum shaderType, const GLchar *shaderPath) {
    auto [shaderCode, errLoad] = this->loader->Load(shaderPath);
    if (errLoad != nullptr) {
        return errLoad;
    }

    auto [shader, errCompile] = this->compiler->Compile(shaderType, shaderCode);
    if (errCompile != nullptr) {
        return errCompile;
    }

    glAttachShader(this->program, shader);

    return nullptr;
}

engine::Error * engine::shader::Shader::Link() {
    GLint success;

    glLinkProgram(this->program);

    glGetProgramiv(this->program, GL_LINK_STATUS, &success);
    if(success != GL_TRUE) {
        GLchar infoLog[512];
        glGetProgramInfoLog(this->program, 512, nullptr, infoLog);
        std::string message = "ERROR::SHADER::PROGRAM::LINKING_FAILED: " + std::string(infoLog);

        return new Error(1, message);
    }

    return nullptr;
}

void engine::shader::Shader::Use() {
    glUseProgram(this->program);
}

GLuint engine::shader::Shader::Program() {
    return this->program;
}

