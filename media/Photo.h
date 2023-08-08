//
// Photo Media Class
//


#ifndef UNTITLED3_PHOTO_H
#define UNTITLED3_PHOTO_H


#include "Media.h"
#include <iostream>
/**
 * @brief Derived class representing Photo media.
 */
class Photo : public Media {
private:
    /**
    * @brief Constant indicating media type.
     */
    constexpr static const char *const PHOTO = "PHOTO";
public:
    /**
    * @brief Override display function to show photo content.
    */
    void display() override;
};


#endif //UNTITLED3_PHOTO_H
