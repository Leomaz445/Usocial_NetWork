//
// Created by PC on 03/08/2023.
//

#ifndef UNTITLED3_NULLMEDIAEXCEPTION_H
#define UNTITLED3_NULLMEDIAEXCEPTION_H

#include <exception>

class NullMediaException : public std::exception {
public:
    const char * what() const noexcept override {
        return "_media not found";
    }
};
#endif //UNTITLED3_NULLMEDIAEXCEPTION_H
