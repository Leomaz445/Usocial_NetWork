//
// Created by PC on 04/08/2023.
//

#ifndef UNTITLED3_NOTINYOURFRIENDLIST_H
#define UNTITLED3_NOTINYOURFRIENDLIST_H

#include <exception>

class NotInYourFriendList : public std::exception {
public:
    const char *what() const noexcept override {
        return "This user is not in your friend list.";
    }
};

#endif //UNTITLED3_NOTINYOURFRIENDLIST_H
