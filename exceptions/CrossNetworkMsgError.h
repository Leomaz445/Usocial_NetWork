//
// Created by PC on 09/08/2023.
//

#ifndef UNTITLED3_CROSSNETWORKMSGERROR_H
#define UNTITLED3_CROSSNETWORKMSGERROR_H

#include <exception>

class CrossNetworkMsgError : public std::exception {
public:
    const char *what() const noexcept override {
        return "Users must belong to the same USocial network to communicate.";
    }
};

#endif //UNTITLED3_CROSSNETWORKMSGERROR_H
