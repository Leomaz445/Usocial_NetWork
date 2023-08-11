//
// Created by PC on 03/08/2023.
//

#ifndef UNTITLED3_USERNOTFOUNDEXCEPTION_H
#define UNTITLED3_USERNOTFOUNDEXCEPTION_H

#include <stdexcept>

class UserNotFoundException : public std::exception {
public:
    const char *what() const noexcept override {
        return "User Not Found Exception.";
    }
};

#endif //UNTITLED3_USERNOTFOUNDEXCEPTION_H
