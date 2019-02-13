//
// Created by yakud on 2019-02-08.
//

#ifndef TRACK_RECOGNIZER_ERROR_H
#define TRACK_RECOGNIZER_ERROR_H

#include <string>

namespace engine {

class Error {
public:
    int Code;
    std::string Message;

    Error(int code, std::string message);

    bool HasError();
};

};

#endif //TRACK_RECOGNIZER_ERROR_H
