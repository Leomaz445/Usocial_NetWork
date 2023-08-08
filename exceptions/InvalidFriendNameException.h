//
// Created by PC on 08/08/2023.
//

#ifndef UNTITLED3_INVALIDFRIENDNAMEEXCEPTION_H
#define UNTITLED3_INVALIDFRIENDNAMEEXCEPTION_H

#include <exception>

class InvalidFriendNameException : public std::exception {
public:
    const char * what() const noexcept override {
        return "Friend name is empty.";
    }
};
#endif //UNTITLED3_INVALIDFRIENDNAMEEXCEPTION_H
