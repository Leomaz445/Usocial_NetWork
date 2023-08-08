//
// Created by PC on 08/08/2023.
//

#ifndef UNTITLED3_USOCIALNULLEXCEPTION_H
#define UNTITLED3_USOCIALNULLEXCEPTION_H
#include <stdexcept>

class USocialNullException: public std::exception {
public:
    const char * what() const noexcept override {
        return "USocial object not initialized.";
    }
};

#endif //UNTITLED3_USOCIALNULLEXCEPTION_H
