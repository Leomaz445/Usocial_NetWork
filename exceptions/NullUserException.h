//
// Created by PC on 03/08/2023.
//

#ifndef UNTITLED3_NULLUSEREXCEPTION_H
#define UNTITLED3_NULLUSEREXCEPTION_H

#include <exception>

class NullUserException : public std::exception {
public:
    const char * what() const noexcept override {
        return "Null user pointer passed to function";
    }
};
#endif //UNTITLED3_NULLUSEREXCEPTION_H
