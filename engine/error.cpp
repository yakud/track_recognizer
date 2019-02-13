#include <utility>

//
// Created by yakud on 2019-02-08.
//

#include "error.h"

bool engine::Error::HasError() {
    return this->Code != 0;
}

engine::Error::Error(int code, std::string message) {
    this->Code = code;
    this->Message = std::move(message);
}
