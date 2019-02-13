//
// Created by yakud on 2019-02-08.
//

#include <fstream>
#include <sstream>
#include "loader.h"

std::tuple<const GLchar *, engine::Error *> engine::shader::Loader::Load(const GLchar* shaderPath) {
    std::string shaderCode;
    std::ifstream shaderFile;

    shaderFile.exceptions(std::ifstream::failbit);

    try {
        shaderFile.open(shaderPath);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        shaderCode = shaderStream.str();
    } catch(std::ifstream::failure e) {
        std::string message = "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " + std::string(e.what());
        return {nullptr, new engine::Error(1, message)};
    }

    return {shaderCode.c_str(), nullptr};
}

