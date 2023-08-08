cmake_minimum_required(VERSION 3.26)
project(untitled3)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled3 main.cpp
        social/USocial.cpp
        social/USocial.h
        users/User.cpp
        users/User.h
        content/Post.cpp
        content/Post.h
        media/Media.h
        media/Photo.cpp
        media/Photo.h
        media/Audio.cpp
        media/Audio.h
        media/Video.cpp
        media/Video.h
        content/Message.cpp
        content/Message.h
        users/BusinessUser.cpp
        users/BusinessUser.h
        exceptions/UserNotFoundException.h
        exceptions/NullUserException.h
        exceptions/InvalidLengthException.h
        exceptions/NullMediaException.h
        exceptions/AlreadyFriends.h
        exceptions/NotInYourFriendList.h
        exceptions/CantAddYourSelf.h
        exceptions/InvalidFriendNameException.h
        exceptions/NullPostException.h
        exceptions/USocialNullException.h
        exceptions/DifferentSocialNetWork.h
        exceptions/DifferentSocialNetWork.h
        exceptions/CrossNetworkMsgError.h
)
