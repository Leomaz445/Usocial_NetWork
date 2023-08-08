//
// Created by PC on 08/08/2023.
//

#ifndef UNTITLED3_CANTADDYOURSELF_H
#define UNTITLED3_CANTADDYOURSELF_H
#include <exception>

class CantAddYourSelf : public std::exception {
public:
    const char * what() const noexcept override {
        return "You can't add yourself as a friend";
    }
};
#endif //UNTITLED3_CANTADDYOURSELF_H
