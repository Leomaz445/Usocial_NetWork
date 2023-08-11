//
// Created by PC on 03/08/2023.
//

#ifndef UNTITLED3_NULLUSEREXCEPTION_H
#define UNTITLED3_NULLUSERECEPTION_H

#include <exception>

class InvalidLengthException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Post must be between 1 and 255 characters long.";
    }
};

#endif //UNTITLED3_NULLUSEREXCEPTION_H
