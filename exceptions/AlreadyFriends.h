//
// Created by PC on 03/08/2023.
//

#ifndef UNTITLED3_ALREADYFRIENDS_H
#define UNTITLED3_ALREADYFRIENDS_H

#include <exception>

class AlreadyFriends : public std::exception {
public:
    const char *what() const noexcept override {
        return "You are already friends";
    }
};

#endif //UNTITLED3_ALREADYFRIENDS_H
