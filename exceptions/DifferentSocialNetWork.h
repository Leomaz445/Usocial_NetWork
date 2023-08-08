//
// Created by PC on 08/08/2023.
//

#ifndef UNTITLED3_DIFFERENTSOCIALNETWORK_H
#define UNTITLED3_DIFFERENTSOCIALNETWORK_H
#include <exception>

class DifferentSocialNetWork : public std::exception {
public:
    const char *what() const noexcept override {
        return "Cannot add users from different social networks!";
    }
};
#endif //UNTITLED3_DIFFERENTSOCIALNETWORK_H
