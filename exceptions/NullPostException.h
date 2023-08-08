//
// Created by PC on 08/08/2023.
//

#ifndef UNTITLED3_NULLPOSTEXCEPTION_H
#define UNTITLED3_NULLPOSTEXCEPTION_H
#include <exception>

class NullPostException : public std::exception {
public:
    const char * what() const noexcept override {
        return "Post object is null.";
    }
};
#endif //UNTITLED3_NULLPOSTEXCEPTION_H
